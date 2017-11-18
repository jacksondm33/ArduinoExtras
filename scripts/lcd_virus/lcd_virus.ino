
#include <LiquidCrystal.h>

LiquidCrystal lcd(27, 28, 30, 31, 32, 33);
String chars[] = {"Y","o","u"," ","A","r","e"," ","H","a","c","k","e","d","!"};

void setup() {
  pinMode(22, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  lcd.begin(16, 2);
  lcd.blink();
  for(int i = 0; i < 15; i++){
    lcd.print(chars[i]);
    delay(random(100,1000));
  }
  delay(1000);
  lcd.noBlink();
  lcd.setCursor(0,0);
  for(int i = 1; i < 16; i++){
    for(int j = 0; j < 10; j++){
      lcd.setCursor(random(0,i),random(0,2));
      lcd.print(random(0,2));
      delay(10);
    }
  }
}

void loop() {
  digitalWrite(22, random(0,2));
  digitalWrite(25, random(0,2));
  digitalWrite(26, random(0,2));
  delay(10);
  lcd.setCursor(random(0,16),random(0,2));
  lcd.print(random(0,2));
}

