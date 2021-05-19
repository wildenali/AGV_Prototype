// Pin Configuration -------------------------------------------------------------
const int emergency_stop_pin        = 45;
const int pwm_left_pin              = 8;
const int pwm_right_pin             = 9;
// Pin Configuration -------------------------------------------------------------

// Variable
int pixy_read_line_value;

// Variable for PID
double kp_PID = 1;
double ki_PID = 0;
double kd_PID = 0;

unsigned long currentTime_PID, previousTime_PID;
double setPoint_PID = 0;
double output_PID;
double elapsedTime_PID;
double error_PID;
double lastError_PID;
double cumError_PID, rateError_PID;

// Variables for Motor
int DEFAULT_SPEED       = 50;       // // units in persen, 0 - 100 persen
int SPEED_LEFT;                     // units in persen
int SPEED_RIGHT;                    // units in persen
int MAX_SPEED_LEFT      = 100;      // units in persen
int MIN_SPEED_LEFT      = 0;        // units in persen
int MAX_SPEED_RIGHT     = 100;      // units in persen
int MIN_SPEED_RIGHT     = 0;        // units in persen