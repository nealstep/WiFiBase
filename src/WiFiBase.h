#ifndef WIFIBASE_H
#define WIFIBASE_H

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#else
#error "Not supported"
#endif // ESP8266 - ESP32

class WiFiBase {
  public:
  bool init(const char *wifi_ssid, const char *wifi_passwd);
  bool connected(void);
  private:
  const uint16_t connect_delay=500;
  const uint8_t max_attempts = 10;
};

#endif // WIFIBASE_H
