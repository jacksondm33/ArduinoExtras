const int latchPin = 3;
const int clockPin = 4;
const int dataPin = 2;
//bit 1 : 3rd
//bit 2 : 2nd
//bit 3 : 8th
//bit 4 : 7th
//bit 5 : 5th
//bit 6 : 6th
//bit 7 : 1st
//bit 8 : 4th
int n = 0;
int t = 0;
 
void setup ()
{
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
}
void loop()
{
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,MSBFIRST,getData(n));
    digitalWrite(latchPin,HIGH);
    n += 1;
    if(n == 10){
      t += 1;
      if(t >= 6){
        shiftOut(dataPin,clockPin,MSBFIRST,B11111111);
      }else{
        n = 0;
      }
    }
    delay(1000);
}
byte getData(int num){
  switch(num){
    case 1:
    return B00001001;
    break;
    case 2:
    return B10010111;
    break;
    case 3:
    return B10011101;
    break;
    case 4:
    return B01011001;
    break;
    case 5:
    return B11011100;
    break;
    case 6:
    return B11011110;
    break;
    case 7:
    return B10001001;
    break;
    case 8:
    return B11011111;
    break;
    case 9:
    return B11011101;
    break;
    case 0:
    return B11001111;
    break;
    default:
    return B11111111;
    break;
  }
}
