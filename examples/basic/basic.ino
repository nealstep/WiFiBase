#include <MySecrets.h>

#include <WiFiBase.h>

WiFiBase wifiBase;

static const char *ssid = MY_SSID;
static const char *passwd = MY_PASSWD;

static uint16_t delay_loop = 5000;

void setup() {
  Serial.begin(MY_BAUD);
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
  delay(delay_loop);
}
