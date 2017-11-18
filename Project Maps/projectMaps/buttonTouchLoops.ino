void buttonTouchLoops()
{
  TSPoint p = initializeTouchLoop();
  checkIfTouching(p);
}

TSPoint initializeTouchLoop()
{
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  return p;
}

void checkIfTouching(TSPoint p)
{
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE)
  {
    ifTouching(p);
  }
}

void ifTouching(TSPoint p)
{
    p.x = p.x + p.y;       
    p.y = p.x - p.y;            
    p.x = p.x - p.y;
    p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
    p.y = tft.height() - (map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));
    buttonMap(p);
}

void buttonMap(TSPoint p)
{
  if (p.x >= w - 60 && p.x <= w - 10 && p.y >= h / 2 - 50 && p.y <= h / 2 + 50)
  {
    //TOP
  }
  else if (p.x >= 10 && p.x <= 60 && p.y >= h / 2 - 50 && p.y <= h / 2 + 50)
  {
    //BOTTOM
  }
  else if (p.x >= w / 2 - 50 && p.x <= w / 2 + 50 && p.y >= h - 60 && p.y <= h - 10)
  {
    //RIGHT
  }
  else if (p.x >= w / 2 - 50 && p.x <= w / 2 + 50 && p.y >= 10 && p.y <= 60)
  {
    //LEFT
  }
  else if (p.x >= w - 55 && p.x <= w - 15 && p.y >= 65 && p.y <= 105)
  {
    //MINUS
  }
  else if (p.x >= w - 55 && p.x <= w - 15 && p.y >= 15 && p.y <= 55)
  {
    //PLUS
  }
  else if (p.x >= 15 && p.x <= 55 && p.y >= 15 && p.y <= 55)
  {
    //CENTER
  }
}

