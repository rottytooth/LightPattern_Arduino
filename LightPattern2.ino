// includes for camera
#include <inttypes.h>
#include <avr/pgmspace.h>
#include <avrpins.h>
#include <max3421e.h>
#include <usbhost.h>
#include <usb_ch9.h>
#include <Usb.h>
#include <usbhub.h>
#include <address.h>
#include <message.h>

#include <ptp.h>
#include <canoneos.h>

// Include the Stepper Library
#include <Stepper.h>

// local files, including auto-generated code
#include "EosPatternStep.h"
#include "EosProgram.h"


// Map our pins to constants to make things easier to keep track of
const int pwmA = 44; // not using pwm for this hope it's okay
const int pwmB = 46;
const int brakeA = 26; // these are all going way up in that section of the mega not used by the camera card
const int brakeB = 28;
const int dirA = 24;
const int dirB = 22;


const int STEPS = 400; // # of steps for a full revolution of the motor
const int ONE_COLOR = 1000; // distance between filters


int ProgramLine = 0; // the line of the program we're writing
int LineStep = 0; // the step within that line (0 = motor, 1 = aperture, 2 = shutter, 3 = fire camera)
int AtEndOfProgram = 0;


// Initialize the Stepper class
Stepper myStepper(STEPS, dirA, dirB);

EosPatternStep* program;


// class for the EOS work
class CamStateHandlers : public PTPStateHandlers
{
      bool stateConnected;

public:
      CamStateHandlers() : stateConnected(false) {};
      
      virtual void OnDeviceDisconnectedState(PTP *ptp);
      virtual void OnDeviceInitializedState(PTP *ptp);
} CamStates;

USB         Usb;
USBHub      Hub1(&Usb);
CanonEOS    Eos(&Usb, &CamStates);

void CamStateHandlers::OnDeviceDisconnectedState(PTP *ptp)
{
    Serial.println("in disconnected state");
    if (stateConnected)
    {
        stateConnected = false;
        Notify(PSTR("Camera disconnected\r\n"),1);
    }
}

void CamStateHandlers::OnDeviceInitializedState(PTP *ptp)
{
    static uint32_t next_time = 0;
    
    if (!stateConnected)
        stateConnected = true;
    
    if (AtEndOfProgram == 1)
      return;
    
    if (ProgramLine >= EosProgram::GetProgramLength())
    {
      AtEndOfProgram = 1;
      Serial.println("passed end of program");
      return;
    }
    uint32_t  time_now = millis();

    if (time_now < next_time)
    {
      return;
    }
    
    next_time = time_now + 2000;
    Serial.println("in initialized state");

          
    uint16_t rc;

    if (LineStep % 4 == 0) // Step Zero: turn the motor
    {
          // turn wheel
          myStepper.step(-ONE_COLOR * program[ProgramLine].colorChange);
          
          // diagnostics
          Serial.print("motor: ");
          Serial.println(-ONE_COLOR * program[ProgramLine].colorChange);
    }
    else if (LineStep % 4 == 1) // Step One: set the aperture
    {
          
          // set aperture and shutter speed
          rc = ((CanonEOS*)ptp)->SetProperty(EOS_DPC_Aperture, program[ProgramLine].apertureCode);

          Serial.println();

          // diagnostics
          Serial.print("aperture CODE: ");
          Serial.println(program[ProgramLine].apertureCode);
          Serial.print("aperture: ");
          Serial.println(program[ProgramLine].apertureSize);

          if (rc != PTP_RC_OK)  
          {
              Serial.print("Error setting aperture: 0x");
              Serial.println(rc, HEX);
          }            
    }
    else if (LineStep % 4 == 2) // Step Two: set the shutter speed
    {

          rc = ((CanonEOS*)ptp)->SetProperty(EOS_DPC_ShutterSpeed, program[ProgramLine].shutterCode);

          // diagnostics
          Serial.print("shutter CODE: ");
          Serial.println(program[ProgramLine].shutterCode);
          Serial.print("shutter: ");
          Serial.println(program[ProgramLine].shutterSeconds);

          if (rc != PTP_RC_OK)  
          {
              Serial.print("Error setting shutter: 0x");
              Serial.println(rc, HEX);
          }            
    }
    else if (LineStep % 4 == 3) // Step Three: take a photo!
    {
          
          rc = ((CanonEOS*)ptp)->Capture();
          
          if (rc != PTP_RC_OK)  
          {
              // it's possible we ended up here because the previous shot has not finished
              Serial.print("Error shooting camera: 0x");
              Serial.println(rc, HEX);
          }            
          
          // delay for the shutter
          delay(program[ProgramLine].shutterSeconds * 1000);
          
          ProgramLine++;
    }          
    LineStep++;
    
//    delete[] program;

}

void setup() {

  if (Usb.Init() == -1)
      Serial.println("OSC did not start.");
      
    // Set the RPM of the motor
  myStepper.setSpeed(30);

  // Turn on pulse width modulation
  pinMode(pwmA, OUTPUT);
  digitalWrite(pwmA, HIGH);
  pinMode(pwmB, OUTPUT);
  digitalWrite(pwmB, HIGH);

  // Turn off the brakes
  pinMode(brakeA, OUTPUT);
  digitalWrite(brakeA, LOW);
  pinMode(brakeB, OUTPUT);
  digitalWrite(brakeB, LOW);

  // Log
  Serial.begin(9600);
  
  program = EosProgram::GetPattern();
}


void loop() { 
    Usb.Task();
    delay(200);
}


