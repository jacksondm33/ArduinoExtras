int last = LOW;
int current = LOW;
int count = 0;
int start = 0;

void setup() {
  Serial.begin(9600);
  pinMode(22, OUTPUT);
  digitalWrite(22, HIGH);
  start = millis();
}

void loop() {
  if(millis() - start < 5000){
    current = digitalRead(23);
    if(current == HIGH and last == LOW){
      count += 1;
    }
    last = current;
  }else{
    Serial.println(count);
    count = 0;
    start = millis();
  }
  delay(1);
}
