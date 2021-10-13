#ifndef InputDevices_h
#define InputDevices_h

#include "config.h"
#include <Joystick.h>
#include "DataPacket.h"

class InputDevices {

    private:
        Joystick m_leftJoystick;
        Joystick m_rightJoystick;
        DataPacket m_data;
        char m_debugString[100];
        void resetData();

    public:
        InputDevices();
        void begin();
        DataPacket * read();
        char * debugString();
};

#endif
