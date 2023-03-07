//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

//=====[Declaration of private defines]========================================

#define MUSIC_DUTY_CYCLE 0.5

//=====[Declaration of private data types]=====================================

digitalOut musicPin(PE_11);

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================
static void setPeriod(float period);

//=====[Implementations of public functions]===================================


//set period and duty cycle
void musicInit(){
    setPeriod(0.1f);
    setMusicDutyCycle();
}

void setMusicDutyCycle()
{
    musicPin.write(MUSIC_DUTY_CYCLE);
}


//vary frequency but constant duty cycle
static void setMusicPeriod(float period){

}


//
