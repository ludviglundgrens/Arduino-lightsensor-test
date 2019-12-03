//#define SECRET_SSID "KTH-IoT"
//#define SECRET_PASS "i2clQBy5Mb" 


#include "thingProperties.h"
#define ledPin 0
#define KnappPin A1
#define BrightPin A2

void setup() {

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  pinMode(ledPin, OUTPUT);
  pinMode(KnappPin, INPUT);
  pinMode(BrightPin, INPUT);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // from guide
  //int brightSensor = analogRead(PIN_BRIGHT);
  //brightness = 500 / (10.0 * (3.3 - (float)brightSensor / 1023 * 3.3) / ((float)brightSensor / 1023 * 3.3));
  
  // Your code here 
  Knapp = digitalRead(KnappPin);
  Ljussensor = analogRead(BrightPin);
  
  
  if(LED==1){
    digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else{
    digitalWrite(ledPin, LOW);
  }

}

void onLEDChange() {
  // Do something
}
void onLjussensorChange() {
  // Do something
}

void onKnappChange() {
  // Do something
}
