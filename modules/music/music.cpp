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
static int accumulatedTime;
static int timeIncrement = 10;



//=====[Declarations (prototypes) of private functions]========================
static void setMusicPeriod(float period);

//=====[Implementations of public functions]===================================

//set period and duty cycle
void musicInit(){
    setMusicPeriod(musicPeriod);                                       
    setMusicDutyCycle(musicDutyCycle);
    songPlaying = true;
    accumulatedTime = 0;
}


void songPlayingWrite( bool state ){
    songPlaying = state;
}

//hot cross bums
void playSong1(){
        if (accumulatedTime < 1000 ){
            setMusicDutyCycle(1);
            accumulatedTime += timeIncrement;
        }
        if ( 1000 < accumulatedTime && accumulatedTime < 2000){
            setMusicDutyCycle(0.15);
            accumulatedTime += timeIncrement;
        }
        if (2000 < accumulatedTime && accumulatedTime < 4000){
            setMusicDutyCycle(0.05);
            accumulatedTime += timeIncrement;
        }
        if (4000 < accumulatedTime && accumulatedTime < 5000){
            setMusicDutyCycle(0.25);
            accumulatedTime += timeIncrement;
        }
        if (5000 < accumulatedTime && accumulatedTime < 6000){
            setMusicDutyCycle(0.15);
            accumulatedTime += timeIncrement;
        }
        if (6000 < accumulatedTime && accumulatedTime < 8000){
            setMusicDutyCycle(0.05);
            accumulatedTime += timeIncrement;
        }
        if (accumulatedTime > 9000){
            accumulatedTime = 0;
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
        setMusicDutyCycle(1);;
        delay(1000);
        setMusicDutyCycle(0.05);
        delay(1000);
        setMusicDutyCycle(1);;
        delay(1000);
        setMusicDutyCycle(0.25);
        delay(3000);
    }
}

void test(){
    setMusicDutyCycle(0.15);
    delay(1000);
    setMusicDutyCycle(1);
    delay(2000);
}


//changes the volume 
void setMusicDutyCycle(float dutyCycle){
    musicPin.write(dutyCycle);
}

void setMusic(char song){
    switch(song){
        case 'A':
            playSong1();
        break;

        case 'B':
            playSong2();
        break;

        case 'C':
            playSong3();
        break;

        case 'D':
            playSong4();
        break;
    }

}


//vary frequency but constant duty cycle
//changes the note 
static void setMusicPeriod(float period){
    musicPin.period(period);
}

