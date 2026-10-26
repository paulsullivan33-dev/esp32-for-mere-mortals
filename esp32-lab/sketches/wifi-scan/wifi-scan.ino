// wifi-scan -- lists the 2.4 GHz
// networks the chip can hear, with
// signal strength and channel.
// The ESP32 hears 2.4 GHz only, so
// the list is honest about that.
#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("scanning...");
  int n = WiFi.scanNetworks();
  Serial.printf("%d networks found\n", n);
  for (int i = 0; i < n; i++) {
    Serial.printf("%d: %s (%d dBm) channel %d\n",
                  i + 1, WiFi.SSID(i).c_str(),
                  WiFi.RSSI(i), WiFi.channel(i));
  }
}

void loop() {
  delay(10000);
}
