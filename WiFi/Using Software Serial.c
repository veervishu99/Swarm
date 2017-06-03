#include <SoftwareSerial.h>

SoftwareSerial esp8266(2,3);

boolean alreadyConnected = false;

void setup() {
  
  Serial.begin(115200);
  esp8266.begin(115200); 

  
  pinMode(6,OUTPUT);
  digitalWrite(6,LOW);
}

void loop() {
  String inString = "";  
  if(esp8266.available()) // check if the esp is sending a message 
  {
   if (!alreadyConnected) {
      // clear out the input buffer:
    esp8266.flush();
    Serial.println("We have a new client");
    esp8266.println("Hello, client!");
    alreadyConnected = true;
  }

  if(esp8266.find("+IPD,"))
  {
     delay(10); // wait for the serial buffer to fill up (read all the serial data)

    char temp = esp8266.read();
    
    Serial.println(temp);
    if(temp=='H')
      digitalWrite(6,HIGH); // toggle pin
    if(temp=='L')
      digitalWrite(6,LOW);    

   }
}

}
