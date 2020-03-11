int tilt = 7;
int buzzer = 6;

void setup() {
  pinMode(tilt, INPUT);
}

void loop() {
  if(digitalRead(tilt) == HIGH) {
    tone(buzzer, 440);
    delay(1000);
  }
  else {
    noTone(buzzer);
  }
}
