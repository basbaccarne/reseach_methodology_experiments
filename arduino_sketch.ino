// Open this file (or copy/paste) in the Arduino IDE to upload the script to your Arduino
// Make sure you selected the Arduino Nano as your board (& have the associated packages installed)
// Make sure the right COM port is selected

// pinout settings
int sensorPin = A0;
int maximum = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the input data
  int reading = analogRead(sensorPin);  

  // serial print data
   Serial.println(reading);

  // set delay
  delay(200);
}
