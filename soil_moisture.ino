#include <utils.h>
#include "configuration.h"

// sensor data (from analog pin)
int moisture_raw;
// interpreted raw data (0-100% moisture)
int moisture;

/*
 * Maximum and minimum voltage from sensor differ based on the version
 * of the sensor: 
 *  - chip TL555C with voltage regulator (LDO)
 *  - chip NE555 without LDO (0 ohm resistor instead)
 * Test your sensor and customize air/water values:
 */

// maximum value returned when sensor is in a pure air
int air = 1024; // no LDO
//int air = 720 ;   // with LDO
// minimum value returned when sensor is submerged in tap water
int water = 600;  // no LDO
//int water = 300;    // with LDO

void setup() {
    init_serial();
    wifi_reconnect(ssid, wifi_password, ip_last_byte);
}

void loop() {
   // get analog moisture_raw sensor data
  int moisture_raw = analogRead(A0);
  // interpret data
  moisture = 100 - int((moisture_raw - water) / ((air - water) / 100.0));
  logln("moisture raw: "+ String(moisture_raw) + " moisture: " + moisture + "%");
  upload();
  delay(refresh_rate*1000);
}

void upload() {
  Broker b = Broker(broker_url);
  b.addProperty("refresh_rate", String(refresh_rate));
  b.addProperty("moisture", String(moisture));
  b.upload();
}
