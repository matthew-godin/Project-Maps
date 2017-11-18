#ifndef DEF_PROJECTMAPS
#define DEF_PROJECTMAPS

#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>
#include <MCUFRIEND_kbv.h>

#include <TouchScreen.h>

#if defined(__SAM3X8E__)
    #undef __FlashStringHelper::F(string_literal)
    #define F(string_literal) string_literal
#endif
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define RANDOM_COLOR 0xFED4
#define GPSECHO  true
#define TRIG_PIN_FRONT 31
#define ECHO_PIN_FRONT 33
#define TRIG_PIN_BACK 41
#define ECHO_PIN_BACK 43
#define YP A2
#define XM A3
#define YM 8
#define XP 9
#define TS_MINX 130
#define TS_MAXX 905
#define TS_MINY 75
#define TS_MAXY 930
#define MINPRESSURE 10
#define MAXPRESSURE 1000

typedef struct Position
{
  double x;
  double y;
} Position;

void sensorSetup();
void screenSetup();
void gpsSetup();
void startPopUpScreen();
void setInitialFontAndColor();
void sensorLoops();
void frontLoop();
void backLoop();
SIGNAL(TIMER0_COMPA_vect);
void useInterrupt(boolean v);
void checkGpsEcho(char c);
void checkGpsC(char c);
void useInterrupt(boolean v);
void ifGpsV();
void ifNotGpsV();
void gpsLoops();
void checkIfGpsNotUsingInterrupt();
void checkIfGpsReceivedNewNMEA();
void checkIfGpsTimerIsGreaterThanMillis();
void checkIfGpsMillisMinusTimerIsGreaterThan2000();
void ifGpsNotUsingInterrupt();
void ifGpsEcho(char c);
void ifGpsReceivednewNMEA();
void printGpsNonFixInformation();
void printGpsFixInformation();
void firstGpsFix();
void buttonDrawLoops();
void setInitialBeforePopUpFontAndColor();
void buttonTouchLoops();
TSPoint initializeTouchLoop();
void checkIfTouching(TSPoint p);
void ifTouching(TSPoint p);
void touchScreenSetup();
void buttonMap(TSPoint p);

#endif
