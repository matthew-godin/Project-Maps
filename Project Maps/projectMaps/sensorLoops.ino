void sensorLoops()
{
    frontLoop();
    rightLoop();
    backLoop();
    leftLoop();
}

const float scaleForCentimeters = 0.08;
const float scaleForMeters = scaleForCentimeters * 100;
const int halfScreenLength = 240;
const int halfScreenHeight = 160;
const int wallLength = 300;
const int minDistance = 100;
const int maxDistance = 300;
int count= 0;
int count_right = 0;
int count_left = 0;
int count_back = 0;

void frontLoop()
{
    int distance, d, l1;
    //uint8_t a = 44;
  
    digitalWrite(TRIG_PIN_FRONT, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_FRONT, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_FRONT, LOW);
    distance = pulseIn(ECHO_PIN_FRONT, HIGH) * 0.034 / 2;
    //tft.fillScreen(BLACK);
    //tft.setCursor(0, 0);
    //tft.print(distance);
    if (distance <= maxDistance && distance >= minDistance && count==0)
    {
      /*d = distance * 0.8;
      l1 = b * ((400 - d) * 800 + 400);
      sdFile = SD.open("datalog.dat", FILE_WRITE);
      sdFile.seek(l1);
      sdFile.write((const uint8_t *)&a, sizeof(a));
      sdFile.close();
      distance = 160 - d;
      tft.fillScreen(RED);
      delay(3000);*/
      distance = 160 - distance * scaleForCentimeters;
      tft.drawLine(distance  + displacementGPS.y * scaleForMeters, halfScreenLength + wallLength + displacementGPS.x * scaleForMeters, distance  + displacementGPS.y * scaleForMeters, halfScreenLength - wallLength + displacementGPS.x * scaleForMeters, RED);
      count = 1;
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
  uint8_t *a = 77;
  *a = 88;
  tft.println("START");
  tft.setCursor(0, 0);
  sdFile = SD.open("datalog.dat", FILE_READ);
  for (int i = 240; i < 800; ++i)
  {
    for (int j = 160; j <  800; ++j)
    {
      sdFile.read((uint8_t *)&a, sizeof(a));
      if (*a == 44)
      {
        tft.fillScreen(BLACK);
        tft.println("SUCESSSSSSSSSS");
        tft.print("i: ");
        tft.println(i);
        tft.print("j: ");
        tft.println(j);
        delay(10000);
        tft.fillScreen(BLACK);
      }
    }
    tft.print(*a);
      if (i % 300 == 0)
      {
        tft.fillScreen(BLACK);
        tft.setCursor(0, 0);
      }
  }
  sdFile.close();
  tft.println("END");
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
    if (distance <= maxDistance && distance >= minDistance && count_right==0)
    {
      distance = distance * scaleForCentimeters;
      tft.println(distance);
      //tft.drawLine(distance  + displacementGPS.y * scaleForMeters, halfScreenLength + wallLength + displacementGPS.x * scaleForMeters, distance  + displacementGPS.y * scaleForMeters, halfScreenLength - wallLength + displacementGPS.x * scaleForMeters, RED);
      tft.drawLine(halfScreenHeight + wallLength + displacementGPS.x * scaleForMeters,halfScreenLength + displacementGPS.y*scaleForMeters - distance, halfScreenHeight - wallLength + displacementGPS.x * scaleForMeters, halfScreenLength + displacementGPS.y*scaleForMeters - distance, RED);
      //tft.drawLine(halfScreenHeight + wallLength, distance, halfScreenHeight - wallLength, distance, RED);
      //delay(2000);
      count_right =1;
    }
}

void backLoop()
{
    int distance;
  
    digitalWrite(TRIG_PIN_RIGHT_BACK, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_RIGHT_BACK, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_RIGHT_BACK, LOW);
    distance = pulseIn(ECHO_PIN_RIGHT_BACK, HIGH) * 0.034 / 2;
    if (distance <= maxDistance  && distance >= minDistance&&count_back==0)
    {
      distance = 160 + distance * scaleForCentimeters;
      tft.drawLine( distance  + displacementGPS.y * scaleForMeters, halfScreenLength + wallLength + displacementGPS.x * scaleForMeters, distance  + displacementGPS.y * scaleForMeters, halfScreenLength - wallLength + displacementGPS.x * scaleForMeters, RED);
      //delay(2000);
      count_back =1;
    }
}

//void leftBackLoop()
//{
//    int distance;
//  
//    digitalWrite(TRIG_PIN_LEFT_BACK, LOW);
//    delayMicroseconds(2);
//    digitalWrite(TRIG_PIN_LEFT_BACK, HIGH);
//    delayMicroseconds(10);
//    digitalWrite(TRIG_PIN_LEFT_BACK, LOW);
//    distance = pulseIn(ECHO_PIN_LEFT_BACK, HIGH) * 0.034 / 2;
//    if (distance <= maxDistance  && distance >= minDistance)
//    {
//      distance = SQRT_2_OVER_2 * scaleForCentimeters * distance;
//      tft.drawLine(halfScreenHeight + distance + wallLength, halfScreenLength + distance - wallLength, halfScreenHeight + distance - wallLength, halfScreenLength + distance + wallLength, RED);
//      //delay(2000);
//    }
//}

void leftLoop()
{
    int distance;
  
    digitalWrite(TRIG_PIN_LEFT, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_LEFT, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_LEFT, LOW);
    distance = pulseIn(ECHO_PIN_LEFT, HIGH) * 0.034 / 2;
    if (distance <= maxDistance  && distance >= minDistance && count_left == 0)
    {
      distance = distance * scaleForCentimeters;
      tft.drawLine(halfScreenHeight + wallLength + displacementGPS.x * scaleForMeters,halfScreenLength + displacementGPS.y*scaleForMeters + distance, halfScreenHeight - wallLength + displacementGPS.x * scaleForMeters, halfScreenLength + displacementGPS.y*scaleForMeters + distance, RED);
      //delay(2000);
      count_left = 1;
    }
}
