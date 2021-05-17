#include <Arduino.h>
#include <Pixy2.h>

#include "_parameter/GlobalVariable.h"
#include "emergency_stop/EmergencyStop.h"
#include "line_sensor/PixyLineSensor.h"


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  emergency_stop_setup();
  pixy_line_sensor_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  pixy_read_line();
  if (pixy.line.numVectors) 
  {
    Serial.println(pixy_read_line_value);
  }
}