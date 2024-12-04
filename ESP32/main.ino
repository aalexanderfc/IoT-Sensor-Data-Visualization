#include "secret.h"  // Innehåller AWS-certifikat och WiFi-uppgifter
#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"
#include <time.h>
#include "DHT.h"
#include "lights_control.h"
// AWS IoT ämnen
#define AWS_IOT_PUBLISH_TOPIC "/telemetry"
#define AWS_IOT_SUBSCRIBE_TOPIC "/downlink"
#define AWS_IOT_LIGHTS_TOPIC "/home/lights/#"

// DHT11-inställningar
#define DHTPIN 25
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

WiFiClientSecure net;
MQTTClient client(1024);

String THINGNAME = "";

// Anslut till WiFi och AWS IoT Core
void connectAWS() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  // Dynamiskt Thing Name baserat på MAC-adress
  THINGNAME = WiFi.macAddress();
  THINGNAME.replace(":", ""); // Ta bort kolon för att matcha AWS IoT-standard

  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

  // AWS IoT certifikat
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  // Anslut till AWS IoT MQTT-broker
  client.begin(AWS_IOT_ENDPOINT, 8883, net);
  client.onMessage(messageHandler);

  Serial.print("Connecting to AWS IoT...");
  while (!client.connect(THINGNAME.c_str())) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to AWS IoT!");

  // Prenumerera på downlink
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
}

// Hämta ISO 8601 tidsstämpel
String getISO8601Timestamp() {
  time_t now;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return "";
  }
  char buf[25];
  strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M:%SZ", &timeinfo);
  Serial.print("Generated timestamp: ");
  Serial.println(buf);
  return String(buf);
}

unsigned long long getNanosecondsSinceEpoch() {
  struct timeval tv;
  gettimeofday(&tv, NULL); // Hämtar tid i sekunder och mikrosekunder
  return (unsigned long long)tv.tv_sec * 1e9 + (unsigned long long)tv.tv_usec * 1e3; // Konverterar till nanosekunder
}


// Publicera telemetri till AWS IoT
void publishTelemetry(float temperature, float humidity) {
  StaticJsonDocument<512> telemetry;
  telemetry["deviceId"] = THINGNAME;
  telemetry["temperature"] = temperature;
  telemetry["humidity"] = humidity;
  telemetry["timestamp"] = getISO8601Timestamp(); // Skicka ISO 8601-format

  char buffer[512];
  serializeJson(telemetry, buffer);

  Serial.println("Telemetry payload to be sent:");
  Serial.println(buffer);

  client.publish(AWS_IOT_PUBLISH_TOPIC, buffer);
  Serial.println("Published telemetry.");
}

// Hantera inkommande meddelanden
void messageHandler(String &topic, String &payload) {
  Serial.println("Incoming message: " + topic + " - " + payload);

  // Controlar datos del sensor (DHT11)
  if (topic == AWS_IOT_SUBSCRIBE_TOPIC) {
    StaticJsonDocument<256> doc;
    DeserializationError error = deserializeJson(doc, payload);
    if (error) {
      Serial.print("Failed to parse JSON: ");
      Serial.println(error.c_str());
      return;
    }
    if (doc["sendInterval"]) {
      int newInterval = doc["sendInterval"];
      Serial.print("Updated send interval to: ");
      Serial.println(newInterval);
    }
  }

  // Controlar las luces
  if (topic.startsWith("/home/lights/")) { // Verificar si el mensaje es para las luces
    handleLightControl(topic, payload);    // Llama a la función para manejar luces
  }
}


void setup() {
  Serial.begin(115200);
  dht.begin();
  connectAWS();

  // Synkronisera tid
 configTime(3600, 3600, "pool.ntp.org", "time.nist.gov");
  Serial.println("Waiting for time sync...");
  struct tm timeinfo;
  while (!getLocalTime(&timeinfo)) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nTime synchronized!");
}

void loop() {
  client.loop();

  static unsigned long lastTelemetry = 0;
  if (millis() - lastTelemetry > 10000) { // Skickar data var 10:e sekund
    lastTelemetry = millis();

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    publishTelemetry(temperature, humidity);
  }
}
