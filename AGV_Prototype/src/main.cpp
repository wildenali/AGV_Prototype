#include <Arduino.h>

#include "_parameter/GlobalVariable.h"
#include "emergency_stop/EmergencyStop.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  emergency_stop_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
}