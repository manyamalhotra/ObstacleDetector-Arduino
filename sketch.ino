 /*
HC-SR04 Ultrasonic Sensor with LCD dispaly

HC-SR04 Ultrasonic Sensor
  VCC to Arduino 5V
  GND to Arduino GND
  Echo to Arduino pin 10
  Trig to Arduino pin 9

LCD Display  
  VSS to Arduino GND
  VDD to Arduino 5V
  VEE to Arduino GND
  RS to Arduino pin 11
  R/W to Arduino pin 12
  E to Arduino pin 13
  DB4 to Arduino pin 2
  DB5 to Arduino pin 1
  DB6 to Arduino pin 4
  DB7 to Arduino pin 5
  LED+ to Arduino 5V
  LED- to Arduino GND
  
*/
#include "pitches.h"
#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(11,12,13,2,1,4,5);  //Create Liquid Crystal Object called LCD

#define trigPin 9 //Sensor Trig pin connected to Arduino pin 9
#define echoPin 10 //Sensor Echo pin connected to Arduino pin 10
const int buzzPin =  3; //for buzzer

void setup() 
{  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin,OUTPUT); //control the buzzer via the digital pin 3 of Arduino Uno. 
  LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
  LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
  LCD.print("Target Distance:");  //Print Message on First Row
}

void loop() 
{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  LCD.setCursor(0,1);  //Set cursor to first column of second row
  LCD.print("                "); //Print blanks to clear the row
  LCD.setCursor(0,1);   //Set Cursor again to first column of second row
  LCD.print(distance); //Print measured distance
  LCD.print(" cm");  //Print your units.
  
  if(distance<20)
  {
    tone(3, 250);   //Plays 250Hz tone i.e. Buzzer
  }
  else
  {
    noTone(3);   
  }
  delay(500); //pause to let things settle
}
