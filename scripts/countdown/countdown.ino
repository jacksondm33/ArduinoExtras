int num1 = 9;
int num2 = 0;
void setup(){
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(46, OUTPUT);
}
void loop(){
  if(num1 == 1){
    digitalWrite(30, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(24, HIGH);
  }else if(num1 == 2){
    digitalWrite(31, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(22, HIGH);
    digitalWrite(23, HIGH);
    digitalWrite(24, HIGH);
  }else if(num1 == 3){
    digitalWrite(31, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(23, HIGH);
    digitalWrite(24, HIGH);
  }else if(num1 == 4){
    digitalWrite(28, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(24, HIGH);
  }else if(num1 == 5){
    digitalWrite(28, HIGH);
    digitalWrite(31, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(23, HIGH);
  }else if(num1 == 6){
    digitalWrite(28, HIGH);
    digitalWrite(31, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(23, HIGH);
    digitalWrite(22, HIGH);
  }else if(num1 == 7){
    digitalWrite(31, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(24, HIGH);
  }else if(num1 == 8){
    digitalWrite(22, HIGH);
    digitalWrite(23, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(31, HIGH);
  }else if(num1 == 9){
    digitalWrite(23, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(31, HIGH);
  }else if(num1 == 0){
    digitalWrite(23, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(22, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(31, HIGH);
  }
  if(num2 == 1){
    digitalWrite(40, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(34, HIGH);
  }else if(num2 == 2){
    digitalWrite(41, HIGH);
    digitalWrite(40, HIGH);
    digitalWrite(37, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
    digitalWrite(34, HIGH);
  }else if(num2 == 3){
    digitalWrite(41, HIGH);
    digitalWrite(40, HIGH);
    digitalWrite(37, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(33, HIGH);
    digitalWrite(34, HIGH);
  }else if(num2 == 4){
    digitalWrite(38, HIGH);
    digitalWrite(40, HIGH);
    digitalWrite(37, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(34, HIGH);
  }else if(num2 == 5){
    digitalWrite(38, HIGH);
    digitalWrite(41, HIGH);
    digitalWrite(37, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(33, HIGH);
  }else if(num2 == 6){
    digitalWrite(38, HIGH);
    digitalWrite(41, HIGH);
    digitalWrite(37, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(33, HIGH);
    digitalWrite(32, HIGH);
  }else if(num2 == 7){
    digitalWrite(41, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(40, HIGH);
    digitalWrite(34, HIGH);
  }else if(num2 == 8){
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(37, HIGH);
    digitalWrite(38, HIGH);
    digitalWrite(40, HIGH);
    digitalWrite(41, HIGH);
  }else if(num2 == 9){
    digitalWrite(33, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(37, HIGH);
    digitalWrite(38, HIGH);
    digitalWrite(40, HIGH);
    digitalWrite(41, HIGH);
  }else if(num2 == 0){
    digitalWrite(33, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(38, HIGH);
    digitalWrite(40, HIGH);
    digitalWrite(41, HIGH);
  }
    if(num2 == 0){
      if(num1 == 0){
        digitalWrite(46, HIGH);
      }else{
        num2 = 9;
        num1 -= 1;
      }
    }else{
      num2 -= 1;
    }
    delay(1000);
  digitalWrite(22, LOW); //1
  digitalWrite(23, LOW); //6
  digitalWrite(24, HIGH); //power
  digitalWrite(25, LOW); //5
  digitalWrite(26, LOW); //8
  digitalWrite(27, LOW); //7
  digitalWrite(28, LOW); //2
  digitalWrite(29, LOW); //ground
  digitalWrite(30, LOW); //4
  digitalWrite(31, LOW); //3
  
  digitalWrite(32, LOW); //1
  digitalWrite(33, LOW); //6
  digitalWrite(34, HIGH); //power
  digitalWrite(35, LOW); //5
  digitalWrite(36, LOW); //8
  digitalWrite(37, LOW); //7
  digitalWrite(38, LOW); //2
  digitalWrite(39, LOW); //ground
  digitalWrite(40, LOW); //4
  digitalWrite(41, LOW); //3
}
