#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "BlynkKey";

void setup()
{
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  digitalWrite(5, 0);
  Blynk.begin(auth, "SSID", "passw0rd");

}

void loop()
{
  if (Blynk.connected()) {
    digitalWrite(5, 1);  //if connected led=on
    }
    else {
      digitalWrite(5, 0);  //not connect led=off
      }

  Blynk.run();
}
