/* !! =============================
 *  Title: joystick control for a servo
 *  Author: Jono Sanders
 *  Description - control for an arduino micro with the following features:
 *  1) reads in joystick data inputs
 *  2) sends that data to servo output
 *  
 *  Date: 08/23/2018
 =================================!!!! */

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int sensorPin = A5;
int sensorValue = 0;
int pos = 0;    // variable to store the servo position
int input = 1;

void setup() {
  myservo.attach(2);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  Serial.print("Reading is: ");
  Serial.println(sensorValue);
  if (sensorValue > 800){
    input = 1;
  }
  else if (sensorValue < 200){
      input = -1;
  }
  else { input = 0;}
  if (input){
    pos += input;
    if (pos > 110){
      pos = 110;
    }
    if (pos < 0){
      pos = 0;
    }
      Serial.print("Pos is: ");
  Serial.println(pos);
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(10);                       // waits 15ms for the servo to reach the position
    }
    
}
