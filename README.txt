PANO v1.0


BlueTClass : carriage return을 포함한 패킷을 주고 받는데 사용된다.
├-char cmd() : carriage returnd을 포함한 패킷이 오면 그 앞의 값을 리턴.
└-void sendCmd(char cmd) : carrage return을 포함한 명령을 보낸다.

TwoPhaseStepperClass : 가로 움직임, 우리가 사용하는 2상 스텝모터를 동작하게함.
├-TwoPhaseStepperClass(int A, int B, int C, int D); : 인스턴스 생성시 사용하는 pin 4개를 순서대로 입력.
└-void moveStep(int step); : 움직이고자 하는 step 만큼 입력 (64*32step = 360도)


하드웨어 스펙

세로 모터 mg996r
가로 모터 http://motorbank.kr/shop/goods/goods_view.php?goodsno=6703&category=006003
MCU 아두이노 나노
블루투스 모듈
7.4V 리튬 폴리머 배터리


구성시 주의사항

- 7.4v 사용시 세로 모터인 mg996r의 정격 전압보다 높아 다이오드 2개를 연결해서 전압을 강하시켜 사용해야함.
- 가로모터 PIN 6, 7, 8, 9
- 블루투스 PIN 0, 1 꼭 RX TX 하드웨어 핀을 사용해야 함.
- 세로모터 PIN 12


각도 설정법

uint8_t horArr[6] = { 86,86,86,86,86,86 }; <--가로 각도 step (64*32step = 360도)
uint8_t verArr[6][7] = { { 6,55,73,90,113,137,155 }, <--세로 각도
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 },
{ 6,55,73,90,113,137,155 } };

세로 각도 변수의 각 행의 첫번째 열은 행의 size를 나타내고 뒤로 나오는 숫자가 각도임.
가로 각도가 한번 변경되고 그 다음 가로 각도 index를 행으로 하는 verArr[index][]의 각도로 세로각도가 변경됨.
