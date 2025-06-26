#include <Arduino.h>

#include "WiFiBase.h"

// passed constants
static const char *ssid = MY_SSID;
static const char *passwd = MY_PASSWD;
static const uint32_t baud = MY_BAUD;

// major classes
WiFiBase wifiBase;

// global constants
static const uint16_t delayMedium = 250;
static const uint16_t delayLong = 1000;
static const uint32_t interval = 30000;

void setup() {
  Serial.begin(baud);
  delay(delayLong*5);
  Serial.println("Starting");
  if (!wifiBase.init(ssid, passwd)) {
    Serial.println("Failed to Connect");
  } else {
    Serial.print("Connected IP: ");
    Serial.println(WiFi.localIP());
  }
}

void loop() {
  Serial.print("Wifi Connected: ");
  Serial.println(wifiBase.connected());
  Serial.print("Connected IP: ");
  Serial.println(WiFi.localIP());
  delay(interval);
}
