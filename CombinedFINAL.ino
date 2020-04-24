#include <LiquidCrystal.h>
#include "SR04.h"

#define TRIG_PIN 12
#define ECHO_PIN 11

LiquidCrystal lcd(13, 10, 5, 4, 3, 2);

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

const int buzzerPin = 8;

//Beginning of Void Setup

void setup() {

pinMode(9, OUTPUT);
  
  Serial.begin(9600);
   delay(0);

pinMode(buzzerPin, OUTPUT);
}

//Begin Void Loop

void loop() { 
  
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");   //Reading in Distance
   delay(0);

lcd.begin(16, 2); 
lcd.clear();  

if(a >= 40){
   lcd.print("SLOW DOWN"); 
}
else
    if( 20 <= a && a < 40){
      lcd.print("STOP TOO CLOSE"); 
    }
   else
    if( a < 20){
      lcd.print("YOU WILL HIT");
    }
   

   lcd.setCursor(0, 1);
   lcd.print(a);          //Printing Out Distance
   lcd.print(" cm  ");

  digitalWrite(9, HIGH);    
  delay(a * 15);          //LED Blinking      
  digitalWrite(9, LOW);    
  delay(a * 15);     

  tone(8, 2500,250);      //Buzzer Going Off
  delay(a * 15);                       
}
