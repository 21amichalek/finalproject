//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "mbed.h"
#include "lighting.h"
#include "smart_home_system.h"
#include "matrix_keypad.h"
#include "party_features.h"
#include "pc_serial_com.h"
#include "user_interface.h"
//=====[Declaration of private defines]========================================

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
//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================
void PartyInit(){
    brightControlInit();

    PartyState = PARTY_MODE_SCANNING;

    



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

        if (readPartyMode() == '2') {
            PartyState = PARTY_MODE_3;
        }
        
        break;

    case PARTY_MODE_1:
        mode1Color(mode1Keypad());
        

        
        break;

    case PARTY_MODE_2:
         mode2Color(readColor1(), readColor2(), readColor3());
        
        break;
    
    case PARTY_MODE_3:
         mode3Color(readColor1(), readColor2(), readColor3());

    default:
        
        break;
    }
    
}







//=====[Implementations of private functions]==================================




