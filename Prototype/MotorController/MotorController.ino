
//
/*  Remote control of two stepper motors
 *  
 *    0 - Stop both motors
 *    1 - Both motors forward
 *    2 - Both motors backward
 *    3 - Turn left
 *    4 - Turn right
 */
#include <AccelStepper.h>
#include <ByteTransfer.h>

const int motorAPin1 = 2;
const int motorAPin2 = 3;
const int motorAPin3 = 4;
const int motorAPin4 = 5;
const int motorBPin1 = 6;
const int motorBPin2 = 7;
const int motorBPin3 = 8;
const int motorBPin4 = 9;
// initialize the stepper library:
AccelStepper motorA(AccelStepper::FULL4WIRE, motorAPin1, motorAPin3, motorAPin2, motorAPin4);
AccelStepper motorB(AccelStepper::FULL4WIRE, motorBPin1, motorBPin3, motorBPin2, motorBPin4);

// Calibration
const int stepsPrRevolution = 2048;
const int mmPrRevolution = 258;
const int stepsPrFullTurn = 3720;


const int inPin = 10;
const int dataPin = 11;
const int outPin = 12;

uint8_t outData;
boolean waitingToWrite;

bool sendByte(uint8_t data)
{
  if(waitingToWrite) return false;
  outData = data;
  waitingToWrite = true;
  return true;
}

void OnDataIn(uint8_t data)
{
  switch(data)
  {
    case 0:
      motorAStop();
      motorBStop();
      sendByte(0);
      break;
    case 1:
      motorAForward();
      motorBForward();
      sendByte(0);
      break;
    case 2:
      motorABackward();
      motorBBackward();
      sendByte(0);
      break;
    case 3:
      motorAForward();
      motorBBackward();
      sendByte(0);
      break;
    case 4:
      motorABackward();
      motorBForward();
      sendByte(0);
      break;
    default:
      sendByte(1);
      break;
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
  return false;
}



ByteTransfer bt(inPin, dataPin, outPin, OnDataIn, OnDataOut);

int motorAState = 0;
int motorBState = 0;

void setup()
{
  waitingToWrite = false;
  delay(10000);
  bt.Initialize();
  motorA.setMaxSpeed(500.0);
  motorA.setAcceleration(200.0);
  motorB.setMaxSpeed(500.0);
  motorB.setAcceleration(200.0);
}

void loop()
{
  updateMotors();
  bt.Update();
}

void motorAStop()
{
  motorAState = 0;
  motorA.stop();
}

void motorBStop()
{
  motorBState = 0;
  motorB.stop();
}

void motorAForward()
{
  motorAState = 1;
  motorA.moveTo(motorA.currentPosition());
  motorA.move(-stepsPrRevolution);
}

void motorBForward()
{
  motorBState = 1;
  motorB.moveTo(motorB.currentPosition());
  motorB.move(stepsPrRevolution);
}

void motorABackward()
{
  motorAState = -1;
  motorA.moveTo(motorA.currentPosition());
  motorA.move(stepsPrRevolution);
}

void motorBBackward()
{
  motorBState = -1;
  motorB.moveTo(motorB.currentPosition());
  motorB.move(-stepsPrRevolution);
}

void updateMotors()
{
  if(motorAState == 1 && motorA.distanceToGo() < stepsPrRevolution)
  {
    motorA.move(-stepsPrRevolution);
  }
  if(motorAState == -1 && motorA.distanceToGo() < stepsPrRevolution)
  {
    motorA.move(stepsPrRevolution);
  }
  if(motorBState == 1 && motorB.distanceToGo() < stepsPrRevolution)
  {
    motorB.move(stepsPrRevolution);
  }
  if(motorBState == -1 && motorB.distanceToGo() < stepsPrRevolution)
  {
    motorB.move(-stepsPrRevolution);
  }
  motorA.run();
  motorB.run();
}
