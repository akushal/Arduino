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
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 7) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(led2,LOW);
  
  digitalWrite(motor1for,LOW);
  digitalWrite(motor2for,LOW);
  digitalWrite(motor1bac, HIGH);
  digitalWrite(motor2bac,HIGH);
}
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
      digitalWrite(motor1for,HIGH);
  digitalWrite(motor2for,HIGH);
  digitalWrite(motor1bac, LOW);
  digitalWrite(motor2bac,LOW);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
