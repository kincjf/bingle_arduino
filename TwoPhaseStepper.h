// TwoPhaseStepper.h

#ifndef _TWOPHASESTEPPER_h
#define _TWOPHASESTEPPER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class TwoPhaseStepperClass
{
protected:
	int A, B, C, D;


public:
	TwoPhaseStepperClass();
	TwoPhaseStepperClass(int A, int B, int C, int D);
	void moveStep(int step);
};

extern TwoPhaseStepperClass TwoPhaseStepper;

#endif

