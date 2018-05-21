#include <AccelStepper.h>
#define HALFSTEP 8

// Motor pin definitions
#define motorPin1  5     // IN1 on the ULN2003 driver 1
#define motorPin2  6     // IN2 on the ULN2003 driver 1
#define motorPin3  7     // IN3 on the ULN2003 driver 1
#define motorPin4  8     // IN4 on the ULN2003 driver 1

#define motorPin21  9     // IN1 on the ULN2003 driver 1
#define motorPin22  10     // IN2 on the ULN2003 driver 1
#define motorPin23  11     // IN3 on the ULN2003 driver 1
#define motorPin24  12     // IN4 on the ULN2003 driver 1

const int photoResistorPin = 0;
const int threshold = 600;

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(HALFSTEP, motorPin21, motorPin23, motorPin22, motorPin24);


void setup() {
  stepper1.setMaxSpeed(1000.0);
  stepper1.setSpeed(-990); //Right motor going forward in negative.
  stepper2.setMaxSpeed(1000.0);
  stepper2.setSpeed(1000); //Left motor going forward in positive. 
}//--(end setup )---

void loop() {
  //keepInLine();
  stepper1.runSpeed();
  stepper2.runSpeed();
}

int isOnline() {
  return analogRead(photoResistorPin) < threshold;
}

void keepInLine() {
  if(isOnline()) {
    stepper1.setSpeed(500);
  } else {
     stepper1.setSpeed(-500);
  }
}
