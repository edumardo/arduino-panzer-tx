#include "InputDevices.h"

/**
 *
 */
InputDevices::InputDevices() : 
    m_leftJoystick(L_JOYSTICK_X_PIN, L_JOYSTICK_Y_PIN, L_JOYSTICK_BUTTON_PIN, 0, 0, MAX_ANALOG_INPUT),
    m_rightJoystick(R_JOYSTICK_X_PIN, R_JOYSTICK_Y_PIN, R_JOYSTICK_BUTTON_PIN, 0, 0, MAX_ANALOG_INPUT)
{
}

/**
 *
 */
void InputDevices::begin()
{
    m_leftJoystick.invertYAxis();
    m_rightJoystick.invertYAxis();
    resetData();
}

/**
 *
 */
DataPacket InputDevices::read()
{
    int tempValues[NRF24_N_INPUTS];
    tempValues[NRF24_LX] = m_leftJoystick.getXValue();
    tempValues[NRF24_LY] = m_leftJoystick.getYValue();
    tempValues[NRF24_LB] = m_leftJoystick.getbuttonValue();
    tempValues[NRF24_RX] = m_rightJoystick.getXValue();
    tempValues[NRF24_RY] = m_rightJoystick.getYValue();
    tempValues[NRF24_RB] = m_rightJoystick.getbuttonValue();

    int index = 0;
    for (int i = 0; i < NRF24_N_INPUTS; i++)
    {

        if (inputSize[i][1] == 2)
        {
            uint16_t input16t = (uint16_t)tempValues[i];
            m_data.payload[index] = input16t & 0xff;
            m_data.payload[index + 1] = (input16t >> 8);
        }
        else
        {
            uint8_t input8t = (uint8_t)tempValues[i];
            m_data.payload[index] = input8t;
        }
        index += inputSize[i][1];
    }
    return m_data;
}

/**
 *
 */
char *InputDevices::debugString()
{

    int tempValues[NRF24_N_INPUTS];
    int index = 0;

    for (int i = 0; i < NRF24_N_INPUTS; i++)
    {
        if (inputSize[i][1] == 2)
        {
            tempValues[i] = ((uint16_t)m_data.payload[index + 1] << 8) | m_data.payload[index];
        }
        else
        {
            tempValues[i] = (uint8_t)m_data.payload[index];
        }
        index += inputSize[i][1];
    }

    sprintf(m_debugString, "{lx: %d, ly: %d, lb: %d | rx: %d, ry: %d, rb: %d}",
            tempValues[0], tempValues[1], tempValues[2],
            tempValues[3], tempValues[4], tempValues[5]);

    return m_debugString;
}

/**
 *
 */
void InputDevices::resetData()
{
    int index = 0;
    for (int i = 0; i < NRF24_N_INPUTS; i++)
    {

        if (inputSize[i][1] == 2)
        {
            uint16_t input16t = (uint16_t)(MAX_ANALOG_INPUT + 1) / 2;
            m_data.payload[index] = input16t & 0xff;
            m_data.payload[index + 1] = (input16t >> 8);
        }
        else
        {
            m_data.payload[index] = (uint8_t)0;
        }
        index += inputSize[i][1];
    }
}
