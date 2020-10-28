int solenoidPins[] = { 9, 10, 11, 12, 13 };

void setup() {
  setupPins(solenoidPins, 5);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(solenoidPins[i], HIGH);
    delay(200);
    digitalWrite(solenoidPins[i], LOW);
    //delay(50);
  }
}

//set the pins as outputs
void setupPins(int pins[], int lengthOfArray) {
  for (int i = 0; i < lengthOfArray; i++) {
    pinMode(pins[i], OUTPUT);
  }
}
