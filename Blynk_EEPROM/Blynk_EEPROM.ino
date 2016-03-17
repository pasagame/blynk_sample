#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include <BlynkSimpleEsp8266.h>

#define epp_adr1 144

char auth[] = "blynkkey";
char state = 0;
bool check = true;

WidgetLED led1(V1);

void blynkUP() {
  if (state == 1) {
    digitalWrite(5, 1);
  }
  else {
    digitalWrite(5, 0);
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(5, OUTPUT); 
  EEPROM.begin(512);
  state = EEPROM.read(epp_adr1)==1?1:0; 
  blynkUP();
  Blynk.begin(auth, "SSID", "passw0rd");

}

void loop()
{
  Blynk.run();
  
  if (digitalRead(5) == HIGH) {
    state = 1;
    if (check == true){
    EEPROM.write(epp_adr1, state);
    EEPROM.commit();
    Serial.println("EEPROM Write ON");
    }
    check = false;
    led1.on(); 
    }
    else{
    state = 0;
    if (check == false){
    EEPROM.write(epp_adr1, state);
    EEPROM.commit();
    Serial.println("EEPROM Write OFF");
    }
    check = true;
    led1.off();
    }

  }

