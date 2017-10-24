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

const int trigPin = 31;
const int echoPin = 33;
long duration;
int distance;
MCUFRIEND_kbv tft;

void setup(void) 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.fillScreen(BLACK);
}

void loop(void) 
{
    unsigned long start, t;
  
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= duration * 0.034 / 2;
    tft.setTextSize(5);
    tft.fillScreen(BLACK);
    tft.print("DISTANCE: ");
    tft.println(distance);
    tft.setCursor(0, 0);
    delay(1000);
}
