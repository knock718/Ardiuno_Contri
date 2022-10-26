#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int visitors = 0;
int sensor = 6;
int sensor1 = 7;
int buzzer = 8;


void setup() {
  lcd.begin(16, 2);
  lcd.print("Visitor counter");
  lcd.setCursor(0, 1);
  lcd.print("Visitors:");
  lcd.setCursor(9,2);
  lcd.print(visitors);
}

void loop() {
int sensorstate = digitalRead(sensor);
int sensor1state = digitalRead(sensor1);
  
  if(sensorstate == HIGH){
    digitalWrite(buzzer,HIGH);
       visitors++;
    delay(1500);
    }
  
  else if (sensor1state == HIGH) {
    visitors--;
    delay(1500);
    digitalWrite(buzzer,LOW);
  }
    lcd.setCursor(9,2);
  lcd.print(visitors);
}


 