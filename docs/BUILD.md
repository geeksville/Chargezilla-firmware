# Building Chargezilla

## Installing tools

1. Clone this project with "git clone https://github.com/geeksville/Chargezilla-firmware.git"
2. Install the platformio toolchain.  There are a number of ways you can install it, but the easiest is to install VSCode and then their extension.  Only [three steps](https://platformio.org/install/ide?install=vscode) are needed.

## Building and flashing the code

1. cd into "Chargezilla-firmware"
2. Connect your Chargezilla to a serial port (the board does not include a built-in USB-Serial adapter).
3. Either use the VSCode IDE (recommended for development), or if you just want to build/install the firmware, run the following at your OS command line: "pio run -t upload"

This will fetch any dependencies, build the firmware and try to program any connected ESP8266 board.  You should see something like:

```
ebike-charger$ pio run -t upload
Processing huzzah (platform: espressif8266; board: huzzah; framework: arduino)
--------------------------------------------------------------------------------
Verbose mode can be enabled via `-v, --verbose` option
CONFIGURATION: https://docs.platformio.org/page/boards/espressif8266/huzzah.html
PLATFORM: Espressif 8266 (4.0.1) > Adafruit HUZZAH ESP8266
HARDWARE: ESP8266 80MHz, 80KB RAM, 4MB Flash
PACKAGES: 
 - framework-arduinoespressif8266 @ 3.30002.0 (3.0.2) 
 - tool-esptool @ 1.413.0 (4.13) 
 - tool-esptoolpy @ 1.30000.201119 (3.0.0) 
 - tool-mklittlefs @ 1.203.210628 (2.3) 
 - tool-mkspiffs @ 1.200.0 (2.0) 
 - toolchain-xtensa @ 2.100300.210717 (10.3.0)
LDF: Library Dependency Finder -> https://bit.ly/configure-pio-ldf
LDF Modes: Finder ~ chain, Compatibility ~ soft
Found 36 compatible libraries
Scanning dependencies...
Dependency Graph
|-- Wire @ 1.0
|-- FUSB302
|   |-- Wire @ 1.0
Building in release mode
Retrieving maximum program size .pio/build/huzzah/firmware.elf
Checking size .pio/build/huzzah/firmware.elf
Advanced Memory Usage is available via "PlatformIO Home > Project Inspect"
RAM:   [====      ]  35.2% (used 28832 bytes from 81920 bytes)
Flash: [===       ]  26.2% (used 273497 bytes from 1044464 bytes)
Configuring upload protocol...
AVAILABLE: espota, esptool
CURRENT: upload_protocol = esptool
Looking for upload port...

Warning! Please install `99-platformio-udev.rules`. 
More details: https://docs.platformio.org/en/latest/core/installation/udev-rules.html

Auto-detected: /dev/ttyACM0
Uploading .pio/build/huzzah/firmware.bin
esptool.py v3.0
Serial port /dev/ttyACM0
Connecting....
Chip is ESP8266EX
Features: WiFi
Crystal is 26MHz
MAC: 44:17:93:1c:3f:f7
Uploading stub...
Running stub...
Stub running...
Configuring flash size...
Compressed 277648 bytes to 202955...
Writing at 0x00000000... (7 %)
Writing at 0x00004000... (15 %)
Writing at 0x00008000... (23 %)
Writing at 0x0000c000... (30 %)
Writing at 0x00010000... (38 %)
Writing at 0x00014000... (46 %)
Writing at 0x00018000... (53 %)
Writing at 0x0001c000... (61 %)
Writing at 0x00020000... (69 %)
Writing at 0x00024000... (76 %)
Writing at 0x00028000... (84 %)
Writing at 0x0002c000... (92 %)
Writing at 0x00030000... (100 %)
Wrote 277648 bytes (202955 compressed) at 0x00000000 in 17.9 seconds (effective 124.0 kbit/s)...
Hash of data verified.

Leaving...
Hard resetting via RTS pin...
========================= [SUCCESS] Took 20.34 seconds =========================
```

## Monitoring the debug serial output

You can see the serial debugging output at 9600 bps with a command like: "pio run -t monitor".  Or if you'd like to build/install and then switch to the debug console it can be done with one command "pio run -t upload -t monitor".  Press ctrl-c to exit the serial monitor.

