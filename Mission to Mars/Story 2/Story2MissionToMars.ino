int LED_WHITE = 11;
int LED_RED = 12;
void setup() {
 pinMode(LED_WHITE, OUTPUT);
 pinMode(LED_RED, OUTPUT);
}

void loop() {
  digitalWrite(LED_WHITE, HIGH);
  digitalWrite(LED_RED, LOW);
  delay(1000);
  digitalWrite(LED_WHITE, LOW);
  digitalWrite (LED_RED, HIGH);
  delay(1000);
}
