/*
Install a virtual wifi terminal on the mobile.
Connect to SRB using password sourabhs.
Use the IP : 192.168.4.1
Port : 1337 
The LED should be connected to GPIO2 of ESP*/

#include <ESP8266WiFi.h>

const char* ssid = "SRB";
const char* password = "sourabhs";
const int ledPin = 2;
WiFiServer server(1337); //1337 is the port

void printWiFiStatus();

void setup(void) {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);

 
  pinMode(ledPin, OUTPUT);

  // Start TCP server.
  server.begin();
   
}

void loop(void) {
  printWiFiStatus();
  
   
  

  WiFiClient client = server.available();
  delay(500);
  

  if (client) {
    Serial.println("Client connected.");

    while (client.connected()) {
      if (client.available()) {
        char command = client.read();
         Serial.print(command);
        if (command == 'H') {
          digitalWrite(ledPin, HIGH);
          Serial.println("\nLED is now on.");
        }
        else if (command == 'L') {
          digitalWrite(ledPin, LOW);
          Serial.println("\nLED is now off.");
        }
      }
    }
    Serial.println("Client disconnected.");
    client.stop();
  }
}

void printWiFiStatus() {
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
