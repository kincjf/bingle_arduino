PANO v1.0

WHAT IS THIS?


BlueTClass : carriage return을 포함한 패킷을 주고 받는데 사용된다.
├-char cmd() : carriage returnd을 포함한 패킷이 오면 그 앞의 값을 리턴.
└-void sendCmd(char cmd) : carrage return을 포함한 명령을 보낸다.

TwoPhaseStepperClass : 가로 움직임, 우리가 사용하는 2상 스텝모터를 동작하게함.
├-TwoPhaseStepperClass(int A, int B, int C, int D); : 인스턴스 생성시 사용하는 pin 4개를 순서대로 입력.
└-void moveStep(int step); : 움직이고자 하는 step 만큼 입력 (64*32step = 360도)


ON WHAT HARDWARE DOES IT RUN?



DOCUMENTATION:
   여기에는 이 프로젝트 문서들이 어디에 있는지 무엇을 설명하는지 쓰는 것 같습니다 :-)

INSTALLING the source:
   여기에는 소스코드를 설치하는 방법에 대해서 씁니다. 

SOFTWARE REQUIREMENTS:
   여기에는 소프트웨어 종속성에 대해서 씁니다. 빌드하는데 필요한 라이브러리라던지..

CONFIGURING:
   여기에는 configure하는 방법에 대하여 씁니다. autotool을 사용해야 한다던지 cmake를 사용한다던지..

COMPILING:
   여기에는 컴파일 하는 방법을 씁니다. make, make clean, 혹은 다른 make *** 명령에 대해서 쓰면 될 것 같습니다.