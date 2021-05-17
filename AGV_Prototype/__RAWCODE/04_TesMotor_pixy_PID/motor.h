// Motor A connections
int enKiri = 8;
int in1 = 4;
int in2 = 5;
// Motor B connections
int enKanan = 9;
int in3 = 6;
int in4 = 7;
float gas = 70;

void motor_maju() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
//  analogWrite(enA, 70); //kiri normal max 255
//  analogWrite(enB, 70); //kanan

  analogWrite(enKiri, gas); //kiri normal max 255
  analogWrite(enKanan, gas); //kanan
  
  // Turn on motor A & B
  digitalWrite(in1, HIGH); //kiri
  digitalWrite(in2, LOW);
  
  digitalWrite(in3, HIGH); //kanan
  digitalWrite(in4, LOW);
}
