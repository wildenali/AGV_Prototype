void LineFollowerBasic(double output_pid)
{
    SPEED_LEFT  = DEFAULT_SPEED + (int)output_pid;
    SPEED_RIGHT = DEFAULT_SPEED - (int)output_pid;

    // Maximal and Minimal limits SPEED RIGHT
    SPEED_LEFT = SPEED_LEFT <= MIN_SPEED_LEFT ? MIN_SPEED_LEFT : SPEED_LEFT; 
    SPEED_LEFT = SPEED_LEFT >= MAX_SPEED_LEFT ? MAX_SPEED_LEFT : SPEED_LEFT; 

    // Maximal and Minimal limits SPEED RIGHT
    SPEED_RIGHT = SPEED_RIGHT <= MIN_SPEED_RIGHT ? MIN_SPEED_RIGHT : SPEED_RIGHT; 
    SPEED_RIGHT = SPEED_RIGHT >= MAX_SPEED_RIGHT ? MAX_SPEED_RIGHT : SPEED_RIGHT;

    motor_left(SPEED_LEFT, true);
    motor_right(SPEED_RIGHT, true);
}