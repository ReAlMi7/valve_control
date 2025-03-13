#define CLK 6
#define DT 5
#define SW 4
#include "GyverEncoder.h"
Encoder enc1(CLK, DT, SW);

#include <GyverOLED.h>
GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;

#include <RBD_Timer.h>
RBD::Timer offTime;
RBD::Timer onTime;
uint8_t period = 8;

String sysTray = "Процент открытия";
uint8_t prOK = 0;

#define relay 7 
uint16_t dTime = 50;

#include <EEPROM.h>
#define INIT_ADDR 1023                                                                 
#define INIT_KEY 50                                                                   
struct Data {
  uint8_t prH = 25, prB = 50; float tOn = 77, tOff = 78;
  };
  Data data;

#include "GyverButton.h"
#define pinH 8
#define pinB 9
GButton setH(pinH);
GButton setB(pinB);

/*#include <DallasTemperature.h>
#define ONE_WIRE_BUS 10
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);
float tC = 0;
*/

void setup() {
  Serial.begin(9600);

 // sensor.begin();
  
  if (EEPROM.read(INIT_ADDR) != INIT_KEY) {                                          
    EEPROM.write(INIT_ADDR, INIT_KEY); EEPROM.put(0, data);
  }
  else EEPROM.get(0, data);

  
  oled.init();              
  oled.setScale(1);
  oled.clear();
  oled.update();
  drawScreen();
  
  enc1.setType(TYPE2);
  //enc1.setTickMode(AUTO);  
  enc1.setFastTimeout(40);

  offTime.setTimeout(period * 1000);
  onTime.setTimeout(0);
  offTime.stop(); onTime.stop();
  
  pinMode (relay, OUTPUT);
  digitalWrite(relay, 0);

  pinMode(pinH, INPUT_PULLUP); pinMode(pinB, INPUT_PULLUP);
  setH.setDebounce(100); setH.setTimeout(300); setH.setClickTimeout(600); 
  setB.setDebounce(100); setB.setTimeout(300); setB.setClickTimeout(600); 
  setH.setTickMode(AUTO); setB.setTickMode(AUTO);
 
}

void loop() {
 // getT();
  enc1.tick();
  checkEnc();
  buttonControl();
  relayControl();
  
}
