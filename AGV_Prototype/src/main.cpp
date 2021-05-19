#include <Arduino.h>
#include <Pixy2.h>

#include <Parameters.h>
#include <EmergencyStop.h>
#include <PixyLineSensor.h>
#include <PID.h>
#include <Motor.h>
#include <LineFollower.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  emergency_stop_setup();
  pixy_line_sensor_setup();
}

void loop() {

  output_PID = hitung_PID(pixy_read_line());
  LineFollowerBasic(output_PID);

  Serial.print(-100);
  Serial.print("\t");
  Serial.print(output_PID);
  Serial.print("\t");
  Serial.print(SPEED_LEFT);
  Serial.print("\t");
  Serial.print(SPEED_RIGHT);
  Serial.print("\t");
  Serial.println(100);
}