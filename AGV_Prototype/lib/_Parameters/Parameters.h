// Pin Configuration -------------------------------------------------------------
const int emergency_stop_pin        = 45;
// Pin Configuration -------------------------------------------------------------

// Variable
int pixy_read_line_value;

// Variable for PID
double kp_PID = 2;
double ki_PID = 0;
double kd_PID = 0;

unsigned long currentTime_PID, previousTime_PID;
double setPoint_PID = 0;
double output_PID;
double elapsedTime_PID;
double error_PID;
double lastError_PID;
double cumError_PID, rateError_PID;