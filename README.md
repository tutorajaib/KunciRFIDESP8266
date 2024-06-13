# KunciRFIDESP8266
/*
Wiring
RC522     Nodemcu8266      esp12f
3V        3V                3V
RST       D1                io5
GND       GND               GND
Miso      D6                io12
Mosi      D7                io13
SCK       D5                io14
SDA       D2                io4

Buzzer --> D0  (GPIO 16 esp12f)
Relay  --> D4  (GPIO 2  esp12f)
*/

/*
Bahan
- RC522
- Esp12f
- Resistor 10K 2pcs
- ams1117 3v3

Catatan
- pull up pin EN (enable)
- pull Down ping Gpio 15 (chip select)

opsional
- pull up pin Gpio0 dan pin Reset


*/
