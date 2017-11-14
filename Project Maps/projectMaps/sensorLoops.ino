void sensorLoops()
{
    frontLoop();
    backLoop();
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

void backLoop()
{
    int distance;
  
    digitalWrite(TRIG_PIN_BACK, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_BACK, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_BACK, LOW);
    distance = pulseIn(ECHO_PIN_BACK, HIGH) * 0.034 / 2;
    if (distance <= 300)
    {
      distance = 160 + distance * 0.8;
      tft.drawLine(distance, 242, distance, 238, RED);
      //delay(2000);
    }
}
