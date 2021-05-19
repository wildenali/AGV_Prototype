double hitung_PID(double inp);

double hitung_PID(double inp){     
  currentTime_PID = millis();                                 //get current time
  elapsedTime_PID = (double)(currentTime_PID - previousTime_PID);     //compute time elapsed from previous computation
  
  error_PID = inp - setPoint_PID;                                 // determine error_PID
  cumError_PID += error_PID * elapsedTime_PID;                        // compute integral
  rateError_PID = (error_PID - lastError_PID)/elapsedTime_PID;            // compute derivative

  double out = kp_PID*error_PID + ki_PID*cumError_PID + kd_PID*rateError_PID;     //PID output_PID               

  lastError_PID = error_PID;                                      //remember current error_PID
  previousTime_PID = currentTime_PID;                             //remember current time

  return out;                                             //have function return the PID output_PID
}
