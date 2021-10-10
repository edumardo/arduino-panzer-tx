#include "InputDevices.h"

/**
 *
 */
InputDevices::InputDevices() :
    m_leftJoystick(L_JOYSTICK_X_PIN, L_JOYSTICK_Y_PIN, L_JOYSTICK_BUTTON_PIN, 0, 0, MAX_ANALOG_INPUT),
    m_rightJoystick(R_JOYSTICK_X_PIN, R_JOYSTICK_Y_PIN, R_JOYSTICK_BUTTON_PIN, 0, 0, MAX_ANALOG_INPUT) {

}

/**
 *
 */
void InputDevices::begin() {

    m_leftJoystick.invertYAxis();
    m_rightJoystick.invertYAxis();
}

/**
 *
 */
DataPacket InputDevices::read() {

    m_data.lx = m_leftJoystick.getXValue();
    m_data.ly = m_leftJoystick.getYValue();
    m_data.lb = m_leftJoystick.getbuttonValue();
    m_data.rx = m_rightJoystick.getXValue();
    m_data.ry = m_rightJoystick.getYValue();
    m_data.rb = m_rightJoystick.getbuttonValue();

    return m_data;
}

/**
 *
 */
char * InputDevices::debugString() {

    sprintf(m_debugString, "{lx: %d, ly: %d, lb: %d | rx: %d, ry: %d, rb: %d}",
        m_data.lx, m_data.ly, m_data.lb,
        m_data.rx, m_data.ry, m_data.rb
        );

    return m_debugString;
}
