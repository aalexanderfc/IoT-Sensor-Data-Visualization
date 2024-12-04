#ifndef LIGHTS_CONTROL_H
#define LIGHTS_CONTROL_H

#include <Arduino.h>
#include <ArduinoJson.h>

// Pines para LEDs
#define LED1_PIN 26
#define LED2_PIN 27
#define LED3_PIN 14
#define RED_PIN 18
#define GREEN_PIN 19
#define BLUE_PIN 21

// Declaración de funciones
void initLights();
void handleLightControl(String topic, String payload);

#endif
