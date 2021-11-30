// Open this file (or copy/paste) in the Arduino IDE to upload the script to your Arduino
// Make sure you selected the Arduino Nano (or other Arduino) as your board (& have the associated packages installed)
// Make sure the right COM port is selected

// libraries
#include <Wire.h>
#include "Adafruit_MPRLS.h"

// settings
#define RESET_PIN  -1  
#define EOC_PIN    -1 
Adafruit_MPRLS mpr = Adafruit_MPRLS(RESET_PIN, EOC_PIN);

void setup() {
  Serial.begin(115200);
  Serial.println("MPRLS Simple Test");
  if (! mpr.begin()) {
    Serial.println("Failed to communicate with MPRLS sensor, check wiring?");
    while (1) {
      delay(10);
    }
  }
  Serial.println("Found MPRLS sensor");
}


void loop() {
  float pressure_hPa = mpr.readPressure();
  Serial.println(pressure_hPa / 68.947572932);
  delay(500);
}
