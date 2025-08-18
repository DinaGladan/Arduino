const int sensorPin = A0;
int sensorValue;
const int ledPin = 13;
int sensorHigh = 0;
int sensorLow = 1023;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while(millis()<5000){
    sensorValue = analogRead(sensorPin);
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  tone(8, pitch, 20); //pin, frekvencija, trajanje;
  delay(250);

}
