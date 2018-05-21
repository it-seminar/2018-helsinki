//PhotoResistor
int photoResistorPin = 0;
const int Threshold = 650;
void setup() {
  Serial.begin(9600);
  }

void loop() {
  Serial.println(isOnline());
  delay(10);
  }

int isOnline(){
  return analogRead(photoResistorPin) < Threshold;
}

//Echo
const int trigPin = 9;
const int echoPin = 10;

long duration;
int distanceCm;

void setup() {


pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
delay(10);
}
