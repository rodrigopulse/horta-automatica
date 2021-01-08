#include <Arduino.h>
#include <ESP8266WiFi.h>

String led(boolean status) {
  int LED = D5;
  pinMode(LED, OUTPUT);
  if (status) {
    String json = "{\"led\": \"on\"}";
    digitalWrite(LED, HIGH);
    return json;
  } else {
    String off = "off";
    String json = "{\"led\": \"" + off + "\"}";
    digitalWrite(LED, LOW);
    return json;
  }
}
