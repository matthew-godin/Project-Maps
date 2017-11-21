void sensorLoops()
{
  bool a;
  tft.print("START");
  delay(3000);
  tft.setCursor(0, 0);
  sdFile = SD.open("datalog.dat", FILE_READ);
  for (int i = 240; i < 800; ++i)
  {
    for (int j = 160; j <  800; ++j)
    {
      sdFile.read((const uint8_t *)&a, sizeof(a));
    }
    tft.print(a);
      if (i % 300 == 0)
      {
        tft.fillScreen(BLACK);
        tft.setCursor(0, 0);
      }
  }
  sdFile.close();
  tft.print("END");
  delay(3000);
    printPixels();
    frontLoop();
    /*rightLoop();
    rightBackLoop();
    leftBackLoop();
    leftLoop();*/
    printPixels();
}

void frontLoop()
{
    int distance, d, l1;
    bool a;
  
    digitalWrite(TRIG_PIN_FRONT, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_FRONT, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_FRONT, LOW);
    distance = pulseIn(ECHO_PIN_FRONT, HIGH) * 0.034 / 2;
    if (distance <= 300)
    {
      d = distance * 0.8;
      l1 = b * ((400 - d) * 800 + 400);
      sdFile = SD.open("datalog.dat", FILE_WRITE);
      sdFile.seek(l1);
      sdFile.write((const uint8_t *)&a, sizeof(a));
      sdFile.close();
      distance = 160 - d;
      //tft.drawLine(distance, 242, distance, 238, RED);
      //delay(2000);
    }
}

void printPixels()
{
  /*bool a;
  sdFile = SD.open("datalog.dat", FILE_READ);
  for (int i = 240; i < 560; ++i)
  {
    for (int j = 160; j <  640; ++j)
    {
      sdFile.read((char*)&a, sizeof(a));
      tft.print(a);
      tft.print(" ");
      if (j % 300 == 0)
      {
        tft.fillScreen(BLACK);
        tft.setCursor(0, 0);
      }
      if (a)
      {
        tft.drawPixel(i - 240, j - 160, RED);
      }
    }
  }
  sdFile.close();*/
  bool a;
  tft.print("START");
  delay(3000);
  tft.setCursor(0, 0);
  sdFile = SD.open("datalog.dat", FILE_READ);
  for (int i = 240; i < 800; ++i)
  {
    for (int j = 160; j <  800; ++j)
    {
      sdFile.read((const uint8_t *)&a, sizeof(a));
    }
    tft.print(a);
      if (i % 300 == 0)
      {
        tft.fillScreen(BLACK);
        tft.setCursor(0, 0);
      }
  }
  sdFile.close();
  tft.print("END");
}

void rightLoop()
{
    int distance;
  
    digitalWrite(TRIG_PIN_RIGHT, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_RIGHT, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_RIGHT, LOW);
    distance = pulseIn(ECHO_PIN_RIGHT, HIGH) * 0.034 / 2;
    if (distance <= 300)
    {
      distance = 240 - distance * 0.8;
      tft.drawLine(162, distance, 158, distance, RED);
      //delay(2000);
    }
}

void rightBackLoop()
{
    int distance;
  
    digitalWrite(TRIG_PIN_RIGHT_BACK, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_RIGHT_BACK, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_RIGHT_BACK, LOW);
    distance = pulseIn(ECHO_PIN_RIGHT_BACK, HIGH) * 0.034 / 2;
    if (distance <= 300)
    {
      distance = SQRT_2_OVER_2 * 0.8 * distance;
      tft.drawLine(160 + distance - 2, 240 - distance - 2, 160 + distance + 2, 240 - distance + 2, RED);
      //delay(2000);
    }
}

void leftBackLoop()
{
    int distance;
  
    digitalWrite(TRIG_PIN_LEFT_BACK, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_LEFT_BACK, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_LEFT_BACK, LOW);
    distance = pulseIn(ECHO_PIN_LEFT_BACK, HIGH) * 0.034 / 2;
    if (distance <= 300)
    {
      distance = SQRT_2_OVER_2 * 0.8 * distance;
      tft.drawLine(160 + distance + 2, 240 + distance - 2, 160 + distance - 2, 240 + distance + 2, RED);
      //delay(2000);
    }
}

void leftLoop()
{
    int distance;
  
    digitalWrite(TRIG_PIN_LEFT, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_LEFT, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_LEFT, LOW);
    distance = pulseIn(ECHO_PIN_LEFT, HIGH) * 0.034 / 2;
    if (distance <= 300)
    {
      distance = 240 + distance * 0.8;
      tft.drawLine(162, distance, 158, distance, RED);
      //delay(2000);
    }
}
