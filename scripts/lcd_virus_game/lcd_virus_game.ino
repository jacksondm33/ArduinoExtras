
#include <LiquidCrystal.h>

int led = 22;
String name1 = "Riley";
String name2 = "Jackson";
int button1 = 23;
int button2 = 24;
int winled1 = 25;
int winled2 = 26;
int dis1 = 0;
int dis2 = 0;
int diss = -100;
int score1 = 0;
int score2 = 0;

LiquidCrystal lcd(27, 28, 30, 31, 32, 33);
String chars[] = {"Y","o","u"," ","A","r","e"," ","H","a","c","k","e","d","!"};

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(winled1, OUTPUT);
  pinMode(winled2, OUTPUT);
  pinMode(2, OUTPUT);
  lcd.begin(16, 2);
  for(int i = 0; i < 5; i++){
      dis1 = 0;
      dis2 = 0;
      lcd.setCursor(0,0);
      lcd.print(name1 + ": " + score1);
      lcd.setCursor(0,1);
      lcd.print(name2 + ": " + score2);
      if((score1 - score2) >= 2 && score1 >= 11){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(name1 + " wins!");
        lcd.setCursor(0,1);
        lcd.print("Final: " + String(score1) + "-" + String(score2));
        while(1==1){
          delay(1000);
        }
      }
      if((score2 - score1) >= 2 && score2 >= 11){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(name2 + " wins!");
        lcd.setCursor(0,1);
        lcd.print("Final: " + String(score1) + "-" + String(score2));
        while(1==1){
          delay(1000);
        }
      }
      int wait = random(1000, 10000);
      for(int i = 0; i < wait; i++){
        if(digitalRead(button1) == HIGH){
          tone(2, 100);
          diss = i;
          dis1 = 1;
        }
        if(digitalRead(button2) == HIGH){
          tone(2, 100);
          diss = i;
          dis2 = 1;
        }
        if(diss == i - 10){
          noTone(2);
          diss = -100;
        }
        delay(1);
      }
      noTone(2);
      digitalWrite(led, HIGH);
      while(true){
        if(digitalRead(button1) == HIGH){
          if(dis1 == 0){
            digitalWrite(winled1, HIGH);
            delay(1000);
            digitalWrite(winled1, LOW);
            score1 += 1;
            break;
          }else if(dis2 == 1){
            delay(1000);
            break;
          }      
        }
        if(digitalRead(button2) == HIGH){
          if(dis2 == 0){
            digitalWrite(winled2, HIGH);
            delay(1000);
            digitalWrite(winled2, LOW);
            score2 += 1;
            break;
          }else if(dis1 == 1){
            delay(1000);
            break;
          }
        }
        delay(1);
      }
      digitalWrite(led, LOW);
  }
  lcd.clear();
  lcd.setCursor(0,0);
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
  tone(2, random(100,3000));
  digitalWrite(led, random(0,2));
  digitalWrite(winled1, random(0,2));
  digitalWrite(winled2, random(0,2));
  delay(10);
  lcd.setCursor(random(0,16),random(0,2));
  lcd.print(random(0,2));
}

