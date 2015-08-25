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


 public:
	void init();
};

extern TwoPhaseStepperClass TwoPhaseStepper;

#endif

