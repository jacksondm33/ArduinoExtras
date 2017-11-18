int vin = 5;
int r1 = 220;
void setup() {
  Serial.begin(9600);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  digitalWrite(22, HIGH);
  digitalWrite(23, LOW);
}

void loop() {
  double vout = map(analogRead(A0), 0, 1023, 0, 5000) / 1000.00;
  int r2 = r1 * vout / ( (double)vin - vout );
  if((double)vin - vout == 0.00){
    Serial.println("Max");
  }else{
    Serial.println(r2);
  }
  delay(100);
}
