# README

This project is not yet ready for anyone to use it ;-).  When it is ready this README will be more useful.  Currently it is an unformatted set of notes.


temporary devboard
pinout https://resource.heltec.cn/download/WiFi_Kit_8/WIFI_Kit_8_Pinout_Diagram.pdf

SDA GPIO4/16/D2
SCL GPIO5/24/D1

## Real board hardware notes

Here's a draft of the schematic. The basic components are:
1. ESP-8266 in a ESP-12F module: https://docs.ai-thinker.com/_media/esp8266/docs/esp-12f_product_specification_en.pdf
2. FUSB302B USB-C PD controller: https://www.onsemi.com/pdf/datasheet/fusb302b-d.pdf
3. LT3755-2 CC-CV boost controller: https://www.analog.com/media/en/technical-documentation/data-sheets/lt3755-3755-1-3755-2.pdf

The ESP8266 communicates to the FUSB302B via I2C. It reads the capabilities of the USB-C PD charger and triggers the max power voltage/current combination.
When a battery is detected via the voltage divider to the ESP8266's ADC input, the LT3755 is turned on. The CC mode current can be set by the CTRL pin from the ESP8266.
The CV mode voltage 54.375V is set by the resistor divider R1 and R2 into the feedback pin of LT3755.

I think this may be a good reference for the USB-C PD IC: https://github.com/ryan-ma/PD_Micro

# License

FIXME TBD