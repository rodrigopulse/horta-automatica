#include <Arduino.h>
#include <ESP8266WiFi.h>

const char *ssid = "Che Guevara";
const char *password = "ramona17";

WiFiServer server(80);

// Componentes
int LED = D5;

void setup()
{
  // Declara Componentes
  pinMode(LED, OUTPUT);

  Serial.begin(115200);
  delay(10);

  Serial.println("");
  Serial.println("");
  Serial.print("Conectando a ");
  Serial.print(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Conectado a rede sem fio ");
  Serial.println(ssid);

  server.begin();
  Serial.println("Servidor iniciado");

  Serial.print("IP para se conectar ao NodeMCU: ");
  Serial.print("http://");
  Serial.println(WiFi.localIP());
}

void loop()
{
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  Serial.println("Novo cliente se conectou!");
  while (!client.available())
  {
    delay(1);
  }
  String request = client.readStringUntil('\r');

  client.flush();
  if (request.indexOf("ledon") != -1)
  {
    digitalWrite(LED, HIGH);
  }
  if (request.indexOf("ledoff") != -1)
  {
    digitalWrite(LED, LOW);
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: application/json");
  client.println("");
  client.println("{\"teste\": \"teste\"}");
  delay(1);
}