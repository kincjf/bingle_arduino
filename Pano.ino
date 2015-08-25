#include "TwoPhaseStepper.h"
#include "BlueT.h"
#include <Servo.h>

BlueTClass BT;
Servo verServo;

char cmd;

#define N1 6
#define N2 7
#define N3 8
#define N4 9

#define horArrSize 6
uint8_t horArr[6] = { 128,48,85,85,43,128 };
uint8_t verArr[6][6] = {{1,90},
						{2,60,120},
						{3,150,90,30},
						{2,60,120},
						{1,90},
						{5,30,60,90,120,150}};
void setup()
{
	pinMode(N1, OUTPUT);
	pinMode(N2, OUTPUT);
	pinMode(N3, OUTPUT);
	pinMode(N4, OUTPUT);
	verServo.attach(12);
	Serial.begin(9600);
  /* add setup code here */

}

void loop()
{
	cmd = BT.cmd();
	delay(500);
	Serial.print("cmd ");
	Serial.println(cmd);
	if (Serial.available()) {
		Serial.println("available");
	}
	if (cmd != NULL) {
		Serial.print("in");
		for (int i = 0; i < 4; i++) {
			for (int h = 0; h < horArrSize; h++) {
				if (h != 0 || i!=0) {
					Serial.print("horArr ");
					Serial.println(horArr[h]);
					myStepper(horArr[h]);
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
				else {
					for (int v = 0; v <= 180; v+=30) {
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
				
			}
		}

	}

}


void myStepper(int si)
{
	while (si) {
		digitalWrite(N1, LOW);
		digitalWrite(N2, LOW);
		digitalWrite(N3, HIGH);
		digitalWrite(N4, HIGH);
		delay(10);
		si--;
		if (si == 0)
			break;
		digitalWrite(N1, HIGH);
		digitalWrite(N2, LOW);
		digitalWrite(N3, LOW);
		digitalWrite(N4, HIGH);

		delay(10);
		si--;
		if (si == 0)
			break;
		digitalWrite(N1, HIGH);
		digitalWrite(N2, HIGH);
		digitalWrite(N3, LOW);
		digitalWrite(N4, LOW);

		delay(10);
		si--;
		if (si == 0)
			break;
		digitalWrite(N1, LOW);
		digitalWrite(N2, HIGH);
		digitalWrite(N3, HIGH);
		digitalWrite(N4, LOW);

		delay(10);
		si--;
	}
}




