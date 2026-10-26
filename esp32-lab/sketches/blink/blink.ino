// blink -- the baseline sketch.
// Blinks the LED most ESP32 dev boards
// carry on GPIO 2, and reports each
// change on the serial line.
const int LED_PIN = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("workshop node: LED on");
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  Serial.println("workshop node: LED off");
  delay(1000);
}
