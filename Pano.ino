/// @file Pano.ino
/// @data 2015-08-26
/// @author Hong


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

#define horArrSize 24
//uint8_t horArr[6] = {128, 128,48,85,85,43};
//uint8_t verArr[6][6] = {	{ 5,30,60,90,120,150 } ,
//							{ 1,90 },
//							{ 2,60,120 },
//							{ 5,150,120,90,60,30 },
//							{ 2,60,120 },
//							{ 1,90 } };

//uint8_t horArr[6] = { 86,86,86,86,86,86 };
//uint8_t verArr[6][6] = { { 1,90 },
//{ 5,43,58,90,124,140 },
//{ 3,140,90,40 },
//{ 5,43,58,90,115,140 },
//{ 1,90 },
//{ 5,43,58,90,124,140 } };

uint8_t horArr[24] = { 86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86 };
uint8_t verArr[24][7] = {
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 }, 
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 }, 
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 }};


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
		//Serial.println("in");
		int lastVerAngle = 90;

		//for (int i = 0; i < 4; i++) {
			for (int h = 0; h < horArrSize; h++) {
				//if (i != 0 || h != 0)
				if (h != 0) {
					horStep.moveStep(horArr[h]+4);
					//Serial.print("movHor");
					//Serial.println(horArr[h]);
				}
				for (int v = 1; v <= verArr[h][0]; v++) {
					
					verServo.write(verArr[h][v]);

					//Serial.print("ver");
					//Serial.println(verArr[h][v]);
					delay(abs(lastVerAngle-verArr[h][v])*20);//8
					BT.sendCmd('C');
					delay(10);

					while (cmd != 'F') {
						cmd = BT.cmd();
						//Serial.println(cmd);
						delay(5);
					}
					cmd = NULL;

				}

			}
		//}
		//Serial.println("out");
		BT.sendCmd('E');

	}
	else
		cmd = NULL;

}





