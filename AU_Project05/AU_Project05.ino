#include <Servo.h>

Servo myServo;
int const potPin = A0;
int potValue;
int angle;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);
  Serial.print("potValue: ");
  Serial.print(potValue);

  //pretvaramo procitanu vrijednost u kut
  // vrijednost, min i max inputa, min i max outputa
  angle = map(potValue, 0, 1023, 0, 179);

  myServo.write(angle); //pomicemo ga za taj kut;
  delay(15);
}
