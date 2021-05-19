#include "LoraPin.h"
#include "SSD1306Wire.h"
#include "images.h"
//SSD1306Wire display(0x3c, 21, 22);
SSD1306Wire  display(0x3c, OLED_SDA, OLED_SCL);

void startupImage()
  {
  display.clear();
  display.drawString(45, 0, "SETIYO");
  display.drawXbm(48, 17, 32, 32, bluetooth32_bits);
  display.drawString(24, 54, "Cobain BLUETOOTH");
  display.display();
  }
void OLED_setup()
{
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);  
}
void OLED_connect()
{
  display.clear();
  display.drawString(0, 0, "CONNECTED!");
  display.display();
}
void OLED_disconnect()
{
  display.clear();
  display.drawString(0, 0, "DISCONNECTED!");
  display.display();
  delay(1000);
}
void OLED_buffer()
{
  display.clear();
  display.drawString(0, 0, "Ku Terima Perintahmu:");
  display.drawString(0, 30, String(rxBuffer));
  display.display();
}
