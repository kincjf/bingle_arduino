PANO v1.0

WHAT IS THIS?


BlueTClass : carriage return�� ������ ��Ŷ�� �ְ� �޴µ� ���ȴ�.
��-char cmd() : carriage returnd�� ������ ��Ŷ�� ���� �� ���� ���� ����.
��-void sendCmd(char cmd) : carrage return�� ������ ����� ������.

TwoPhaseStepperClass : ���� ������, �츮�� ����ϴ� 2�� ���ܸ��͸� �����ϰ���.
��-TwoPhaseStepperClass(int A, int B, int C, int D); : �ν��Ͻ� ������ ����ϴ� pin 4���� ������� �Է�.
��-void moveStep(int step); : �����̰��� �ϴ� step ��ŭ �Է� (64*32step = 360��)


ON WHAT HARDWARE DOES IT RUN?



DOCUMENTATION:
   ���⿡�� �� ������Ʈ �������� ��� �ִ��� ������ �����ϴ��� ���� �� �����ϴ� :-)

INSTALLING the source:
   ���⿡�� �ҽ��ڵ带 ��ġ�ϴ� ����� ���ؼ� ���ϴ�. 

SOFTWARE REQUIREMENTS:
   ���⿡�� ����Ʈ���� ���Ӽ��� ���ؼ� ���ϴ�. �����ϴµ� �ʿ��� ���̺귯�������..

CONFIGURING:
   ���⿡�� configure�ϴ� ����� ���Ͽ� ���ϴ�. autotool�� ����ؾ� �Ѵٴ��� cmake�� ����Ѵٴ���..

COMPILING:
   ���⿡�� ������ �ϴ� ����� ���ϴ�. make, make clean, Ȥ�� �ٸ� make *** ��ɿ� ���ؼ� ���� �� �� �����ϴ�.