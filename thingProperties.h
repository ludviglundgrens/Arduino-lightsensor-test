#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[] = "f743b30d-bd02-4e61-8a52-176c1f2a1b36";

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)

void onLEDChange();

float Ljussensor;
bool LED;
bool Knapp;

void initProperties(){

  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(Ljussensor, READ, ON_CHANGE, NULL, 20.000000);
  ArduinoCloud.addProperty(LED, READWRITE, ON_CHANGE, onLEDChange);
  ArduinoCloud.addProperty(Knapp, READ, ON_CHANGE, NULL);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
