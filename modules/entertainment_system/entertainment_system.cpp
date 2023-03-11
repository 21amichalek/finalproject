//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "entertainment_system.h"

#include "user_interface.h"
#include "party_features.h"
#include "pc_serial_com.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void entertainmentSystemInit()
{
    userInterfaceInit();
    pcSerialComInit();
    PartyInit();
}

void entertainmentSystemUpdate()
{
    userInterfaceUpdate();
    pcSerialComUpdate();
    PartyUpdate();
    delay(SYSTEM_TIME_INCREMENT_MS);
}

//=====[Implementations of private functions]==================================
