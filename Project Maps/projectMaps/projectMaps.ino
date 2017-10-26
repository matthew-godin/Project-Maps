/*
This is the very first version of Project Maps, we intend
to include minimal functionality to show a generated map on 
a fixed point without gps coordinates yet.
 */
#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>
#include <MCUFRIEND_kbv.h>

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

void sensorLoops();
void frontLoop();
void backLoop();

const int trigPinFront = 31;
const int echoPinFront = 33;
const int trigPinBack = 41;
const int echoPinBack = 43;
int w, h;
MCUFRIEND_kbv tft;

void setup(void) 
{
  Serial.begin(9600);
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);
  pinMode(trigPinBack, OUTPUT);
  pinMode(echoPinBack, INPUT);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  w = tft.width(), h = tft.height();
  tft.fillScreen(BLUE);
  tft.setTextSize(2);
  tft.setRotation(1);
  tft.setTextColor(WHITE);
  tft.print("\n\n\n\n\n   Welcome to Project Maps First Demo!");
  tft.drawRect(tft.width() / 2 - 100 + 50, tft.height() / 2 - 50 + 30, 100, 100, WHITE);
  tft.drawRect(tft.width() / 2 - 100 + 50 + 25, tft.height() / 2 - 50 + 55, 100, 100, WHITE);
  delay(3000);
  tft.fillScreen(BLACK);
  tft.setRotation(0);
}

void loop(void) 
{
    sensorLoops();
    tft.setCursor(0, 0);
    delay(1000);
}

void sensorLoops()
{
    frontLoop();
    backLoop();
}

void frontLoop()
{
    int distance;
  
    digitalWrite(trigPinFront, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinFront, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinFront, LOW);
    distance = pulseIn(echoPinFront, HIGH) * 0.034 / 2;
    if (distance <= 300)
    {
      distance = 160 - distance * 0.8;
      tft.drawLine(distance, 242, distance, 238, RED);
      delay(2000);
    }
}

void backLoop()
{
    int distance;
  
    digitalWrite(trigPinBack, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinBack, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinBack, LOW);
    distance = pulseIn(echoPinBack, HIGH) * 0.034 / 2;
    if (distance <= 300)
    {
      distance = 160 + distance * 0.8;
      tft.drawLine(distance, 242, distance, 238, RED);
      delay(2000);
    }
}
