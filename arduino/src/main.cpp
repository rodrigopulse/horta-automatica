#include <Arduino.h>
#include <ESP8266WiFi.h>

const char *ssid = "Che Guevara";
const char *password = "ramona17";

WiFiServer server(80);

// Componentes
int LED = D5;

void setup() {
  // Declara Componentes
  pinMode(LED, OUTPUT);

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

void returnJson(WiFiClient client) {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: application/json");
  client.println("");
  client.println("{\"teste\": \"teste\"}");
  delay(1);
}

void router(String request) {
  if (request.indexOf("ledon") != -1) {
    digitalWrite(LED, HIGH);
  }
  if (request.indexOf("ledoff") != -1) {
    digitalWrite(LED, LOW);
  }
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

  router(request);
  returnJson(client);
}
