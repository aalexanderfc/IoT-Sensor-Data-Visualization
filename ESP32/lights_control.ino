#include "lights_control.h"

// Inicializar pines de los LEDs
void initLights() {
  // Configurar pines de salida para los LEDs
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // Apagar todas las luces inicialmente
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
}

// Manejar mensajes de control de luces
void handleLightControl(String topic, String payload) {
  Serial.print("Topic: ");
  Serial.println(topic);
  Serial.print("Payload: ");
  Serial.println(payload);

  if (topic == "/home/lights/led1") {
    digitalWrite(LED1_PIN, payload == "ON" ? HIGH : LOW);
  } else if (topic == "/home/lights/led2") {
    digitalWrite(LED2_PIN, payload == "ON" ? HIGH : LOW);
  } else if (topic == "/home/lights/led3") {
    digitalWrite(LED3_PIN, payload == "ON" ? HIGH : LOW);
  } else if (topic == "/home/lights/rgb") {
    StaticJsonDocument<256> doc;
    DeserializationError error = deserializeJson(doc, payload);
    if (error) {
      Serial.println("Error parsing RGB payload.");
      return;
    }
    analogWrite(RED_PIN, doc["red"] | 0);
    analogWrite(GREEN_PIN, doc["green"] | 0);
    analogWrite(BLUE_PIN, doc["blue"] | 0);
  }
}


