// CBlue.h

#ifndef _CBLUE_h
#define _CBLUE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class CBlueClass
{
 protected:


 public:
	void init();
};

extern CBlueClass CBlue;

#endif

