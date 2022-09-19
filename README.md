# Chargezilla README

This project is not yet ready for anyone to use ;-).  

When it is ready this README will be more useful.  Currently it is an unformatted set of notes.

## How to build/run/install

See [docs/BUILD](docs/BUILD.md).

## Remaining TODO items

See [docs/TODO](docs/TODO.md) for remaining software work items before bringing-up the board and running the charge algorithm.

## temporary devboard

pinout https://resource.heltec.cn/download/WiFi_Kit_8/WIFI_Kit_8_Pinout_Diagram.pdf

* SDA GPIO4/16/D2
* SCL GPIO5/24/D1

## Does the battery provide temperature feedback?

Per https://www.maximintegrated.com/en/design/technical-documents/app-notes/5/5681.html
See figure 5
Batteries are often provided with a negative temperature coefficient (NTC) thermistor, which is used to prevent the batteries from being charged at temperatures that are too high or too low. The battery, therefore, has three connections: a positive terminal (BAT+), a negative terminal (BAT-), and a connection for the NTC thermistor (see Figure 5). Note that some batteries with three connections have only a normal resistor inside that is used for identification. The value of the normal resistor will be constant and will not vary with the temperature of the battery.
Figure 5. Most lithium-ion batteries with three connections have an internal NTC thermistor connected as shown.
Figure 5. Most lithium-ion batteries with three connections have an internal NTC thermistor connected as shown.
Referring back to Figure 4, when an NTC thermistor is used, it should be connected between the THM pin and ground (via the BAT- connection). A resistor (R7) is also connected between the THM pin and a reference voltage (VL), which creates a potential divider. The value of the resistor is chosen so that it has the same value as the NTC thermistor at a temperature of +25°C. The voltage at the THM pin at +25°C will be equal to 0.5 VL. When the temperature rises or falls, the resistance of the NTC thermistor falls or rises, as will the voltage at the THM pin. The device will only charge when this voltage is between 0.28 VL and 0.74 VL. With contemporary NTC thermistors, this corresponds to a temperature between 0°C and 50°C. When no NTC thermistor is available, you should add R8, which causes the voltage at the THM pin to be 0.5 VL.

## Real board hardware notes

From coffeemaker:

Here's a draft of the schematic. The basic components are:
1. ESP-8266 in a ESP-12F module: https://docs.ai-thinker.com/_media/esp8266/docs/esp-12f_product_specification_en.pdf
2. FUSB302B USB-C PD controller: https://www.onsemi.com/pdf/datasheet/fusb302b-d.pdf
3. LT3755-2 CC-CV boost controller: https://www.analog.com/media/en/technical-documentation/data-sheets/lt3755-3755-1-3755-2.pdf

The ESP8266 communicates to the FUSB302B via I2C. It reads the capabilities of the USB-C PD charger and triggers the max power voltage/current combination.
When a battery is detected via the voltage divider to the ESP8266's ADC input, the LT3755 is turned on. The CC mode current can be set by the CTRL pin from the ESP8266.
The CV mode voltage 54.375V is set by the resistor divider R1 and R2 into the feedback pin of LT3755.

I think this may be a good reference for the USB-C PD IC: https://github.com/ryan-ma/PD_Micro

# Credits

We'd like to thank:

* https://github.com/ryan-ma/PD_Micro for their (MIT License) great FUSB302 code (which we've lightly reorganized for our use)


# License

FIXME TBD