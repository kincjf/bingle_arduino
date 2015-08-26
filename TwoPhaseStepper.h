/// @file TwoPhaseStepper.h
/// @data 2015-08-26
/// @author Hong

#ifndef _TWOPHASESTEPPER_h
#define _TWOPHASESTEPPER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

/// @brief 가로 움직임을 담당하는 모터의 움직임 제어
class TwoPhaseStepperClass
{
protected:
	int A, B, C, D; /// pin A, B, C, D 저장


public:
	TwoPhaseStepperClass();
	TwoPhaseStepperClass(int A, int B, int C, int D); /// 모터의 pin 설정
	void moveStep(int step); /// step만큼 움직임.
};

extern TwoPhaseStepperClass TwoPhaseStepper;

#endif

