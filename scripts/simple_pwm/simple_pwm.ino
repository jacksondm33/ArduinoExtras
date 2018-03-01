int freq;

void setup() {
  pinMode(2, OUTPUT);
  freq = 0;
}

void loop() {
  tone(2, freq);
  freq++;
}
