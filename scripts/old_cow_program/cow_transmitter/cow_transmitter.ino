#include <SimbleeCOM.h>

//#define DEBUG

const int dataLength = 10;
const int valueDelay = 100;
const int* pins = new int[4] {2, 3, 4, 6};

const float devMax = 30;
const float weightMax = 75;

float** data = new float*[4] {new float[dataLength], new float[dataLength], new float[dataLength], new float[dataLength]};
float* means = new float[4];
float* devs = new float[4];
float* bias = new float[4] {0, 0, 0, 0};
char* outData = new char[5];

volatile int pos = 0;

volatile bool flag = false;
volatile bool limpFlag = false;

volatile int startTime = 0;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(pins[i], INPUT);
  }
  Serial.begin(9600);
  SimbleeCOM.mode = LOW_LATENCY;
  SimbleeCOM.begin();
  outData[0] = 0;
}

void loop() {

  startTime = millis();

  for (int i = 0; i < 4; i++) {
    data[i][pos] = convertWeight(analogRead(pins[i]));
    means[i] = mean(data[i]);
    devs[i] = standardDev(data[i], means[i]);
    outData[i + 1] = (char) (means[i] + bias[i]);
    if (devs[i] > devMax) {
      flag = true;
    }
  }

#ifdef DEBUG
  Serial.print("Back right data: ");
  Serial.println(data[0]);
  Serial.print("Back left data: ");
  Serial.println(data[1]);
  Serial.print("Front right data: ");
  Serial.println(data[2]);
  Serial.print("Front Left data: ");
  Serial.println(data[3]);
#endif

  SimbleeCOM.send(outData, 5);

  pos++;
  if (pos == dataLength) {
    pos = 0;
  }

  Serial.println(millis() - startTime);

  delay(valueDelay);
}

float convertWeight(int rawData) {
  return (float) rawData * 105.0 / 96.0;
}

float standardDev(float* inputData, float mean) {
  float total = 0;
  float difference;
  for (int i = 0; i < dataLength; i++) {
    difference = inputData[i] - mean;
    difference *= difference;
    total += difference;
  }
  return sqrt(total / dataLength);
}

float mean(float* inputData) {
  float total = 0;
  for (int i = 0; i < dataLength; i++) {
    total += inputData[i];
  }
  return total / dataLength;
}


