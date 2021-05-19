/*
Bluetooth UART Rx/Tx example with Wemos Lolin 32 + Oled display
Example derived from Examples->ESP32 BLE Arduino->BLE_uart
(c) Giovanni Bernardo
https://www.settorezero.com
    
Video: https://www.youtube.com/watch?v=oCMOYS71NIU
Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleNotify.cpp
Ported to Arduino ESP32 by Evandro Copercini

Create a BLE server that, once we receive a connection, will send periodic notifications.
The service advertises itself as: 6E400001-B5A3-F393-E0A9-E50E24DCCA9E
Has a characteristic of: 6E400002-B5A3-F393-E0A9-E50E24DCCA9E - used for receiving data with "WRITE" 
Has a characteristic of: 6E400003-B5A3-F393-E0A9-E50E24DCCA9E - used to send data with  "NOTIFY"

The design of creating the BLE server is:
1. Create a BLE Server
2. Create a BLE Service
3. Create a BLE Characteristic on the Service
4. Create a BLE Descriptor on the characteristic
5. Start the service.
6. Start advertising.
*/

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/
#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" // UART service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

BLEServer *pServer = NULL;
BLECharacteristic * pTxCharacteristic;
bool deviceConnected = false;
bool oldDeviceConnected = false;

#define BUFFER_LENGTH 20
char rxBuffer[BUFFER_LENGTH];
bool newBuffer=false;

class MyServerCallbacks: public BLEServerCallbacks 
      {
        void onConnect(BLEServer* pServer) 
            {
              deviceConnected = true;
            };
        void onDisconnect(BLEServer* pServer) 
            {
              deviceConnected = false;
            }
      };
class MyCallbacks: public BLECharacteristicCallbacks 
      {
        void onWrite(BLECharacteristic *pCharacteristic) 
            {
              std::string rxValue = pCharacteristic->getValue();
              if (rxValue.length() > 0) 
                  {
                    // transfer data received into a buffer
                    for (int i = 0; i < rxValue.length(); i++)
                        {
                          rxBuffer[i]=rxValue[i];
                          // new line received or : end of string
                          if (rxValue[i]==10 || rxValue[i]==13 || i==BUFFER_LENGTH-1)
                              {
                                if (i!=0)
                                    {
                                      newBuffer=true;          
                                    }
                                rxBuffer[i]=0;
                              }
                        }
                  }
            }
      };
void BLE_setup()
{
    // Create the BLE Device
  BLEDevice::init("LoRa_Setiyoo");

  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pTxCharacteristic = pService->createCharacteristic
                    (
                      CHARACTERISTIC_UUID_TX,
                      BLECharacteristic::PROPERTY_NOTIFY
                    );
                      
  pTxCharacteristic->addDescriptor(new BLE2902());

  BLECharacteristic * pRxCharacteristic = pService->createCharacteristic
                    (
                      CHARACTERISTIC_UUID_RX,
                      BLECharacteristic::PROPERTY_WRITE
                    );

  pRxCharacteristic->setCallbacks(new MyCallbacks());

  // Start the service
  pService->start();

  // Start advertising
  pServer->getAdvertising()->start();
}
void BLE_disconnect()
{
      // disconnecting
    if (!deviceConnected && oldDeviceConnected) 
        {
          delay(500); // give the bluetooth stack the chance to get things ready
          pServer->startAdvertising(); // restart advertising
          oldDeviceConnected = deviceConnected;
        } // \disconnecting
    
    // connecting
    if (deviceConnected && !oldDeviceConnected) 
        {
          // do stuff here on connecting
          oldDeviceConnected = deviceConnected;
        } // \connecting
}
