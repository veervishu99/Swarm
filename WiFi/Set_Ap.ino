/*
 *
 *	Make an Access Point
 *
 */

#include <ESP8266_TCP.h>

// ESP8266 Class
ESP8266_TCP wifi;

// Define SSID, Password and Channel that provide for Access Point
#define ssid         "ESP_AP"
#define pass         "123456789"
#define channel      5

// Connect this pin to CH_PD pin on ESP8266
#define PIN_RESET    6	

void setup()
{
  delay(3000);
  
  
   Serial.begin(115200);
   wifi.begin(&Serial, PIN_RESET);
  
  
  // Check that ESP8266 is available
  if(wifi.test()) 
  {
	// Open Access Point (WiFi Hotspot) 
    wifi.openAccessPoint(ssid, pass, channel);
  } 
  else 
  {
	// ESP8266 isn't available
    Serial.println("Check module connection and restart to try again..."); 
  }
}

void loop()
{

}
