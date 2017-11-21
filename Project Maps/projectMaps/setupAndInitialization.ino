void gpsSetup()
{
  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  GPS.sendCommand(PGCMD_ANTENNA);
  useInterrupt(true);
  delay(1000);
  mySerial.println(PMTK_Q_RELEASE);
}

void setInitialBeforePopUpFontAndColor()
{
  tft.setTextSize(2);
  tft.setRotation(1);
  tft.setTextColor(BLACK);
}

void setInitialFontAndColor()
{
  tft.setTextColor(WHITE);
  tft.fillScreen(BLACK);
  tft.setRotation(0);
}

void startPopUpScreen()
{
  tft.fillScreen(RED);
  tft.print("\n\n\n\n\n   Welcome to Project Maps Second Demo!");
  tft.drawRect(w / 2 - 100 + 50, h / 2 - 50 + 30, 100, 100, WHITE);
  tft.drawRect(w / 2 - 100 + 50 + 25, h / 2 - 50 + 55, 100, 100, WHITE);
  delay(3000);
}

void screenSetup()
{
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  w = tft.width(), h = tft.height();
}

void touchScreenSetup()
{
  pinMode(13, OUTPUT);
  initializeButtons();
}

void sensorSetup()
{
  Serial.begin(9600);
  pinMode(TRIG_PIN_FRONT, OUTPUT);
  pinMode(ECHO_PIN_FRONT, INPUT);
  pinMode(TRIG_PIN_RIGHT, OUTPUT);
  pinMode(ECHO_PIN_RIGHT, INPUT);
  pinMode(TRIG_PIN_RIGHT_BACK, OUTPUT);
  pinMode(ECHO_PIN_RIGHT_BACK, INPUT);
  pinMode(TRIG_PIN_LEFT_BACK, OUTPUT);
  pinMode(ECHO_PIN_LEFT_BACK, INPUT);
  pinMode(TRIG_PIN_LEFT, OUTPUT);
  pinMode(ECHO_PIN_LEFT, INPUT);
}

