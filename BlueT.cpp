// 
// 
// 

#include "BlueT.h"

BlueTClass::BlueTClass()
{
	Serial.begin(9600);
}

char BlueTClass::cmd()
{
	if (!Serial.available())
	{
		return NULL;
	}
	else
	{
		delay(2);
		uint8_t count = 0;

		while (Serial.available())
		{
			char readBuf = Serial.read();

			if (count == 0)
			{
				cmdTmp = readBuf;
				count = 1;
			}
			else if (count == 1 && readBuf == 'r')
			{
				count++;
			}
			else if (count == 2 && readBuf == 'n')
			{
				while (Serial.available() > 0)
					Serial.read();
				return cmdTmp;
			}
			else
			{
				cmdTmp = readBuf;
				count = 1;
			}
		}
	}
}

void BlueTClass::sendCmd(char cmd)
{
	char sendWithCR[4] = { cmd, 'r', 'n' };
	Serial.write(sendWithCR);
	delay(1);
}



