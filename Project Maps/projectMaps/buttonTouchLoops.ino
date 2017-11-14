void buttonTouchLoops()
{
  TSPoint p = ts.getPoint();
  pinMode(YP, OUTPUT);
  pinMode(XM, OUTPUT);
  if (p.z > ts.pressureThreshhold) 
  {
     differentButtons(p);
  }
}

void differentButtons(TSPoint &p)
{
  tft.print("X = "); 
     tft.print(p.x);
     tft.print("\tY = "); 
     tft.print(p.y);
  if (p.x >= w - 55 && p.x <= w - 15 && p.y >= 15 && p.y <= 55)
  {
    test = true;
  }
  else test = false;
}

