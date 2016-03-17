#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include <BlynkSimpleEsp8266.h>

#define EEPROM_STATE_ADDRESS 128
#define EEPROM_STATE_ADDRESS2 144

char auth[] = "blynkkey";
char state = 0;
char state2 = 0;
bool check = true;
bool check2 = true;

WidgetLED led1(V1);
WidgetLED led2(V2);

void updateblynk() {
  if (state == 1) {
    digitalWrite(4, 1);
  }
  else {
    digitalWrite(4, 0);
  }

  if (state2 == 1) {
    digitalWrite(5, 1);
  }
  else {
    digitalWrite(5, 0);
  }
  
}

void setup()
{
  Serial.begin(115200);
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  EEPROM.begin(512);
  state = EEPROM.read(EEPROM_STATE_ADDRESS)==1?1:0; 
  state2 = EEPROM.read(EEPROM_STATE_ADDRESS2)==1?1:0;
  updateblynk();
  Blynk.begin(auth, "SSID", "passw0rd");

}

void loop()
{
  Blynk.run();

  if (digitalRead(4) == HIGH) {
    state = 1;
    if (check == true){
    EEPROM.write(EEPROM_STATE_ADDRESS, state);
    EEPROM.commit();
    Serial.println("EEPROM Write ON 1");
    }
    check = false;
    led1.on(); 
    }
    else{
    state = 0;
    if (check == false){
    EEPROM.write(EEPROM_STATE_ADDRESS, state);
    EEPROM.commit();
    Serial.println("EEPROM Write OFF 1");
    }
    check = true;
    led1.off();
    }
  
  if (digitalRead(5) == HIGH) {
    state2 = 1;
    if (check2 == true){
    EEPROM.write(EEPROM_STATE_ADDRESS2, state2);
    EEPROM.commit();
    Serial.println("EEPROM Write ON 2");
    }
    check2 = false;
    led2.on(); 
    }
    else{
    state2 = 0;
    if (check2 == false){
    EEPROM.write(EEPROM_STATE_ADDRESS2, state2);
    EEPROM.commit();
    Serial.println("EEPROM Write OFF 2");
    }
    check2 = true;
    led2.off();
    }

  }

