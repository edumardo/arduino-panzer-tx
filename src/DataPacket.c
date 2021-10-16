#include "DataPacket.h"

// { Input number, size in bytes }
// Total: 10 bytes
uint8_t inputSize[NRF24_N_INPUTS][2] = {
        {NRF24_LX, 2},
        {NRF24_LY, 2},
        {NRF24_LB, 1},
        {NRF24_RX, 2},
        {NRF24_RY, 2},
        {NRF24_RB, 1}
};
