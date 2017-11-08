/*
This is the first version using both the GPS
and the HCSRO4 sensors at the same time. The
GPS information is only parsed for the moment
as the sensors still show the closest wall.
 */
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

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
#define GPSECHO  true

void sensorLoops();
void frontLoop();
void backLoop();

MCUFRIEND_kbv tft;
HardwareSerial mySerial = Serial1;
Adafruit_GPS GPS(&Serial1);
boolean usingInterrupt = false;
void useInterrupt(boolean);
const int trigPinFront = 31;
const int echoPinFront = 33;
const int trigPinBack = 41;
const int echoPinBack = 43;
int w, h;

void setup() 
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
  tft.fillScreen(RED);
  tft.setTextSize(2);
  tft.setRotation(1);
  tft.setTextColor(BLACK);
  tft.print("\n\n\n\n\n   Welcome to Project Maps Second Demo!");
  tft.drawRect(tft.width() / 2 - 100 + 50, tft.height() / 2 - 50 + 30, 100, 100, WHITE);
  tft.drawRect(tft.width() / 2 - 100 + 50 + 25, tft.height() / 2 - 50 + 55, 100, 100, WHITE);
  delay(3000);
  tft.setTextColor(WHITE);
  tft.fillScreen(BLACK);
  tft.setRotation(0);
  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  GPS.sendCommand(PGCMD_ANTENNA);
  useInterrupt(true);
  delay(1000);
  mySerial.println(PMTK_Q_RELEASE);
}

SIGNAL(TIMER0_COMPA_vect) 
{
  char c = GPS.read();
  #ifdef UDR0
    if (GPSECHO)
      if (c) UDR0 = c;
  #endif
}

void useInterrupt(boolean v) 
{
  if (v) 
  {
    OCR0A = 0xAF;
    TIMSK0 |= _BV(OCIE0A);
    usingInterrupt = true;
  } 
  else 
  {
    TIMSK0 &= ~_BV(OCIE0A);
    usingInterrupt = false;
  }
}

uint32_t timer = millis();

void loop()
{
  tft.fillScreen(BLACK);
  tft.setCursor(0, 0);
  if (!usingInterrupt) 
  {
    char c = GPS.read();
    if (GPSECHO)
    {
      if (c) 
      {
        tft.print(c);
      }
    }
  }
  if (GPS.newNMEAreceived()) 
  {
    if (!GPS.parse(GPS.lastNMEA()))
    {
      return;
    }
  }
  if (timer > millis())  
  {
    timer = millis();
  }
  if (millis() - timer > 2000)
  {
    timer = millis();
    tft.print("\nTime: ");
    tft.print(GPS.hour, DEC); 
    tft.print(':');
    tft.print(GPS.minute, DEC); 
    tft.print(':');
    tft.print(GPS.seconds, DEC); 
    tft.print('.');
    tft.println(GPS.milliseconds);
    tft.print("Date: ");
    tft.print(GPS.day, DEC); 
    tft.print('/');
    tft.print(GPS.month, DEC); 
    tft.print("/20");
    tft.println(GPS.year, DEC);
    tft.print("Fix: "); 
    tft.print((int)GPS.fix);
    tft.print(" quality: "); 
    tft.println((int)GPS.fixquality);
    if (GPS.fix) 
    {
      tft.print("Location: ");
      tft.print(GPS.latitude, 4); 
      tft.print(GPS.lat);
      tft.print(", ");
      tft.print(GPS.longitude, 4); 
      tft.println(GPS.lon);
      tft.print("Speed (knots): "); 
      tft.println(GPS.speed);
      tft.print("Angle: "); 
      tft.println(GPS.angle);
      tft.print("Altitude: "); 
      tft.println(GPS.altitude);
      tft.print("Satellites: "); 
      tft.println((int)GPS.satellites);
    }
  }
  sensorLoops();
  tft.setCursor(0, 0);
  delay(3000);
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
      //delay(2000);
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
      //delay(2000);
    }
}
