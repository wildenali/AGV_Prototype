void motor_left(int speed_left, bool left_direction)
{
    // Maximal and Minimal SPEED LEFT
    speed_left <= 0     ? 0     : speed_left; 
    speed_left >= 100   ? 100   : speed_left;

    // Convert from SPEED to PWM
    analogWrite(pwm_left_pin,  map(speed_left, 0, 100, 0, 255));
}

void motor_right(int speed_right, bool right_direction)
{
    // Maximal and Minimal SPEED RIGHT
    speed_right <= 0     ? 0     : speed_right; 
    speed_right >= 100   ? 100   : speed_right;
    
    // Convert from SPEED to PWM
    analogWrite(pwm_right_pin, map(speed_right, 0, 100, 0, 255));
}