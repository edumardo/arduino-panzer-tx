#ifndef DataPaket_h
#define DataPaket_h

#include <Arduino.h>

struct DataPacket {
    uint8_t lx;
    uint8_t ly;
    bool    lb;
    uint8_t rx;
    uint8_t ry;
    bool    rb;
};

#endif
