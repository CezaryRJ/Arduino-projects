// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
 
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
 
void setup()
{
    // Initialize ASK Object
    rf_driver.init();
    // Setup Serial Monitor
    Serial.begin(9600);
}
 
void loop()
{
 
    uint8_t data;
    uint8_t datalen = sizeof(data);
    // Check if received packet is correct size
    if (rf_driver.recv((uint8_t*)&data, &datalen))
    {
      
      // Message received with valid checksum
      Serial.print("Message Received: ");
      Serial.println(data);         
    }
}
