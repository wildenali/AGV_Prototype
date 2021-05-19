Pixy2 pixy;

void pixy_line_sensor_setup()
{
    pixy.init();
    pixy.setLamp(1,1);
    Serial.println(pixy.changeProg("line"));
}

double pixy_read_line()
{
    // if (pixy.line.numVectors) 
    // {
    //     return pixy_read_line_value = (int32_t)pixy.frameWidth/2 - pixy.line.vectors->m_x1; 
    // }
    if (true)
    {
        return map(analogRead(A0), 0, 1023, -100, 100);
    }
}