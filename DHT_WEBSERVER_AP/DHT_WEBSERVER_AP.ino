#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ESP8266mDNS.h>

//Definimos el sensor de temperatura
#define DHTPIN D1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Password del Access Point
const char WiFiAPPSK[] = "sistemaspumas";
//Inicializar el servidor
WiFiServer server(80);

void setup()
{
  initHardware();
  setupWiFi();
  server.begin();
}

void loop()
{
  // Preguntar si un cliente se ha conectado
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Leemos la primera linea de la peticion
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  // Definir la accion deseada
  int val = -1; // variable del caso a ejecutar
  if (req.indexOf("/led/0") != -1)
    val = 0; // Encendera el LED
  else if (req.indexOf("/led/1") != -1)
    val = 1; // Apagara el LED
  else if (req.indexOf("/sensor/0") != -1)
    val = -2; // Mostrara la temperatura y humedad

  // Enciende o apaga el LED
  if (val >= 0)
    digitalWrite(LED_BUILTIN, val);

  client.flush();

  // Prepara la respuesta HTTP
  String s = "HTTP/1.1 200 OK\r\n";
  s += "Content-Type: text/html\r\n\r\n";
  s += "<!DOCTYPE HTML>\r\n<html>\r\n";
  s += "<head>\r\n";
  s += "<meta http-equiv='refresh' content='5'/>\r\n";
  s += "<title>Facultad de Sistemas</title>\r\n";
  s += "<style>";
  s += "body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }";
  s += "</style>";
  s += "</head>";

  // Si cambio el estado de el LED, da una pagina que avise.
  if (val >= 0)
  {
    s += "El LED esta ";
    s += (val) ? "apagado" : "encendido";
  }
  else if (val == -2)
  { // Escribe los datos del sensor
    s += "Temperatura = ";
    s += String(dht.readTemperature());
    s += "*C\t";
    s += "<br>"; // Go to the next line.
    s += "Humedad = ";
    s += String(dht.readHumidity());
    s += " %";
  }
  else
  {
    s += "Peticion Invalida.<br> Intenta enviar /led/1, /led/0, o /sensor/0.";
  }
  s += "</html>\n";

  // Envia la respuesta al cliente
  client.print(s);
  delay(1);
  Serial.println("Cliente desconectado");
}

void setupWiFi()
{
  WiFi.mode(WIFI_AP);
  uint8_t mac[WL_MAC_ADDR_LENGTH];
  WiFi.softAPmacAddress(mac);
  WiFi.softAP("Sistemas IoT", WiFiAPPSK);
  if (!MDNS.begin("sistemas")) {
    Serial.println("Error al inicializar el servidor mDNS");
    while (1) {
      delay(1000);
    }
  }
  Serial.println("El servidor mDNS inicio correctamente");
  MDNS.addService("http", "tcp", 80);
}

void initHardware()
{
  Serial.begin(115200);
  dht.begin();
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, HIGH);
}
