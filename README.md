# Solenoid Driver Build Notes 1/26/20

This project is in partnership with [Bantam Tools](https://www.bantamtools.com)

**Design Notes:**

Each 12v solenoid has a 1N4001 diode in parallel with its positive/negative leads, serving as a flyback diode.  The TIP120s serve as switches with signals being directed via an external microcontroller through a 2.2k resistor.

The board is broken up into two sides, with the Arduino signals coming in on one side, and the solenoids being actuated on the other, indicated by an A (Arduino) and an S (Solenoid) in each of the two rows.  External power (12v) enters through a screw terminal on the side of the board.  Polarity is indicated with +/- symbols next to the screw terminals where applicable.  Solenoids are non-polar and so can be oriented any way.  Each Arduino screw terminal port is identical with the exception of one which is required for ground (as indicated by a ‘-‘ symbol).  Arduino signal pins can be any digital pin.

# Build Process
**Bit:** 1/32”
**Mill Time:** <10mins

It’s easiest to solder in this order:
```
1. Resistors
2. Diodes
3. Screw Terminals
4. TIP120s
5. Install heatsinks
```


Test - Sample Code (also within directory)

```
int solenoidPins[] = { 9, 10, 11, 12, 13 };
void setup() {
  setupPins(solenoidPins, 5);
}
void loop() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(solenoidPins[i], HIGH);
	delay(80);
    digitalWrite(solenoidPins[i], LOW);
	delay(80);
  }
}
//set the pins as outputs
void setupPins(int pins[], int lengthOfArray) {
  for (int i = 0; i < lengthOfArray; i++) {
	pinMode(pins[i], OUTPUT);
  }
}
```
