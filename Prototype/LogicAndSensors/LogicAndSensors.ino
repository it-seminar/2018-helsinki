/*  Remote control of motors
 *  
 *    0 - Stop both motors
 *    1 - Both motors forward
 *    2 - Both motors backward
 *    3 - Turn left
 *    4 - Turn right
 */
//
//#define TRIGGER_PIN  2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
//#define ECHO_PIN     3  // Arduino pin tied to echo pin on the ultrasonic sensor.
//#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters).

//#include <NewPing.h>
#include <ByteTransfer.h>


//Set up pins for ByteTransfer
const int inPin = 4;
const int dataPin = 5;
const int outPin = 6;

uint8_t outData;
boolean waitingToWrite;
boolean paramWaiting;
uint8_t parameter;

//Ultra sensor
//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void sendByte(uint8_t data)
{
  outData = data;
  waitingToWrite = true;
}

void OnDataIn(uint8_t data)
{
  if(data == 2)
  {
    onFinishMove();
  }
}

bool OnDataOut(uint8_t &data)
{
  if(waitingToWrite)
  {
    data = outData;
    waitingToWrite = false;
    return true;
  }
  else if(paramWaiting)
  {
    data = parameter;
    paramWaiting = false;
    return true;
  }
  return false;
}

ByteTransfer bt(inPin, dataPin, outPin, OnDataIn, OnDataOut);

String inString = "";

void setup()
{
  delay(10000);
  bt.Initialize();
  waitingToWrite = false;
  paramWaiting = false;
}

int curState = 0;
int newState = 1;

void loop()
{
  if(!waitingToWrite && !paramWaiting)
  {
    if(curState != newState)
    {
      switch(newState)
      {
        case 1:
          moveForward(30);                         
          break;
        case 2:
          turnLeft(128); 
          break;
        case 3:
          moveForward(30);
          break;
        case 4:
          turnRight(128); 
          break;
      }
      curState = newState;
    }
    
  }
  bt.Update();
}

void moveForward(uint8_t cm)
{
  sendByte(10);
  parameter = cm;
  paramWaiting = true;
}

void moveBackward(uint8_t cm)
{
  sendByte(11);
  parameter = cm;
  paramWaiting = true;
}

void turnLeft(int value)
{
  sendByte(12);
  parameter = value - 1;
  paramWaiting = true;
}

void turnRight(int value)
{
  sendByte(13);
  parameter = value - 1;
  paramWaiting = true;
}

void onFinishMove()
{
  ++newState;
  if(newState > 4) newState = 1;
}



