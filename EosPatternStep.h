/*************************************
//
// Settings for each step of a Light Pattern program
//
// An array of these should be supplied to the Arduino progam to carry out
//
//
//
// Contact information
// -------------------
//
// Daniel Temkin
// Web      :  http://danieltemkin.com
// e-mail   :  lightpattern@danieltemkin.com
//
**************************************/


#ifndef EosPatternStep_h
#define EosPatternStep_h

class EosPatternStep
{
	public:
		int shutterCode; // shutter speed code send to camera
		float shutterSeconds; // human-readable

		int apertureCode; // camera code
		float apertureSize; // human-readable

		int colorChange; // number of colors to move forward or back on wheel
		char currentColor; // human-readable

		EosPatternStep();
		EosPatternStep(int shutter, float shutterSec, int app, float appSize, int colorCh, char color);
};


#endif
