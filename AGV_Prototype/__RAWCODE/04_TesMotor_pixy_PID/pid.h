unsigned long lastTime;
double PID;
double errSum, lastErr;

double kp = 0.7;     /*4*/  
double ki = 0;
double kd = 0.2;  /*6*/

int lastError;
int Error;
int16_t PIDLeft, PIDRight;

void hitungPID() 
{
/*-----------Cara Baca DATA satu satu si pixycam2-------*/

  if (pixy.line.numVectors) 
      {
        unsigned long now = millis();
        double timeChange = (double)(now - lastTime);        
        Error = (int32_t)pixy.frameWidth/2 - pixy.line.vectors->m_x1;      
        errSum += (Error * timeChange);
        double dErr = (Error - lastErr) / timeChange;
        
        PID = kp * Error + ki * errSum + kd * dErr;
        
        lastErr = Error;                                                          
        lastTime = now;
      }
}
void no_Line()
{
    while (pixy.line.getMainFeatures()<=0)
      {
        analogWrite(enKiri, PIDLeft);
        analogWrite(enKanan, PIDRight);                  
        PIDLeft = 0;
        PIDRight = 0;         
        
//        Serial.print("Kiri ");
//        Serial.print(PIDLeft);    Serial.print("\t");
//        Serial.print("Kanan ");
//        Serial.print(PIDRight);   Serial.print("\n");        
      }
}
void eksekusimotor()
{
        PIDLeft = gas + PID;  /* asline minus*/
        PIDRight = gas - PID;
    
        if(PIDLeft > gas)           {PIDLeft = gas;}
        if(PIDLeft <= 70)          {PIDLeft = 70;}
        if(PIDRight > gas)          {PIDRight = gas;}
        if(PIDRight <= 0)         {PIDRight = 0;}    
   
        analogWrite(enKiri, PIDLeft);
        analogWrite(enKanan, PIDRight); 
}
