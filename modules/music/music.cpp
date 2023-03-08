//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "music.h"

//=====[Declaration of private defines]========================================

#define MUSIC_DUTY_CYCLE    0.5

//=====[Declaration of private data types]=====================================

//bc buzzer and sending a pwm
PwmOut musicPin(PE_14);

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================
static void setMusicPeriod(float period);

//=====[Implementations of public functions]===================================

//set period and duty cycle
void musicInit(){
    setMusicPeriod(0.001f);                                       
    setMusicDutyCycle(0.5f);
}

//changes the volume 
void setMusicDutyCycle(float dutyCycle){
    musicPin.write(dutyCycle);
}


//vary frequency but constant duty cycle
//changes the note 
static void setMusicPeriod(float period){
    musicPin.period(period);
}

//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "music.h"

//=====[Declaration of private defines]========================================

#define MUSIC_DUTY_CYCLE    0.5

//=====[Declaration of private data types]=====================================

//bc buzzer and sending a pwm
PwmOut musicPin(PE_14);

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================
static void setMusicPeriod(float period);

//=====[Implementations of public functions]===================================

//set period and duty cycle
void musicInit(){
    setMusicPeriod(0.001f);                                       
    setMusicDutyCycle(0.5f);
}

//changes the volume 
void setMusicDutyCycle(float dutyCycle){
    musicPin.write(dutyCycle);
}


//vary frequency but constant duty cycle
//changes the note 
static void setMusicPeriod(float period){
    musicPin.period(period);
}

