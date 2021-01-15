/***************************************************************************
  This is a library for the CCS811 air

  This sketch reads the sensor

  Designed specifically to work with the Adafruit CCS811 breakout
  ----> http://www.adafruit.com/products/3566

  These sensors use I2C to communicate. The device's I2C address is 0x5A

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Dean Miller for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include "Adafruit_CCS811.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F, 16, 2); // Change to (0x27,16,2) for 16x2 LCD.

Adafruit_CCS811 ccs;

int gate=11; 
int indicatorLine=1;

void setup() {
  Serial.begin(9600);
  
  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }

  lcd.init();
  lcd.backlight();

  lcd.print("CO2 ppm  = ");
  lcd.setCursor(0,1);
  lcd.print("TVOC ppm = ");
//  lcd.setCursor(9,0);
//  lcd.write(1);
//  lcd.print("C");
//  lcd.setCursor(13,1);
//  lcd.print("%");

  // Wait for the sensor to be ready
  while(!ccs.available());
  
}

void loop() {
  if(ccs.available()){
    if(!ccs.readData()){
      Serial.print("CO2: ");
      Serial.print(ccs.geteCO2());
      lcd.setCursor(11,0);
      lcd.print(ccs.geteCO2());
      Serial.print("ppm, TVOC: ");
      Serial.println(ccs.getTVOC());
      lcd.setCursor(12,1);
      lcd.print(ccs.getTVOC());

      if(indicatorLine==0){
        lcd.setCursor(15,1);
        lcd.print(" ");
        lcd.setCursor(15,0);
        lcd.print("#");
        indicatorLine=1;
      }
      else {
        lcd.setCursor(15,0);
        lcd.print(" ");
        lcd.setCursor(15,1);
        lcd.print("#");
        indicatorLine=0;
      }
    }
    else{
      Serial.println("ERROR!");
      while(1);
    }
  }
  delay(500);
}
