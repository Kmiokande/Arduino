#include <Ultrasonic.h>

#define TRIGGER_PIN 4
#define ECHO_PIN 5

#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  delay(1000);
}

void loop() {
  robo_frente();
  float dist_cm = distancia();
  Serial.println(dist_cm);

  if(dist_cm < 20) {
    decisao();
  }

  delay(100);
}

float distancia() {
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  return(cmMsec);
  delay(10);
}

void robo_frente() {
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW); // LOW
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW); // LOW
}

void robo_tras() {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void robo_esquerda() {
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void robo_parado() {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
} 

void decisao() {
  robo_parado();
  delay(500);
  robo_tras();
  delay(500);
  robo_esquerda();
  delay(400);
  robo_parado();
  delay(500);
}
