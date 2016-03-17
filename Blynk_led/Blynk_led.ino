#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include <BlynkSimpleEsp8266.h>

#define EEPROM_STATE_ADDRESS 128

char auth[] = "blynkkey";
char state = 0;

WidgetLED led1(V1);

void setup()
{
  Serial.begin(9600);
  pinMode(5, OUTPUT); 
  Blynk.begin(auth, "SSID", "passw0rd");

}

void loop()
{
  
  Blynk.run();
  
  if (digitalRead(5) == HIGH) {
      led1.on(); 
    }
    else{
      led1.off();
    }
  }

