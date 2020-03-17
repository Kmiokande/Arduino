int isObstaclePin = 2;
int ledClear = 3;
int ledObstacle = 4;
int buzzer = 5;
int isObstacle = HIGH;

void setup() {
  pinMode(ledClear, OUTPUT);
  pinMode(ledObstacle, OUTPUT);
  pinMode(isObstaclePin, INPUT);
}

void loop() {
  isObstacle = digitalRead(isObstaclePin);
  
  if (isObstacle == LOW) {
    digitalWrite(ledClear, LOW);
    tone(buzzer, 440);
    digitalWrite(ledObstacle, HIGH);
  }
  else {
    digitalWrite(ledObstacle, LOW);
    noTone(buzzer);
    digitalWrite(ledClear, HIGH);
  }
  
  delay(500);
}
