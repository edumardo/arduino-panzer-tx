#ifndef DataPaket_h
#define DataPaket_h

#include <Arduino.h>

#define DATAPACKET_SIZE 10                      // DataPacket payload size
#define NRF24_N_INPUTS 6                        // Number of inputs

// Input number in datapacket payload
#define NRF24_LX 0                              // Left joystick, x axis
#define NRF24_LY 1                              // Left joystick, y axis
#define NRF24_LB 2                              // Left joystick, button
#define NRF24_RX 3                              // Right joystick, x axis
#define NRF24_RY 4                              // Right joystick, y axis
#define NRF24_RB 5                              // Right joystick, button

typedef struct dataPacket                       // Datapacket struct with payload array
{
    uint8_t payload[DATAPACKET_SIZE];
} DataPacket;

extern uint8_t inputSize[NRF24_N_INPUTS][2];    // { Input number, size in bytes }

#endif
