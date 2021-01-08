#include <Arduino.h>
#include <ESP8266WiFi.h>

String moistureValor(WiFiClient client) {
  int moistureSensor = A0;
  pinMode(moistureSensor, INPUT);
  int moistureValor = analogRead(moistureSensor);
  String moitureValorString = String(moistureValor);
  String json = "{\"moisture\": \"" + moitureValorString + "\"}";
  return json;
};
