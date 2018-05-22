
//
/*  Remote control of two stepper motors
 *  
 *    0 - Stop both motors
 *    1 - Both motors forward
 *    2 - Both motors backward
 *    3 - Turn left
 *    4 - Turn right
 */
#include <ByteTransfer.h>
const int inPin = 2;
const int dataPin = 3;
const int outPin = 4;

uint8_t outData;
boolean waitingToWrite;

void OnDataIn(uint8_t data)
{
  if(data == 0)
  {
    Serial.println("Response: OK");
  }
  else if(data == 1)
  {
    Serial.println("Unknown command");
  }
  else
  {
    Serial.print("Unknown response: ");
    Serial.println(data);
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

String inString = "";

void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  delay(10000);
  bt.Initialize();
  Serial.println("Motor remote control:");
  Serial.println("  0 - Stop both motors");
  Serial.println("  1 - Both motors forward");
  Serial.println("  2 - Both motors backward");
  Serial.println("  3 - Turn left");
  Serial.println("  4 - Turn right");
  waitingToWrite = false;
}

void loop()
{
  if(!waitingToWrite)
  {
    while (Serial.available() > 0)
    {
      int inChar = Serial.read();
      if (isDigit(inChar))
      {
        // convert the incoming byte to a char and add it to the string:
        inString += (char)inChar;
      }
      // if you get a newline, print the string, then the string's value:
      if (inChar == '\n')
      {
        int command = inString.toInt();
        
        Serial.print("Sending command: ");
        Serial.println(command);
        outData = command;
        waitingToWrite = true;
        // clear the string for new input:
        inString = "";
       }
    }
  }
  bt.Update();
}



