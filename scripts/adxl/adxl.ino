//Accurate to +- 0.15 m/s^2

const int pinX = A0;
const int pinY = A1;
const int pinZ = A2;
const int infoLED = 53;
int x = 0; // Raw x reading
int y = 0; // Raw y reading
int z = 0; // Raw z reading
int dx = 0; // x - baseX
int dy = 0; // y - baseY
int dz = 0; // z - baseZ
float scale = 0; // Converts readings to m/s^2 units
int baseX = 0; // Reading on x axis with no acc.
int baseY = 0; // Reading on y axis with no acc.
int baseZ = 0; // Reading on z axis with no acc.
int baseGZ = 0; //Reading on z axis with gravity

void setup()
{
  Serial.begin(9600);
  pinMode(52, OUTPUT);
  pinMode(infoLED, OUTPUT);
  digitalWrite(52, HIGH);
  delay(1000);
  int temp = 0;
  for(int i = 0; i < 10; i++){
    temp += analogRead(pinX);
    delay(100);
  }
  baseX = temp / 10;
  temp = 0;
  for(int i = 0; i < 10; i++){
    temp += analogRead(pinY);
    delay(100);
  }
  baseY = temp / 10;
  temp = 0;
  for(int i = 0; i < 10; i++){
    temp += analogRead(pinZ);
    delay(100);
  }
  baseGZ = temp / 10;
  temp = 0;
  digitalWrite(infoLED, HIGH);
  delay(5000);
  for(int i = 0; i < 10; i++){
    temp += analogRead(pinZ);
    delay(100);
  }
  baseZ = temp / 10;
  temp = 0;
  digitalWrite(infoLED, LOW);
  scale = abs((baseGZ - baseZ) / 9.81);
}
void loop()
{

  x = analogRead(pinX);
  y = analogRead(pinY);
  z = analogRead(pinZ);
  dx = x - baseX;
  dy = y - baseY;
  dz = z - baseZ;
  Serial.print((float)dx / scale);
  Serial.print("\t");
  Serial.print((float)dy / scale);
  Serial.print("\t");
  Serial.print((float)dz / scale);
  Serial.println();
  delay(100);
}
