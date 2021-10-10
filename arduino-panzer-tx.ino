#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <RF24_config.h>

#include "src/Config.h"
#include "src/InputDevices.h"

RF24 radio(RF24_CE_PIN, RF24_CSN_PIN);
DataPacket * dataPacket;
InputDevices inputDevices;
operationMode opMode = transmitter;

void setup() {

    Serial.begin(BAUD_RATE);

    inputDevices.begin();

    radio.begin();
    radio.openWritingPipe(RF24_ADDRESS);
    radio.setAutoAck(false);
    radio.setDataRate(RF24_250KBPS);
    radio.setPALevel(RF24_PA_LOW);
}

void loop() {

    dataPacket = inputDevices.read();
    if (DEBUG_MODE) {
        Serial.print((int) sizeof(dataPacket), DEC);
        Serial.print("B ");
        Serial.println(inputDevices.debugString());
    }

    // Transmitter mode
    if (opMode == transmitter) {
        radio.write(&dataPacket, sizeof(dataPacket));
    }
    // Configuration mode
    else {
        // lcd and EEPROM ?
    }

    delay(LOOP_DELAY_MS);
}
