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


/// @brief Bluetooth ����� ���� Class
// ------------------------------------
class BlueTClass
{
 protected:
	 char cmdTmp; /// ����� �ӽ�����.

 public:
	BlueTClass(); /// ������� ������
	char cmd(); /// ��������κ��� ĳ���� ������ ������ ����� �޾ƿ´�.
	void sendCmd(char cmd); /// ĳ���� ������ ������ ����� ������.

};

extern BlueTClass BlueT;

#endif

