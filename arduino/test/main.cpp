#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Router.h>

const char *ssid = "Che Guevara";
const char *password = "ramona17";
WiFiServer server(80);

void setup() {
  // Conexão wifi
  Serial.begin(115200);
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("Conectado a rede sem fio ");
  Serial.println(ssid);
  server.begin();
  Serial.println("Servidor iniciado");
  Serial.print("IP para se conectar ao NodeMCU: ");
  Serial.print("http://");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while (!client.available()) {
    delay(1);
  }
  String request = client.readStringUntil('\r');
  client.flush();

  router(client, request);
}
