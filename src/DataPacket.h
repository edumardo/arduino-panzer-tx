#ifndef DataPaket_h
#define DataPaket_h

#include <Arduino.h>

// DataPacket size
const uint8_t DATAPACKET_SIZE = 6;

// Position in DataPacket array
const uint8_t NRF24_LX = 0;
const uint8_t NRF24_LY = 1;
const uint8_t NRF24_LB = 2;
const uint8_t NRF24_RX = 3;
const uint8_t NRF24_RY = 4;
const uint8_t NRF24_RB = 5;

// DataPacket type
typedef uint8_t DataPacket[DATAPACKET_SIZE];

#endif
