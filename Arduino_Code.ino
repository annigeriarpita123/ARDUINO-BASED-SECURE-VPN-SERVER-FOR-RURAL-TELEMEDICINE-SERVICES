#include <SoftwareSerial.h>
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#include <LiquidCrystal595.h>       // include the library
LiquidCrystal595 lcd(6, 5, 4);   // datapin, latchpin, clockpin

int HeartRate = 3.0, SpO2 = 3.0;
float glucose_level = 0.0;

#define ONE_WIRE_BUS 10
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float tempC = 0;
float tempF = 0;

#define REPORTING_PERIOD_MS 2000
uint32_t tsLastReport = 0;
PulseOximeter pox;
int LED = 13;
String cdata; 

byte degree[8] =
{
  0b00011,
  0b00011,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte heart[8] =
{
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

//*************************************************************************
void onBeatDetected()
 {
  digitalWrite(LED,!digitalRead(LED));
 }

//*************************************************************************
void setup()
 {
  Serial.begin(9600);
  lcd.begin(16, 2);               // 16 characters, 2 rows
  lcd.setLED2Pin(HIGH);
  lcd.createChar(1, degree);
  lcd.createChar(2, heart);
  lcd.clear();  lcd.home ();
  sensors.begin();
  sensors.setWaitForConversion(false);
  pinMode(LED, OUTPUT);
  lcd.setCursor(0,0); lcd.print("Rural telehealth");
  lcd.setCursor(0,1); lcd.print(" monitoring sys ");
  delay(3000); lcd.clear();

  if(!pox.begin()) {  Serial.println("FAILED");  while(1);  } 
  else {  Serial.println("SUCCESS");  }

  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
  pox.setOnBeatDetectedCallback(onBeatDetected);
//*************************************************************************
void loop()
  {
   pox.update();
   HeartRate = pox.getHeartRate();
   SpO2 = pox.getSpO2();
   
   if(millis() - tsLastReport > REPORTING_PERIOD_MS) 
     {
      if(HeartRate > 0 && SpO2 > 0) {  glucose_level = 16714.61 + 0.47 * HeartRate - 351.045 * SpO2 + 1.85 * (SpO2 * SpO2);  }
      else { glucose_level = 0.0; }

      sensors.requestTemperatures();
      tempC = sensors.getTempCByIndex(0);

      tsLastReport = millis();
      cdata = cdata + HeartRate + "," + SpO2 + "," + tempC + "," + glucose_level; 
      Serial.println(cdata);
      cdata = "";
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.write(2);
      lcd.print(String(":") + HeartRate);
        
      lcd.setCursor(8,0);
      lcd.print("Sp:");
      lcd.print(SpO2);
      lcd.print("%");

      lcd.setCursor(0,1);
      lcd.print("Bg:");
      lcd.print(glucose_level,1);
      lcd.print("mg/dL");
      
      lcd.setCursor(11,1);
      lcd.print(String(" T:") + tempC);
     }
  }

//*************************************************************************
