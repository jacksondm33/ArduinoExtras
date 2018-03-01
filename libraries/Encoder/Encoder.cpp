#include "Arduino.h"
#include "Encoder.h"

Encoder::Encoder(int clk, int dt){
  pinMode(clk, INPUT);
  pinMode(dt, INPUT);
  _clk = clk;
  _dt = dt;
}
int Encoder::getChange(){
  static int oldA = HIGH;
  static int oldB = HIGH;
  int result = 0;
  int newA = digitalRead(_clk);
  int newB = digitalRead(_dt);
  if (newA != oldA || newB != oldB){
    if (oldA == HIGH && newA == LOW){
      result = (oldB * 2 - 1);
    }
  }
  oldA = newA;
  oldB = newB;
  return result;
}

