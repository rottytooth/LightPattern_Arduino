/*************************************
//
// This is not the code we're looking for, move along, move along
//
**************************************/

#include "EosPatternStep.h"


EosPatternStep::EosPatternStep()
{
}

EosPatternStep::EosPatternStep(int shutter, float shutterSec, int app, float appSize, int colorCh, char color)
{
	shutterCode = shutter; // shutter speed code send to camera
	shutterSeconds = shutterSec; // human-readable

	apertureCode = app; // camera code
	apertureSize = appSize; // human-readable

	colorChange = colorCh; // number of colors to move forward or back on wheel
	currentColor = color; // human-readable
}

