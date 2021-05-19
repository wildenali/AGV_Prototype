#include "BLEtooth.h"
#include "LoraPin.h"
#include "OLED_display.h"

/*-------------------------------------------------------------------------------------*/ 
void LedOn()
    {
    digitalWrite(LED, HIGH);
    }
void LedOff()
    {
    digitalWrite(LED, LOW);
    }
/*-------------------------------------------------------------------------------------*/    
void setup() 
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT); // Green Led
  
  OLED_setup();
  BLE_setup();
  startupImage();
}

void loop() 
{
  // this flag is used only for writing connected-disconnected on display
  static bool writeConnection=false;    
  if (deviceConnected) 
      {      
      // write connected on display and set a flag
      if (!writeConnection)
          {
            OLED_connect();
            writeConnection=true;
          }
      // data received?
      if (newBuffer)
          {
            LedOn();
            OLED_buffer();
            
            // write back "ok" (+CR+LF) on Bluetooth UART
            uint8_t ok[4]={'O','k',13,10};
            pTxCharacteristic->setValue(ok, 4);
            pTxCharacteristic->notify();
            
            if (/* condition */)
            {
              /* code */
            }
            
            // PERCOBAAN 1 
            Serial.print(String(rxBuffer)); //default rxBuffer=0, jadi harus pakai String untuk tampilkan di Serial
            Serial.println('\n');  

            // reset received command flag and buffer
            newBuffer=false;
            rxBuffer[0]=0;
          }
      delay(500);
      LedOff();
      delay(1000);


	    } // \connected
     else
      {
        // write disconnected on display if there was a previous connection
        if (writeConnection)
            {
              OLED_disconnect();
              startupImage();
              writeConnection=false;
            }  
      }
  BLE_disconnect();
   
} // \loop
