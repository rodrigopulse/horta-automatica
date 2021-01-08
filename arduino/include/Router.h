#include <Arduino.h>
#include <Led.h>
#include <Moisture.h>
#include <ReturnJson.h>

void router(WiFiClient client, String request) {
  if (request.indexOf("ledon") != -1) {
    String ledJson = led(true);
    returnJson(client, ledJson);
  }
  if (request.indexOf("ledoff") != -1) {
    String ledJson = led(false);
    returnJson(client, ledJson);
  }
  if (request.indexOf("moistureValor") != -1) {
    String valor = moistureValor(client);
    returnJson(client, valor);
  }
}
