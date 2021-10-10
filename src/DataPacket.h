#ifndef DataPaket_h
#define DataPaket_h

#include <Arduino.h>

// 32 bytes payload        10
struct DataPacket {
    uint16_t lx;        //  2
    uint16_t ly;        //  2
    bool     lb;        //  1
    uint16_t rx;        //  2
    uint16_t ry;        //  2
    bool     rb;        //  1
};

#endif
