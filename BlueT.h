// BlueT.h

#ifndef _BLUET_h
#define _BLUET_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class BlueTClass
{
 protected:
	 char cmdTmp;

 public:
	BlueTClass();
	char cmd();
	void sendCmd(char cmd);

};

extern BlueTClass BlueT;

#endif

