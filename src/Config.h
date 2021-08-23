#ifndef Config_h
#define Config_h

#include <Arduino.h>

// General
const uint8_t DEBUG_MODE = 1;
const uint16_t LOOP_DELAY_MS = 200;

// RF24 pins
const uint8_t RF24_CE_PIN  =  9;
const uint8_t RF24_CSN_PIN = 10;

// RF24 Address
const uint8_t RF24_ADDRESS[5] = "00001";

// Left joystick pins
const uint8_t  L_JOYSTICK_X_PIN      =  A0;
const uint8_t  L_JOYSTICK_Y_PIN      =  A1;
const uint8_t  L_JOYSTICK_BUTTON_PIN =   2;

// Right joystick pins
const uint8_t  R_JOYSTICK_X_PIN      =  A2;
const uint8_t  R_JOYSTICK_Y_PIN      =  A3;
const uint8_t  R_JOYSTICK_BUTTON_PIN =   4;

// Operation mode
enum operationMode {transmitter, configuration};

#endif
