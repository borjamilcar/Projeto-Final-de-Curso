// ================================================================================
// MIT License
// https://github.com/gonzalocasas/arduino-uno-dragino-lorawan/blob/master/LICENSE
// Based on examples from https://github.com/matthijskooijman/arduino-lmic
// Copyright (c) 2015 Thomas Telkamp and Matthijs Kooijman
// ================================================================================
//        ENVIO DE LEITURA DE TEMPERATURA E HUMIDADE PARA A TTN POR ABP
//                            FEITO POT AMILCAR BORJA
// --------------------------------------------------------------------------------
// BIBLIOTECAS ------ DHT, LMIC
// SENSOR ----------- DHT11
// TEMPO DE LEITURA - 5 MINUTOS
// ATENÇÃO: Sketch para o Dragino SX1276/SX1277/SX1278/SX1279 radio
// e HopeRF RFM95 boards
// ================================================================================

#include <lmic.h>
#include <hal/hal.h>

/*************************************
* NwkSKey: network session key
* AppSKey: application session key
* DevAddr: end-device address
**************************************/
static const u1_t NWKSKEY[16] = { 0x1C, 0xDF, 0x03, 0x74, 0xC7, 0x0E, 0x12, 0x23, 0xDA, 0x7E, 0xEA, 0x0E, 0x62, 0xAF, 0x57, 0x40 };
static const u1_t APPSKEY[16] = { 0x17, 0xFE, 0x09, 0xF0, 0x80, 0x57, 0x79, 0x5D, 0x4A, 0x6D, 0x8B, 0x43, 0x30, 0x09, 0x73, 0x79 };
static const u4_t DEVADDR = 0x26011056;

// These callbacks are only used in over-the-air activation, so they are
// left empty here (we cannot leave them out completely unless
// DISABLE_JOIN is set in config.h, otherwise the linker will complain).
void os_getArtEui (u1_t* buf) { }
void os_getDevEui (u1_t* buf) { }
void os_getDevKey (u1_t* buf) { }

// 
static osjob_t sendjob;


// Schedule TX every this many seconds (might become longer due to duty
// cycle limitations).
const unsigned TX_INTERVAL = 60;


// Pin mapping
const lmic_pinmap lmic_pins = {
    .nss = 10,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 9,
    .dio = {2, 6, 7},
};


// This callback function may react on certain events and trigger new actions
// based on the event and the LMIC state. In this case (ABP), the EV_TXCOMPLETE
// is the only one which is lauch
void onEvent (ev_t ev) {
    if (ev == EV_TXCOMPLETE) {
      Serial.println(F("EV_TXCOMPLETE (includes waiting for RX windows)"));
      // Schedule next transmission
      os_setTimedCallback(&sendjob, os_getTime()+sec2osticks(TX_INTERVAL), do_send);
    }
}


void do_send(osjob_t* j){
    // Payload to send (uplink)
    static uint8_t message[] = "hi";
  
    // Check if there is not a current TX/RX job running
    if (LMIC.opmode & OP_TXRXPEND) {
      Serial.println(F("OP_TXRXPEND, not sending"));
    } else {
      // Prepare upstream data transmission at the next possible time.
      LMIC_setTxData2(1, message, sizeof(message)-1, 0);
      Serial.println(F("Sending uplink packet..."));
      Serial.print("LMIC.freq: ");
      Serial.println(LMIC.freq); 
      Serial.print("LMIC.txCnt: ");
      Serial.println(LMIC.txCnt);
      Serial.print("LMIC.seqnoUp: ");
      Serial.println(LMIC.seqnoUp - 1);
      Serial.print("LMIC.seqnoDn: ");
      Serial.println(LMIC.seqnoDn);
    }
    // Next TX is scheduled after TX_COMPLETE event.
}


void setup() {
    // put your setup code here, to run once:
  
    Serial.begin(115200);
    Serial.println(F("Starting"));

    // LMIC init
    os_init();

    // Reset the MAC state. Session and pending data transfers will be discarded.
    LMIC_reset();

    // Set static session parameters. Instead of dynamically establishing a session
    // by joining the network, precomputed session parameters are be provided.
    LMIC_setSession (0x1, DEVADDR, NWKSKEY, APPSKEY);

    // Disable link check validation
    LMIC_setLinkCheckMode(0);

    // TTN uses SF9 for its RX2 window.
    LMIC.dn2Dr = DR_SF9;

    // Set data rate and transmit power for uplink (note: txpow seems to be ignored by the library)
    LMIC_setDrTxpow(DR_SF7,14);

    // Start job
    do_send(&sendjob);
}

void loop() {
    // put your main code here, to run repeatedly:
    
    os_runloop_once();
}
