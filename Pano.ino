#include "TwoPhaseStepper.h"
#include "BlueT.h"
#include <Servo.h>

#define Pin1 6
#define Pin2 7
#define Pin3 8
#define Pin4 9

BlueTClass BT;
Servo verServo;
TwoPhaseStepperClass horStep(Pin1, Pin2, Pin3, Pin4);

char cmd;


#define horArrSize 6
uint8_t horArr[6] = { 128,48,85,85,43,128 };
uint8_t verArr[6][6] = { { 1,90 },
							{ 2,60,120 },
							{ 3,150,90,30 },
							{ 2,60,120 },
							{ 1,90 },
							{ 5,30,60,90,120,150 } };
void setup()
{
	verServo.attach(12);
	Serial.begin(9600);
}

void loop()
{
	cmd = BT.cmd();
	delay(100);

	if (cmd == 'S')
	{
		for (int i = 0; i < 4; i++) {
			for (int h = 0; h < horArrSize; h++) {
				if (i == 0 && h == 0) {
					for (int v = 0; v <= 180; v += 30) {
						Serial.print("verArr ");
						Serial.println(v);
						cmd = ' ';
						while (!(cmd == 'C')) {
							cmd = BT.cmd();
							Serial.println(cmd);
							delay(50);
						}
						verServo.write(v);
						delay(800);
					}
				}
				else
				{
					Serial.print("horArr ");
					Serial.println(horArr[h]);
					horStep.moveStep(horArr[h]);
					for (int v = 1; v <= verArr[i][0]; v++) {
						cmd = NULL;
						while (!(cmd == 'C')) {
							cmd = BT.cmd();
							Serial.println(cmd);
							delay(50);
						}
						Serial.print("verArr ");
						Serial.println(verArr[i][v]);
						verServo.write(verArr[i][v]);
						delay(1000);
					}
				}

			}
		}
	}
	else
		cmd = NULL;

}





