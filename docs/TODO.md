# TODO

## Before real board

* FUSB302B USB-C PD controller support
* Check that PIN_FUSB302_INT actually maps to GPIO 9 in the arduino firmware
* LT3744-2 CC-CV boost controller support - esp8266 arduino layer has a wrapper to drive a PWM output as a basic DAC https://randomnerdtutorials.com/esp8266-pwm-arduino-ide/
* Basic charge algorithm

## Before user release

* Figure out if temperature monitoring is needed or possible
* Basic hardwired wifi config
* application monitor via hw watchdog, ensure it stops charging on failure
* Nice ad-hoc/infrastructure wifi setup flow (via a TBD lib)
* REST/JSON API for monitoring & setting charge options
* Robust charge algorithm/state-machine

## Eventually

* HTML/javascript frontend embedded in device for driving the REST API
* Use this library for OTA updates and the web server? https://randomnerdtutorials.com/esp8266-nodemcu-ota-over-the-air-vs-code/
  