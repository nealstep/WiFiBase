#include "WiFiBase.h"

static const char *ssid;
static const char *passwd;

#ifdef ESP8266

bool WiFiBase::init(const char *wifi_ssid, const char *wifi_passwd) {
  uint8_t attempts=0;

  ssid = wifi_ssid;
  passwd = wifi_passwd;
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, passwd);
  while (WiFi.status() != WL_CONNECTED) {
    delay(connect_delay);
    if (++attempts > max_attempts) {
      return false;
    }
  }
  WiFi.setAutoReconnect(true);
  WiFi.persistent(true);
  return true;
}

#endif // ESP8266

#ifdef ESP32

void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info)
{
  WiFi.disconnect(true);  
  WiFi.begin(ssid, passwd);
}

bool WiFiBase::init(const char *wifi_ssid, const char *wifi_passwd) {
  uint8_t attempts=0;

  ssid = wifi_ssid;
  passwd = wifi_passwd;
  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);
  WiFi.onEvent(WiFiStationDisconnected, WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_DISCONNECTED);
  WiFi.begin(ssid, passwd);  
  while (WiFi.status() != WL_CONNECTED) {
    delay(connect_delay);
    if (++attempts > max_attempts) {
      return false;
    }
  }
  return true;
}

#endif // ESP32

bool WiFiBase::connected(void) {
  return WiFi.status() == WL_CONNECTED;
}
