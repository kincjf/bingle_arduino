
#include <SoftwareSerial.h>
#include <Servo.h>

#define TEST false
#define servoPin 12
#define N1 6
#define N2 7
#define N3 8
#define N4 9
#define ANGLE_ARRAY_SIZE 7
//sizeof(angleArray)/sizeof(int)

SoftwareSerial BTSerial(2, 3); //Connect HC-06 TX,RX
Servo verServo;

int buffPos;
String receiveCmd;
char cmd;
boolean isCarriageReturn;
boolean isNotEnd;
boolean nextCap;

int angleArray[] = {25,50,72,95,113,133,165};
int stepArray[] = {0,8,12,16,10,8,0};

void setup()  
{
    pinMode(N1, OUTPUT);
  pinMode(N2, OUTPUT);
  pinMode(N3, OUTPUT);
  pinMode(N4, OUTPUT);

  //horMotor.setSpeed(180);
  BTSerial.begin(9600);

}
void loop()
{

  if (BTSerial.available())
  {
    receiveBlue();

    if(isCarriageReturn && cmd == 'S'){

         #if TEST
          Serial.println("Start Capture!");
         #endif
         verServo.attach(servoPin);
         verServo.write(30);
         delay(1000);
         verServo.detach();
          BTSerial.write("C\r\n");

         for(int i=0; i<ANGLE_ARRAY_SIZE; i++){
          if(i != 0)
            changeVerticalAngle(angleArray[i]);
          horizontalRotation(stepArray[i]);
         }

         verServo.attach(servoPin);
         verServo.write(90);
         delay(1000);
         verServo.detach();

         BTSerial.write("E\r\n");
         delay(10);
     }
  }
  
}


void receiveBlue(){
  buffPos = 0;
  receiveCmd = "";
  isCarriageReturn = false;


  while(BTSerial.available()){
    
      buffPos++;

      char data = (char)BTSerial.read();
      cmd = data;
      isCarriageReturn = true;
    }
}

void horizontalRotation(int steps){

  for(int i=0; i<steps; i++){    //16번
          int calStep = 64*32/steps;
          myStepper(calStep);
          
          BTSerial.write("C\r\n");
          delay(10);
          
          waitNextCap();
   }

}

void changeVerticalAngle(int angle){
         waitNextCap();

         verServo.attach(servoPin);
         verServo.write(angle);
         delay(300);
         verServo.detach();

         BTSerial.write("C\r\n");
}

void waitNextCap(){
  while(!nextCap){
              receiveBlue();
              if(isCarriageReturn && cmd == 'F'){
                  nextCap = true;
              }
          }
   nextCap = false;
}

void myStepper(int si)
{
  while(si){
  digitalWrite(N1, LOW);
  digitalWrite(N2, LOW);
  digitalWrite(N3, HIGH);
  digitalWrite(N4, HIGH);
  delay(5);
  si--;
  if(si==0)
    break;
    digitalWrite(N1, HIGH);
  digitalWrite(N2, LOW);
  digitalWrite(N3, LOW);
  digitalWrite(N4, HIGH);

  delay(5);
  si--;
    if(si==0)
    break;
    digitalWrite(N1, HIGH);
  digitalWrite(N2, HIGH);
  digitalWrite(N3, LOW);
  digitalWrite(N4, LOW);

  delay(5);
  si--;
    if(si==0)
    break;
    digitalWrite(N1, LOW);
  digitalWrite(N2, HIGH);
  digitalWrite(N3, HIGH);
  digitalWrite(N4, LOW);

  delay(5);
    si--;
  }
}

