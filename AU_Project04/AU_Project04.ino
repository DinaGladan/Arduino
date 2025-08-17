const int greenLEDPin = 11;
const int blueLEDPin = 10;
const int redLEDPin = 9;

const int redsensorPin = A0; 
const int bluesensorPin = A2; 
const int greensensorPin = A1; 

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  redSensorValue = analogRead(redsensorPin);
  delay(5);
  greenSensorValue = analogRead(greensensorPin);
  delay(5);
  blueSensorValue = analogRead(bluesensorPin);

  Serial.print("Raw sensor values: \t red: ");
  Serial.print(redSensorValue);
  Serial.print("\t green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t blue: ");
  Serial.println(blueSensorValue);

  //sesor cita od 0 do 1023 a trebamo ga prebacit u raspon boja 
  //koji je od 0 do 255

  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  Serial.print("Mapped sensor values: \t red: ");
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t blue: ");
  Serial.println(blueValue);
  delay(250);

  //mijenjanje svjetline, 
  //pin na kojem mijenjamo i koju vrijednost stavljamo (0-255)
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);

}












