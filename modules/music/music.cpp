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
bool songPlaying;

//=====[Declaration and initialization of private global variables]============

static float musicPeriod = 0.0001;
static float musicDutyCycle = 0.5;



//=====[Declarations (prototypes) of private functions]========================
static void setMusicPeriod(float period);

//=====[Implementations of public functions]===================================

//set period and duty cycle
void musicInit(){
    setMusicPeriod(musicPeriod);                                       
    setMusicDutyCycle(musicDutyCycle);
    songPlaying = true;
}


void songPlayingWrite( bool state ){
    songPlaying = state;
}

//hot cross bums
void playSong1(){
    while (songPlaying){
       setMusicDutyCycle(0.25);
       delay(1000);
       setMusicDutyCycle(0.15);
       delay(1000);
       setMusicDutyCycle(0.5);
       delay(2000);
       setMusicDutyCycle(0.25);
       delay(1000);
       setMusicDutyCycle(0.15);
       delay(1000);
       setMusicDutyCycle(0.05);
       delay(2000);
    }
}

// original
void playSong2(){
    while (songPlaying){
        setMusicDutyCycle(0.25);
        delay(1000);
        setMusicDutyCycle(1);
        delay(1000);
        setMusicDutyCycle(0.25);
        delay(1000);
        setMusicDutyCycle(0.15);
        delay(1000);
    }
}

//happy birthday
//ccdcfe
void playSong3(){
    while (songPlaying){
        setMusicDutyCycle(0.35);
        delay(2000);
        setMusicDutyCycle(0.25);
        delay(1000);
        setMusicDutyCycle(0.35);
        delay(1000);
        setMusicDutyCycle(0.05);
        delay(1000);
        setMusicDutyCycle(0.15);
        delay(4000);
    }
}

//mary had a little lamb
//E D C D E E E
void playSong4(){
    while (songPlaying){
        setMusicDutyCycle(0.15);
        delay(1000);
        setMusicDutyCycle(0.25);
        delay(1000);
        setMusicDutyCycle(0.35);
        delay(1000);
        setMusicDutyCycle(0.25);
        delay(1000);
        setMusicDutyCycle(0.15);
        delay(3000);
    }
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

