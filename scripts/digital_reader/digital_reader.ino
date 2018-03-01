int dataPin = A0;
int clockPin = 2;
long freq = 2000000;
int current = 0;
int last = 0;

void setup() {
  tone(clockPin, freq);
  attachInterrupt(digitalPinToInterrupt(clockPin), readData, LOW);
  Serial.begin(freq);
}

void loop() {
  delay(10000);
}

void readData(){
  last = current;
  current = analogRead(dataPin);
  if(last != current){
    Serial.println(current);
  }
}

