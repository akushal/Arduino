/*
 HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 13 Trig to Arduino pin 12
 Red POS to Arduino pin 11
 Green POS to Arduino pin 10
 560 ohm resistor to both LED NEG and GRD power rail
 More info at: http://goo.gl/kJ8Gl
 Original code improvements to the Ping sketch sourced from Trollmaker.com
 Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
 */

#define trigPin 6
#define echoPin 5
#define led 13
#define led2 10
#define motor1for  11
#define motor1bac 10
#define motor2for 9
#define motor2bac 8
#define xdist 50
#define servo 7
#include <Servo.h>
Servo servoMain; // Define our Servo
long duration, distance;
 int status_roll=0;
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(motor1for, OUTPUT);
  pinMode(motor2for, OUTPUT);
  pinMode(motor1bac, OUTPUT);
  pinMode(motor2bac, OUTPUT);
  servoMain.attach(servo); // servo on digital pin 10
}

void loop() {

   caldistance();
   
  if (distance <= xdist) {  // This is where the LED On/Off happens
      digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
      digitalWrite(led2,LOW);
      spin ();
     // roll();
  }
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);

    forward();
    //  digitalWrite(motor1for,HIGH);
 // digitalWrite(motor2for,HIGH);
  //digitalWrite(motor1bac, LOW);
 // digitalWrite(motor2bac,LOW);
   //servoMain.write(45);  // Turn Servo Left to 45 degrees
  // delay(1000);          // Wait 1 second
  // servoMain.write(0);   // Turn Servo Left to 0 degrees
  // delay(1000);          // Wait 1 second
  // servoMain.write(90);  // Turn Servo back to center position (90 degrees)
  // delay(1000);          // Wait 1 second
  // servoMain.write(135); // Turn Servo Right to 135 degrees
  // delay(1000);          // Wait 1 second
  // servoMain.write(180); // Turn Servo Right to 180 degrees
  // delay(1000);          // Wait 1 second
  // servoMain.write(90);  // Turn Servo back to center position (90 degrees)
  // delay(1000);          // Wait 1 second   
  }
  //if (distance >= 200 || distance <= 0){
   // Serial.println("Out of range");
  //}
  //else {
    Serial.print(distance);
    Serial.println(" cm");
  //}
  delay(500);
}

void caldistance() {
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 }

 void roll() {

    if (status_roll == 0 ) { 
      servoMain.write(1);  
      status_roll=1;
      Serial.println("Turning 135 Deg right" + status_roll);
    }
     else {

        //servoMain.write(0);
        servoMain.write(145); 
        status_roll=0;
        Serial.println("Turning 90 deg left");
     }
  //Serial.print(status_roll);
  //Serial.println();
  //servoMain.write(0);   // Turn Servo Left to 0 degrees

  
 }

 void spin () {
  digitalWrite(motor1for,HIGH);
  digitalWrite(motor2bac, HIGH);
  digitalWrite(motor1bac, LOW);
  digitalWrite(motor2for, LOW);
 }


void forward () {

  digitalWrite(motor1for, HIGH);
  digitalWrite(motor2for, HIGH);
  digitalWrite(motor1bac, LOW);
  digitalWrite(motor2bac, LOW);
  
}

