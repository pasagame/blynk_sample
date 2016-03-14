#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "BlynkKey";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "SSID", "passw0rd");

}

void loop()
{
  Blynk.run();
}
