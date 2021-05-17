#include <Pixy2.h>
Pixy2 pixy;

#include "motor.h"
#include "pid.h"

void setup() {
  Serial1.begin(19200);           /*---Pixy------*/
  Serial.begin(115200);
  Serial.print("Starting...\n");

  pixy.init();
  Serial.println(pixy.changeProg("line"));
  pixy.setLamp(1,1);
  
  // Set all the motor control pins to outputs
  pinMode(enKiri, OUTPUT);
  pinMode(enKanan, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
}

void loop() 
{
  no_Line();         
  hitungPID();
  motor_maju();
}
