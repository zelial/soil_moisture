# soil_moisture

Measure soil moisture using Capatitive Soil Moisture Sensor and ESP8266. There are two versions of the sensor. They differ by the chip used and by the voltage they need to function:
 *  - chip TL555C with voltage regulator (LDO) -> works with both 5V and 3.3v
 *  - chip NE555 without LDO (0 ohm resistor instead) -> needs 5V
 
They also report different voltages  with the same moisture level - update the air & water constants at the beginning of the code before uploading.
 
 For battery operated sensors, the 3.3 version is preferable.



![Moisture sensors comparison](sensor_photo_labeled.jpg?raw=true "Moisture sensors comparison")
