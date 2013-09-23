/*************************************
//
// Auto-Generated by Light Pattern compiler (lp.exe)
//
// For more info, visit http://danieltemkin.com/LightPattern
//
// NOTE: This is the Hello, World program
//
**************************************/

#include "EosProgram.h"


EosPatternStep* EosProgram::GetPattern()
{
	EosPatternStep* program = new EosPatternStep[51];
	program[0] = EosPatternStep(55, 1.000, 35, 3.2, 0, 'r');
	program[1] = EosPatternStep(52, 1.300, 32, 2.8, 0, 'r'); // print screen
	program[2] = EosPatternStep(52, 1.300, 27, 2.2, 2, 'b'); // string
	program[3] = EosPatternStep(55, 1.000, 32, 2.8, -2, 'r'); // 2 photo letter
	program[4] = EosPatternStep(58, 0.800, 35, 3.2, 1, 'g');
	program[5] = EosPatternStep(55, 1.000, 36, 3.5, -1, 'r'); // H
	program[6] = EosPatternStep(58, 0.800, 40, 4, 1, 'g');
	program[7] = EosPatternStep(61, 0.600, 40, 4, -1, 'r');
	program[8] = EosPatternStep(58, 0.800, 43, 4.5, 1, 'g'); // e
	program[9] = EosPatternStep(61, 0.600, 44, 5, 1, 'b');
	program[10] = EosPatternStep(63, 0.500, 44, 5, 0, 'b');
	program[11] = EosPatternStep(66, 0.400, 48, 5.6, -1, 'g'); // l
	program[12] = EosPatternStep(68, 0.300, 51, 6.3, 1, 'b');
	program[13] = EosPatternStep(71, 0.250, 51, 6.3, 0, 'b');
	program[14] = EosPatternStep(74, 0.200, 52, 7.1, -1, 'g'); // l
	program[15] = EosPatternStep(76, 0.167, 59, 9, 1, 'b');
	program[16] = EosPatternStep(79, 0.125, 59, 9, 0, 'b');
	program[17] = EosPatternStep(82, 0.100, 59, 9, -1, 'g'); // o
	program[18] = EosPatternStep(84, 0.077, 60, 10, -1, 'r'); // end of string marker
	program[19] = EosPatternStep(82, 0.100, 59, 9, 1, 'g'); // reset and new pic
	program[20] = EosPatternStep(55, 1.000, 35, 3.2, 0, 'r');
	program[21] = EosPatternStep(55, 1.000, 32, 2.8, 2, 'b'); // string
	program[22] = EosPatternStep(58, 0.800, 35, 3.2, -2, 'r');
	program[23] = EosPatternStep(61, 0.600, 36, 3.5, 0, 'r');
	program[24] = EosPatternStep(61, 0.600, 35, 3.2, 1, 'g'); // ,
	program[25] = EosPatternStep(63, 0.500, 36, 3.5, 1, 'b');
	program[26] = EosPatternStep(66, 0.400, 40, 4, 0, 'b');
	program[27] = EosPatternStep(68, 0.300, 40, 4, -2, 'r'); // space
	program[28] = EosPatternStep(71, 0.250, 43, 4.5, 1, 'g');
	program[29] = EosPatternStep(74, 0.200, 43, 4.5, -1, 'r');
	program[30] = EosPatternStep(76, 0.167, 40, 4, 2, 'b'); // W
	program[31] = EosPatternStep(79, 0.125, 43, 4.5, -2, 'r');
	program[32] = EosPatternStep(82, 0.100, 43, 4.5, 0, 'r');
	program[33] = EosPatternStep(84, 0.077, 43, 4.5, 2, 'b'); // o
	program[34] = EosPatternStep(87, 0.067, 44, 5, -1, 'g'); // end of string marker
	program[35] = EosPatternStep(84, 0.077, 43, 4.5, 1, 'b'); // reset and new pic
	program[36] = EosPatternStep(55, 1.000, 35, 3.2, 0, 'r');
	program[37] = EosPatternStep(55, 1.000, 32, 2.8, 2, 'b'); // string
	program[38] = EosPatternStep(58, 0.800, 35, 3.2, -2, 'r');
	program[39] = EosPatternStep(61, 0.600, 35, 3.2, 0, 'r');
	program[40] = EosPatternStep(63, 0.500, 32, 2.8, 2, 'b'); // r
	program[41] = EosPatternStep(66, 0.400, 35, 3.2, -2, 'r');
	program[42] = EosPatternStep(68, 0.300, 35, 3.2, 0, 'r');
	program[43] = EosPatternStep(71, 0.250, 36, 3.5, 2, 'b'); // l
	program[44] = EosPatternStep(74, 0.200, 40, 4, -2, 'r');
	program[45] = EosPatternStep(76, 0.167, 40, 4, 2, 'b');
	program[46] = EosPatternStep(74, 0.200, 43, 4.5, 0, 'b'); // d
	program[47] = EosPatternStep(76, 0.167, 44, 5, -2, 'r');
	program[48] = EosPatternStep(79, 0.125, 48, 5.6, 0, 'r');
	program[49] = EosPatternStep(82, 0.100, 44, 5, 2, 'b'); // !
	program[50] = EosPatternStep(84, 0.077, 48, 5.6, -1, 'g'); // end of string marker

	return program;
}

int EosProgram::GetProgramLength()
{
	return 51;
}
