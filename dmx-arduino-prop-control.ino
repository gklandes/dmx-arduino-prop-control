#include <Conceptinetics.h>

const int startAddress = 20;
const int channels = 1; 
const int ledPin = LED_BUILTIN;

// Configure a DMX slave controller
DMX_Slave dmx_slave(channels);

// the setup routine runs once when you press reset:
void setup() {             
  
  // Set initial start address, this can be changed remotely via RDM
  dmx_slave.setStartAddress(startAddress);
  
  // Enable DMX slave interface and start recording (without RDM won't work)
  dmx_slave.enable();  

  // setup status/test led
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);
}

void loop() {
  // Do stuff here
  int level = dmx_slave.getChannelValue(1);
  analogWrite(ledPin, level);
}
