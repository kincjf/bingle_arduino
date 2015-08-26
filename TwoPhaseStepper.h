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

/// @brief ���� �������� ����ϴ� ������ ������ ����
class TwoPhaseStepperClass
{
protected:
	int A, B, C, D; /// pin A, B, C, D ����


public:
	TwoPhaseStepperClass();
	TwoPhaseStepperClass(int A, int B, int C, int D); /// ������ pin ����
	void moveStep(int step); /// step��ŭ ������.
};

extern TwoPhaseStepperClass TwoPhaseStepper;

#endif

