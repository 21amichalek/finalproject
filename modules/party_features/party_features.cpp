//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "mbed.h"

#include "party_features.h"

#include "lighting.h"
#include "music.h"
#include "matrix_keypad.h"
#include "pc_serial_com.h"
#include "user_interface.h"
#include "ldr_sensor.h"

//=====[Declaration of private defines]========================================

#define MAX_VOLTAGE_PARTY_STOP 0.7

//=====[Declaration of private data types]=====================================

typedef enum {
    PARTY_OFF,
    PARTY_MODE_SCANNING,
    PARTY_MODE_1,
    PARTY_MODE_2,
    PARTY_MODE_3
} PartyState_t;

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static PartyState_t PartyState;
static bool partyStopState = OFF;

//=====[Declarations (prototypes) of private functions]========================

static bool partyStop();

//=====[Implementations of public functions]===================================

void PartyInit(){
    brightControlInit();
    musicInit();
    if (!partyStop()) {
        PartyState = PARTY_MODE_SCANNING;
    }
}

void PartyUpdate(){
    switch(PartyState) {
    case PARTY_OFF:
        PartyInit();
        break;

    case PARTY_MODE_SCANNING:
        if (readPartyMode() == '1') {
            PartyState = PARTY_MODE_1;
        }
        if (readPartyMode() == '2') {
            PartyState = PARTY_MODE_2;
        }
        if (readPartyMode() == '3') {
            PartyState = PARTY_MODE_3;
        }
        break;

    case PARTY_MODE_1:
        mode1Color(readMatrixInput());
        if ( partyStop() ) {
            PartyState = PARTY_OFF;
        }
        break;

    case PARTY_MODE_2:
        mode2Color('1', '3','6');
        if ( partyStop() ) {
            PartyState = PARTY_OFF;
        }
        break;
    
    case PARTY_MODE_3:
         mode3Color('1', '3','6');
         if ( partyStop() ) {
            PartyState = PARTY_OFF;
        }
        setMusic(readMatrixInput()); 
        break;
    }
}

//=====[Implementations of private functions]==================================

static bool partyStop()
{
    if ( ldrSensorRead() < MAX_VOLTAGE_PARTY_STOP ) {
        partyStopState = ON;
    } else {
        partyStopState = OFF;
    }
    return partyStopState;
}
