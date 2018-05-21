int photoResistorPin = 0;

void setup() {
  Serial.begin(9600);
  }

void loop() {
  Serial.println(analogRead(photoResistorPin));
  delay(10);
  }
