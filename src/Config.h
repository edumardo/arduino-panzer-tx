#ifndef Config_h
#define Config_h

#include <Arduino.h>

// General
#define DEBUG_MODE
const uint16_t LOOP_DELAY_MS    =   50;
const uint16_t MAX_ANALOG_INPUT = 1023;
const uint16_t BAUD_RATE        = 9600;


// RF24 pins
const uint8_t RF24_CE_PIN  =  9;
const uint8_t RF24_CSN_PIN = 10;

// RF24 Address
const uint8_t RF24_ADDRESS[6] = "AP-TX";

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
