#include <ESP8266WiFi.h>
#include <DHT.h>

#define DHTPIN D1
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, HIGH);
}

void loop() {

  digitalWrite(BUILTIN_LED, LOW);

  Serial.print("Temperatura: ");
  Serial.print(dht.readTemperature());
  Serial.print(" *C\t");

  Serial.print("Humedad: ");
  Serial.print(dht.readHumidity());
  Serial.println(" %");

  digitalWrite(BUILTIN_LED, HIGH);

  delay(3000);
}
