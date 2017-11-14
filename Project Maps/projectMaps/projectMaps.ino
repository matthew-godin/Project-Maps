/*
*************************************
* This is Project Maps Source Code! *
*************************************

Please read this code carefully and
use it as you wish on your Arduino
Mega 2560 with Adafruit Ultimate GPS,
HCSR04 sensors, tft touch screen,
MPU6050 accelerometer and SD card
reader. This is not a release version.
 */
#include "projectMaps.h"

MCUFRIEND_kbv tft;
HardwareSerial mySerial = Serial1;
Adafruit_GPS GPS(&Serial1);
boolean usingInterrupt = false;
void useInterrupt(boolean);
uint32_t timer = millis();
int w, h;

void setup()
{
  sensorSetup();
  screenSetup();
  startPopUpScreen();
  setInitialFontAndColor();
  gpsSetup();
}

void loop()
{
  loopInit();
  gpsLoops();
  sensorLoops();
  loopEnd();
}
