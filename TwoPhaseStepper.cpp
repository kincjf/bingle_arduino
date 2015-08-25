// 
// 
// 

#include "TwoPhaseStepper.h"


TwoPhaseStepperClass TwoPhaseStepper;

TwoPhaseStepperClass::TwoPhaseStepperClass()
{
}

TwoPhaseStepperClass::TwoPhaseStepperClass(int pinA, int pinB, int pinC, int pinD)
{
	A = pinA;
	B = pinB;
	C = pinC;
	D = pinD;

	pinMode(A, OUTPUT);
	pinMode(B, OUTPUT);
	pinMode(C, OUTPUT);
	pinMode(D, OUTPUT);
}


void TwoPhaseStepperClass::moveStep(int step)
{
	while (step) {
		digitalWrite(A, LOW);
		digitalWrite(B, LOW);
		digitalWrite(C, HIGH);
		digitalWrite(D, HIGH);
		delay(10);
		step--;
		if (step == 0)
			break;
		digitalWrite(A, HIGH);
		digitalWrite(B, LOW);
		digitalWrite(C, LOW);
		digitalWrite(D, HIGH);

		delay(10);
		step--;
		if (step == 0)
			break;
		digitalWrite(A, HIGH);
		digitalWrite(B, HIGH);
		digitalWrite(C, LOW);
		digitalWrite(D, LOW);

		delay(10);
		step--;
		if (step == 0)
			break;
		digitalWrite(A, LOW);
		digitalWrite(B, HIGH);
		digitalWrite(C, HIGH);
		digitalWrite(D, LOW);

		delay(10);
		step--;
	}
}
