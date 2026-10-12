// Temperature Sensor - DHT11 -> JSON over Serial
// Sends {"h":..,"t":..} every 2 seconds
// Web page (temperature.html) reads via Web Serial API

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  while (!Serial) { ; }
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("{\"error\":\"DHT11 read failed\"}"));
  } else {
    Serial.print(F("{\"h\":"));
    Serial.print(h, 1);
    Serial.print(F(",\"t\":"));
    Serial.print(t, 1);
    Serial.println(F("}"));
  }
  delay(2000);
}
