#define pinOutputPulse 4  //D2
#define pinInputPulse 5  //D1

unsigned long actualTimePulse;
int delayBetweenPulses = 15; //mS
int inputState;
int buttonCounter = 1;

void setup() {
  Serial.begin(115200);
  pinMode(pinOutputPulse, OUTPUT);
  pinMode(pinInputPulse, INPUT);
}

void loop() {
  inputState = digitalRead(5);
  releasePulses();
  if (inputState == 1) {
    if (buttonCounter == 1) {
      Serial.println("BUTTON 1 PRESSED");
      buttonCounter = 1;
    }else if (buttonCounter == 2) {
      Serial.println("BUTTON 2 PRESSED");
      buttonCounter = 2;
    }
  }
}

void releasePulses() {
  if (millis() - actualTimePulse >= delayBetweenPulses) {
    //Serial.println(actualTimePulse);
    if (millis() % 2 == 0) {
      digitalWrite(pinOutputPulse, 1);
      buttonCounter++;
    } else {
      digitalWrite(pinOutputPulse, 0);
    }
    actualTimePulse = millis();
    if (buttonCounter >= 3) {
      buttonCounter = 1;
    }
  }
}
