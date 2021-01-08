#include <Arduino.h>

int valor_analogico;
int pino = A0;

void setup() {
  Serial.begin(115200);
  pinMode(pino, INPUT);
}

void loop() {
  valor_analogico = analogRead(pino);
  Serial.println(valor_analogico);
  delay(100);
}
