
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  

//Distance sensor
int trigPin = 10;
int echoPin = 11;

//Flashing LED on Arduino board

boolean isClose = false;
//LCD










void setup ()
{
  
  pinMode(trigPin, OUTPUT);  //The transmit pin of the ultrasonic sensor
  pinMode(echoPin, INPUT);   //The receive pin of the ultrasonic sensor
Serial.begin(9600);
 
  lcd.begin(20,4);
  lcd.backlight(); 
 
 
                // go home

}

void loop()
{
  int duration, distance; 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  distance = duration / 58;
  if(distance < 100 && isClose == false){
    clearLine(0);
    clearLine(1);
    clearLine(2);
    clearLine(3);
    isClose = true;
    lcd.setCursor(0,0);
    lcd.print("too close.");
    lcd.setCursor(0,1);
    lcd.print("eye strain risk");
  }
  else if(isClose == true && distance > 200){
    isClose = false;
    clearLine(0);
    clearLine(1);
    clearLine(2);
    clearLine(3);
   
    lcd.setCursor(0,0);
    lcd.print("too far.");
    lcd.setCursor(0,1);
    lcd.print("you're missing out");
   }

   
 Serial.print(distance); 
  Serial.println(" distance"); 
  
  


}


void clearLine(int line){
  lcd.setCursor(0, line);
  lcd.print("                    ");
}


