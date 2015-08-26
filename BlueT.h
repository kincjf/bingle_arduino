/// @file BlueT.h
/// @data 2015-08-26
/// @author Hong

#ifndef _BLUET_h
#define _BLUET_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


/// @brief Bluetooth 통신을 위한 Class
// ------------------------------------
class BlueTClass
{
 protected:
	 char cmdTmp; /// 명령의 임시저장.

 public:
	BlueTClass(); /// 블루투스 생성자
	char cmd(); /// 블루투스로부터 캐리지 리턴을 포함한 명령을 받아온다.
	void sendCmd(char cmd); /// 캐리지 리턴을 포함한 명령을 보낸다.

};

extern BlueTClass BlueT;

#endif

