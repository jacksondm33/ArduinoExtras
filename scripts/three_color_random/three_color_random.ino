int red = 53;
int green = 52;
int blue = 51;

void setup() {
  pinMode(red, OUTPUT);     
  pinMode(green, OUTPUT);     
  pinMode(blue, OUTPUT);     
}
void loop() {
  digitalWrite(red, HIGH);
  delay(100);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(100); 
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  delay(100);
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
  delay(100);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(100); 
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  delay(100);
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
  delay(100);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(100); 
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  delay(100);
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
  delay(100);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(100); 
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  delay(100);
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
  delay(100);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(100); 
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  delay(100);
  digitalWrite(blue, LOW);
  int test = random(1,4);
  if(test == 1){
    digitalWrite(red, HIGH);
    delay(5000);
    digitalWrite(red, LOW);
  }
  if(test == 2){
    digitalWrite(green, HIGH);
    delay(5000); 
    digitalWrite(green, LOW);
  }
  if(test == 3){
    digitalWrite(blue, HIGH);
    delay(5000);
    digitalWrite(blue, LOW);
  }
}
