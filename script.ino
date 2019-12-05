//#define SECRET_SSID "KTH-IoT"
//#define SECRET_PASS "i2clQBy5Mb" 


#include "thingProperties.h"
#define BrightPin A2

void setup() {

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  pinMode(BrightPin, INPUT);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  
  // Your code here 
  Ljussensor = analogRead(BrightPin);
}

void onLjussensorChange() {
}

