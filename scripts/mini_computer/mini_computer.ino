#define sp SongPlayer

#include <LiquidCrystal.h>
#include <ReactGame.h>
#include <Alarm.h>
#include <Encoder.h>
#include <Matrix.h>
#include <MemoryFree.h>
#include <SongPlayer.h>

LiquidCrystal lcd(26, 27, 28, 29, 30, 31);
unsigned char red = 50;
unsigned char green = 49;
unsigned char blue = 48;
unsigned char bt1 = 25;
unsigned char bt2 = 24;
unsigned char bt3 = 23;
unsigned char bt4 = 22;
unsigned char speaker = 2;
unsigned char x = A0;
unsigned char y = A1;
unsigned char z = A2;
unsigned char sw = 51;
unsigned char dt = 52;
unsigned char clk = 53;
unsigned char encoderVal = 0;
unsigned char redVal = 0;
unsigned char greenVal = 0;
unsigned char blueVal = 0;
unsigned char col8 = 32;
unsigned char col7 = 33;
unsigned char row2 = 34;
unsigned char col1 = 35;
unsigned char row4 = 36;
unsigned char col6 = 37;
unsigned char col4 = 38;
unsigned char row1 = 39;
unsigned char row5 = 40;
unsigned char row7 = 41;
unsigned char col2 = 42;
unsigned char col3 = 43;
unsigned char row8 = 44;
unsigned char col5 = 45;
unsigned char row6 = 46;
unsigned char row3 = 47;
unsigned char* cols = new unsigned char[8]{col1, col2, col3, col4, col5, col6, col7, col8};
unsigned char* rows = new unsigned char[8]{row1, row2, row3, row4, row5, row6, row7, row8};
Encoder encoder = Encoder(clk, dt);
String programs[] = {"RGB_party", "scale", "matrix", "alarm", "react_game", "birthday"};

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(bt1, INPUT);
  pinMode(bt2, INPUT);
  pinMode(bt3, INPUT);
  pinMode(bt4, INPUT);
  pinMode(speaker, OUTPUT);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(z, INPUT);
  pinMode(clk, INPUT);
  pinMode(dt, INPUT);
  pinMode(sw, INPUT);
  pinMode(col1, OUTPUT);
  pinMode(col2, OUTPUT);
  pinMode(col3, OUTPUT);
  pinMode(col4, OUTPUT);
  pinMode(col5, OUTPUT);
  pinMode(col6, OUTPUT);
  pinMode(col7, OUTPUT);
  pinMode(col8, OUTPUT);
  pinMode(row1, INPUT);
  pinMode(row2, INPUT);
  pinMode(row3, INPUT);
  pinMode(row4, INPUT);
  pinMode(row5, INPUT);
  pinMode(row6, INPUT);
  pinMode(row7, INPUT);
  pinMode(row8, INPUT);
  digitalWrite(col1, HIGH);
  digitalWrite(col2, HIGH);
  digitalWrite(col3, HIGH);
  digitalWrite(col4, HIGH);
  digitalWrite(col5, HIGH);
  digitalWrite(col6, HIGH);
  digitalWrite(col7, HIGH);
  digitalWrite(col8, HIGH);
  digitalWrite(sw, HIGH);
  lcd.begin(16,2);
  lcd.noBlink();
  Serial.begin(9600);
}
 
