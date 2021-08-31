#include "InputDevices.h"

/**
 *
 */
InputDevices::InputDevices() :
    m_leftJoystick(L_JOYSTICK_X_PIN, L_JOYSTICK_Y_PIN, L_JOYSTICK_BUTTON_PIN, 0, 0, 255),
    m_rightJoystick(R_JOYSTICK_X_PIN, R_JOYSTICK_Y_PIN, R_JOYSTICK_BUTTON_PIN, 0, 0, 255) {

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
DataPacket * InputDevices::read() {

    m_data[NRF24_LX] = m_leftJoystick.getXValue();
    m_data[NRF24_LY] = m_leftJoystick.getYValue();
    m_data[NRF24_LB] = m_leftJoystick.getbuttonValue();
    m_data[NRF24_RX] = m_rightJoystick.getXValue();
    m_data[NRF24_RY] = m_rightJoystick.getYValue();
    m_data[NRF24_RB] = m_rightJoystick.getbuttonValue();
    return &m_data;
}

/**
 *
 */
char * InputDevices::debugString() {

    sprintf(m_debugString, "{lx: %d, ly: %d, lb: %d | rx: %d, ry: %d, rb: %d}",
        m_data[NRF24_LX], m_data[NRF24_LY], m_data[NRF24_LB],
        m_data[NRF24_RX], m_data[NRF24_RY], m_data[NRF24_RB]
        );

    return m_debugString;
}
