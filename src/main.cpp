/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x64 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <M5Unified.h>

#include "earthunit.h"

M5GFX display;
M5Canvas canvas(&display);

void setup() {
  Serial.begin(115200);

  display.begin();
  display.setRotation(1);
  display.fillScreen(TFT_BLACK);
  
  canvas.createSprite(display.width(), display.height());

}

void loop() {
  // print the number of seconds since reset:
    M5.update();

  canvas.fillSprite(BLACK);
  canvas.setTextFont(2);
  canvas.setFont(&fonts::lgfxJapanGothicP_16);
  canvas.setCursor(10, 0);
  canvas.print("Moisture Check");
  canvas.setFont(&fonts::lgfxJapanGothicP_24);
  canvas.setCursor(10, 25);
  canvas.print("水分 ");
  canvas.print(EarthUnit::getData());

  // Only the following process is actually drawn on the panel.
  display.startWrite(); 
  canvas.pushSprite(0, 0);
  display.endWrite();

  delay(1000);

}
