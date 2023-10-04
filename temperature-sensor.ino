#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();  // Initialisez le capteur DHT
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(temperature) & isnan(humidity)) {
    Serial.println("Erreur de lecture du capteur DHT11 !");
  } else {
    Serial.print("Humidité : ");
    Serial.println(humidity);
    Serial.print("%");
    
    Serial.print("Température : ");
    Serial.println(temperature);
    Serial.print(" °C");
  }

  delay(2000);
}
