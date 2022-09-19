#include <Arduino.h>
#include <PD_UFP.h>

class PD_UFP_core_c PD_UFP;

void setup() { 
  Serial.begin(9600);
  Serial.println("Hello esp8266");
  // Disable until real hardware is available
  //PD_UFP.init(PD_POWER_OPTION_MAX_20V);
}

void loop() {
  // Disable until real hardware is available
  //PD_UFP.run();
  delay(5); // max sleep of 10ms to keep USB happy
}