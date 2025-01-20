# Platformio XIAO ESP32S3 Modbus Slave Exploration
This exploration project is to test the integration of an NTC temperature sensor on the XIAO ESP32S3.
It reports the temperature sensing through the logging interface!
NTC Sensor (3435 Beta version): https://www.aliexpress.com/item/4001345626993.html.

# Seeed Xiao ESP32-S3 references:
https://docs.platformio.org/en/latest//boards/espressif32/seeed_xiao_esp32s3.html
https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/

# Debug on Windows:
References https://community.platformio.org/t/how-to-use-jtag-built-in-debugger-of-the-esp32-s3-in-platformio/36042 and https://mydicedevice.com/?p=514.
1. Install latest version of "Espressif - WinUSB support for JTAG (ESP32-C3/S3)" driver https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/api-guides/jtag-debugging/configure-builtin-jtag.html.
2. Download Zadig https://zadig.akeo.ie/.
3. In Zadig, list all devices under options.
4. Install USB CDC driver for USB JTAG/serial debug unit (interface 0).
5. Install libusbK driver for USB JTAG/serial debug unit (interface 2).
6. Use platformio.ini from this project and update COM ports.
7. Upload and debug should now work through esp-builtin interface!

# Espressif NTC Example:
https://docs.espressif.com/projects/esp-iot-solution/en/latest/sensors/ntc_driver.html
https://github.com/espressif/esp-iot-solution/tree/17c072bdd192f5bdbe26976b50ae410ccdde1ff9/components/sensors/ntc_driver
