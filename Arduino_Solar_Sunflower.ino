#include <Servo.h>

int sensorPin = A0;
int servoPin  = 9;

Servo myservo;

// Measure these values using a flashlight from different angles.
// The Serial.println() function will print the changing values
// as you move the light from one side to the other.
int east = 350;
int west = 890;

void setup() {
  // This happens once when the sketch is run
  myservo.attach(servoPin);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Repeat this over and over!
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  // Map the sensor values from to servo positions
  // Sensor values range from east (minimum) to west (maximum)
  // Servo values range from 0 to 180
  int angle = map(sensorValue, east, west, 180, 0);
  myservo.write( angle ); 
  delay(100);
}

