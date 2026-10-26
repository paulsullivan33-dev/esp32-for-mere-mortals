// json-reading -- formats one sensor
// reading as a line of JSON, using the
// ArduinoJson library, the way a small
// sensor node would report itself.
// The lab compiles this without a
// sensor attached, so the temperature
// is simulated: a slow wave standing
// in for a workshop warming and cooling.
#include <ArduinoJson.h>

float fakeTemperature() {
  return 21.0f + 2.0f * sin(millis() / 60000.0f);
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  float t = floor(fakeTemperature() * 10) / 10.0f;

  JsonDocument doc;
  doc["sensor"] = "workshop-north-wall";
  doc["temp_c"] = t;
  doc["uptime_s"] = millis() / 1000;

  serializeJson(doc, Serial);
  Serial.println();
  delay(5000);
}