void loop()
{
  showHome();
}
void showHome(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Program-MIO");
  lcd.setCursor(0,1);
  lcd.print("bt1-bt2");
  delay(500);
  for(;;){
    if(digitalRead(bt1) == HIGH){
      showPrograms();
      break;
    }
    if(digitalRead(bt2) == HIGH){
      showMIO();
      break;
    }
    delay(1);
  }
}
void showMIO(){
  for(;;){
    int pinNum = 0;
    int oldPinNum = 0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Pin:" + String(pinNum) + "-Enter");
    lcd.setCursor(0,1);
    lcd.print("rot1-bt1");
    delay(500);
    for(;;){
      oldPinNum = pinNum;
      pinNum += encoder.getChange();
      if(pinNum != oldPinNum){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Pin:" + String(pinNum) + "-Enter");
        lcd.setCursor(0,1);
        lcd.print("rot1-bt1");
      }
      if(digitalRead(bt1) == HIGH){
        showIo(pinNum);
        break;
      }
      if(digitalRead(bt4) == HIGH){
        return;
      }
      delay(1);
    }
  }
}
void showInput(int pinNum){
  int pinState = digitalRead(pinNum);
  int oldPinState = pinState;
  pinMode(pinNum, INPUT);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pin " + String(pinNum) + " Input:" + String(pinState));
  lcd.setCursor(0,1);
  lcd.print("");
  delay(500);
  for(;;){
    pinState = digitalRead(pinNum);
    if(pinState != oldPinState){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Pin " + String(pinNum) + " Input:" + String(digitalRead(pinNum)));
      lcd.setCursor(0,1);
      lcd.print("");
    }
    oldPinState = pinState;
    if(digitalRead(bt4) == HIGH){
      return;
    }
    delay(1);
  }
}
void showOutput(int pinNum){
  int pinState = digitalRead(pinNum);
  pinMode(pinNum, OUTPUT);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pin " + String(pinNum) + " Output:" + String(pinState));
  lcd.setCursor(0,1);
  lcd.print("bt1");
  delay(500);
  for(;;){
    if(digitalRead(bt1) == HIGH){
      pinState = (pinState / (-1) + 1);
      digitalWrite(pinNum, pinState);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Pin " + String(pinNum) + " Output:" + String(pinState));
      lcd.setCursor(0,1);
      lcd.print("bt1");
      delay(500);
    }
    delay(1);
    if(digitalRead(bt4) == HIGH){
      return;
    }
  }
}
void showPrograms(){
  for(;;){
    int index = 0;
    int oldIndex = index;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(programs[index] + "-Run");
    lcd.setCursor(0,1);
    lcd.print("rot1-bt1");
    delay(500);
    for(;;){
      oldIndex = index;
      index += encoder.getChange();
      if(index < 0){
        index = 0;
      }
      if(index >= (sizeof(programs)/sizeof(String))){
        index = (sizeof(programs)/sizeof(String)) - 1;
      }
      if(oldIndex != index){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(programs[index] + "-Run");
        lcd.setCursor(0,1);
        lcd.print("rot1-bt1");
      }
      if(digitalRead(bt1) == HIGH){
        execProgram(programs[index]);
        break;
      }
      if(digitalRead(bt4) == HIGH){
        return;
      }
      delay(1);
    }
  }
}
void showIo(int pinNum){
  for(;;){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Input-Output");
    lcd.setCursor(0,1);
    lcd.print("bt1-bt2");
    delay(500);
    for(;;){
      if(digitalRead(bt1) == HIGH){
        showInput(pinNum);
        break;
      }
      if(digitalRead(bt2) == HIGH){
        showOutput(pinNum);
        break;
      }
      if(digitalRead(bt4) == HIGH){
        return;
      }
      delay(1);
    }
  }
}
void execProgram(String program){
  if(program == "RGB_party"){
    RGB_party();
    return;
  }
  if(program == "scale"){
    scale();
    return;
  }
  if(program == "matrix"){
    matrix();
    return;
  }
  if(program == "alarm"){
    alarm();
    return;
  }
  if(program == "react_game"){
    reactGame();
    return;
  }
  if(program == "birthday"){
    birthday();
    return;
  }
}

void RGB_party(){
  while(digitalRead(bt4) != HIGH){
    int ran_color = random(1,4);
    if(ran_color == 1){
      digitalWrite(red, HIGH);
      delay(50);
      digitalWrite(red, LOW);
    }
    if(ran_color == 2){
      digitalWrite(green, HIGH);
      delay(50);
      digitalWrite(green, LOW);
    }
    if(ran_color == 3){
      digitalWrite(blue, HIGH);
      delay(50);
      digitalWrite(blue, LOW);
    }
  }
}
void scale(){
  int index = 50;
  while(index <= 20000){
    tone(speaker, index);
    index += 1;
    delay(1);
  }
  noTone(speaker);
}
void matrix(){
  Matrix matrix = Matrix(rows, cols);
  matrix.startUpdateManager(3, 1);
  matrix.getEditableSymbol(Matrix::letters[0]);
  matrix.getEditableSymbol(Matrix::letters[1]);
  delay(10000);
  matrix.clear();
  matrix.stopUpdateManager(3, 1);
}
void alarm(){
  Alarm alarm = Alarm(x, y, z, green, red, bt4, -1, speaker, &encoder, &lcd);
  alarm.armAlarm();
}
void reactGame(){
  ReactGame game = ReactGame(bt1, bt3, red, blue, green, "Red", "Blue", speaker, &lcd);
  game.playGame();
  while(digitalRead(bt4) == LOW){
    delay(10);
  }
}
void birthday(){
  sp player(speaker);
  const float** oct = sp::octaves;
  float* notes = new float[29]{oct[5][sp::d], oct[5][sp::d], oct[5][sp::e], oct[5][sp::d], oct[5][sp::g], oct[5][sp::f_g], sp::rest, oct[5][sp::d], oct[5][sp::d], oct[5][sp::e], oct[5][sp::d], oct[5][sp::a], oct[5][sp::g], sp::rest, oct[5][sp::d], oct[5][sp::d], oct[6][sp::d], oct[5][sp::b], oct[5][sp::g], oct[5][sp::f_g], oct[5][sp::e], sp::rest, oct[6][sp::c], oct[6][sp::c], oct[5][sp::b], oct[5][sp::g], oct[5][sp::a], oct[5][sp::g], sp::end_song};
  float* beats = new float[28]{0.75, 0.5, 1, 1, 1, 1, 1, 0.75, 0.5, 1, 1, 1, 1, 1, 0.75, 0.5, 1, 1, 1, 1, 1, 1, 0.75, 0.5, 1, 1, 1, 1};
  player.setSong(notes, beats, 100);
  player.playSong();
}
