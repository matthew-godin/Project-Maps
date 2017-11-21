void sensorLoops()
{
    frontLoop();
    rightLoop();
    rightBackLoop();
    leftBackLoop();
    leftLoop();
}

void frontLoop()
{
    int distance;
  
    digitalWrite(TRIG_PIN_FRONT, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_FRONT, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_FRONT, LOW);
    distance = pulseIn(ECHO_PIN_FRONT, HIGH) * 0.034 / 2;
    if (distance <= 300)
    {
      distance = 160 - distance * 0.8;
      tft.drawLine(distance, 242, distance, 238, RED);
      //delay(2000);
    }
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
