//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "mbed.h"

#include "lighting.h"
#include "matrix_keypad.h"
#include "party_features.h"
#include "pc_serial_com.h"
#include "user_interface.h"

#include "ldr_sensor.h"

//=====[Declaration of private defines]========================================

#define MAX_VOLTAGE_PARTY_STOP 0.6

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

//=====[Implementations of public functions]===================================

void PartyInit()
{
    brightControlInit();

    PartyState = PARTY_MODE_SCANNING;
}

void PartyUpdate()
{
    switch(PartyState) {

    case PARTY_OFF:
        PartyInit();
        break;

    case PARTY_MODE_SCANNING:
        
        if ( partyStop() ) {
            PartyState = PARTY_MODE_SCANNING;
        }

        else if (readPartyMode() == '1') {
            PartyState = PARTY_MODE_1;
        }

        else if (readPartyMode() == '2') {
            PartyState = PARTY_MODE_2;
        }

        else if (readPartyMode() == '3') {
            PartyState = PARTY_MODE_3;
        }
        break;

    case PARTY_MODE_1:
        if ( partyStop() ) {
            PartyState = PARTY_MODE_SCANNING;
        }
        mode1Color(mode1Keypad());
        break;

    case PARTY_MODE_2:
        if ( partyStop() ) {
            PartyState = PARTY_MODE_SCANNING;
        }
         mode2Color(readColor1(), readColor2(), readColor3());
        break;
    
    case PARTY_MODE_3:
        if ( partyStop() ) {
            PartyState = PARTY_MODE_SCANNING;
        }
         mode3Color(readColor1(), readColor2(), readColor3());
        break;

    default:
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
