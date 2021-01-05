#include <Arduino.h>
#include <ReturnJson.h>
void router(WiFiClient client, String request) {
  int LED = D5;
  pinMode(LED, OUTPUT);
  if (request.indexOf("ledon") != -1) {
    String json = "{\"led\": \"on\"}";
    returnJson(client, json);
    digitalWrite(LED, HIGH);
  }
  if (request.indexOf("ledoff") != -1) {
    String json = "{\"led\": \"off\"}";
    returnJson(client, json);
    digitalWrite(LED, LOW);
  }
}
