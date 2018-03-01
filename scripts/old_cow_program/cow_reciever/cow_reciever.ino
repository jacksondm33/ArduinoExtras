#include <MemoryFree.h>

#include <SimbleeCOM.h>

// Current range at 0 packet loss: 14 m

int total = 0;
const int rate = 102;

void setup() {
  Serial.begin(9600);
  SimbleeCOM.mode = LOW_LATENCY;
  SimbleeCOM.begin();
}

void loop() {
  total++;
  //delay(1.0/(double)rate * 1000);
  delay(rate);
}

void SimbleeCOM_onReceive(unsigned int esn, const char* payload, int len, int rssi){
  Serial.printf("%d ", rssi);
  Serial.printf("%d ", (total - 1) * 10);
  for (int i = 0; i < len; i++){
    Serial.printf("%d ", payload[i]);
  }
  Serial.printf("\n");
  total = 0;
}
