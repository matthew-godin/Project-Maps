void gpsLoops()
{
  checkIfGpsNotUsingInterrupt();
  checkIfGpsReceivedNewNMEA();
  checkIfGpsTimerIsGreaterThanMillis();
  checkIfGpsMillisMinusTimerIsGreaterThan2000();
}

void checkIfGpsNotUsingInterrupt()
{
  if (!usingInterrupt)
  {
    ifGpsNotUsingInterrupt();
  }
}

void ifGpsNotUsingInterrupt()
{
  char c = GPS.read();
  if (GPSECHO)
  {
    ifGpsEcho(c);
  }
}

void ifGpsEcho(char c)
{
  if (c)
  {
    tft.print(c);
  }
}

void checkIfGpsReceivedNewNMEA()
{
  if (GPS.newNMEAreceived())
  {
    ifGpsReceivednewNMEA();
  }
}

void ifGpsReceivednewNMEA()
{
  if (!GPS.parse(GPS.lastNMEA()))
  {
    return;
  }
}

void checkIfGpsTimerIsGreaterThanMillis()
{
  if (timer > millis()) 
  {
    timer = millis();
  }
}

void checkIfGpsMillisMinusTimerIsGreaterThan2000()
{
  if (millis() - timer > 2000)
  {
    timer = millis();
    printGpsNonFixInformation();
    if (GPS.fix)
    {
      printGpsFixInformation();
    }
  }
}

void printGpsNonFixInformation()
{
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
}

void printGpsFixInformation()
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

