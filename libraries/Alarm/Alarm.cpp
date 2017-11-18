#include "Arduino.h"
#include "Alarm.h"
#include <Encoder.h>
#include <LiquidCrystal.h>

Alarm::Alarm(int x_pin, int y_pin, int z_pin, int safe_led, int alarm_led, int pass_bt, int pass, int speaker, Encoder* encoder, LiquidCrystal* lcd){
  pinMode(safe_led, OUTPUT);
  pinMode(alarm_led, OUTPUT);
  pinMode(speaker, OUTPUT);
  _x_pin = x_pin;
  _y_pin = y_pin;
  _z_pin = z_pin;
  _safe_led = safe_led;
  _alarm_led = alarm_led;
  _pass_bt = pass_bt;
  _pass = pass;
  _speaker = speaker;
  _encoder = encoder;
  _lcd = lcd;
}
void Alarm::armAlarm(){
  int oldx = 0;
  int oldy = 0;
  int oldz = 0;
  int newx = 0;
  int newy = 0;
  int newz = 0;
  int changex = 0;
  int changey = 0;
  int changez = 0;
  int alarm_freq = 2000;
  int sens = 3;
  int alarm_length = 5000;
  int alarm_time = alarm_length * 2;
  int delay_length = 10;
  int pass_attempts = 0;
  int max_attempts = 2;
  digitalWrite(_safe_led, HIGH);
  _lcd->clear();
  delay(1000);
  oldx = analogRead(_x_pin);
  oldy = analogRead(_y_pin);
  oldz = analogRead(_z_pin);
  while(true){
    alarm_time += delay_length;
    newx = analogRead(_x_pin);
    newy = analogRead(_y_pin);
    newz = analogRead(_z_pin);
    changex = newx - oldx;
    changey = newy - oldy;
    changez = newz - oldz;
    if(alarm_time > alarm_length){
      if(changex >= sens || changex <= -sens){
        setAlarm(alarm_freq);
	alarm_time = 0;
      }
      if(changey >= sens || changey <= -sens){
        setAlarm(alarm_freq);
	alarm_time = 0;
      }
      if(changez >= sens || changez <= -sens){
        setAlarm(alarm_freq);
	alarm_time = 0;
      }
    }
    if(alarm_time == alarm_length){
      unsetAlarm();
      alarm_time = alarm_length * 2;
      delay(100);
      newx = analogRead(_x_pin);
      newy = analogRead(_y_pin);
      newz = analogRead(_z_pin);
    }
    oldx = newx;
    oldy = newy;
    oldz = newz;
    if(digitalRead(_pass_bt) == HIGH && pass_attempts < max_attempts){
      unsetAlarm();
      alarm_time = alarm_length * 2;
      int index = 0;
      int time_change = 0;
      while(time_change <= 5000){
        index += _encoder->getChange();
        _lcd->print(index);
        delay(10);
        _lcd->clear();
        time_change += 10;
      }
      if(index == _pass){
        break;
      }else{
        pass_attempts += 1;
      }
    }
    delay(delay_length);
  }
  noTone(_speaker);
  digitalWrite(_alarm_led, LOW);
  digitalWrite(_safe_led, LOW);
}
void Alarm::setAlarm(int alarm_freq){
  tone(_speaker, alarm_freq);
  digitalWrite(_safe_led, LOW);
  digitalWrite(_alarm_led, HIGH);
  _lcd->clear();
  _lcd->setCursor(0,0);
  _lcd->print("Trying to hack");
  _lcd->setCursor(0,1);
  _lcd->print("the system???");
}
void Alarm::unsetAlarm(){
  noTone(_speaker);
  digitalWrite(_alarm_led, LOW);
  digitalWrite(_safe_led, HIGH);
  _lcd->clear();
}
