//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "music.h"

//=====[Declaration of private defines]========================================

#define TIME_INCREMENT   10

//=====[Declaration of private data types]=====================================

PwmOut musicPin(PE_14);

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

bool songPlaying;

//=====[Declaration and initialization of private global variables]============

static float musicPeriod = 0.0001;
static float musicDutyCycle = 0.5;
static float dutyCycleOff = 1.0;

static int accumulatedTime;

static float A = 0.000440;
static float B = 0.000494;
static float C = 0.000523; 
static float D = 0.000587;
static float E = 0.000659;
static float G = 0.000784;
static float F = 0.000698;

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

//hot cross buns
void playSong1(){
    if (accumulatedTime < 1000 ){
        musicPin.period(B);
        accumulatedTime += TIME_INCREMENT;
    } 
    else if ( (1000 <= accumulatedTime) && (accumulatedTime < 2000)){
        musicPin.period(A);
        accumulatedTime += TIME_INCREMENT;
    }
    else if (2000 <= accumulatedTime && accumulatedTime < 4000){
        musicPin.period(G);
        accumulatedTime += TIME_INCREMENT;
    }
    else if (4000 <= accumulatedTime && accumulatedTime < 5000){
        musicPin.period(B);
        accumulatedTime += TIME_INCREMENT;
    }
    else if (5000 <= accumulatedTime && accumulatedTime < 6000){
        musicPin.period(A);
        accumulatedTime += TIME_INCREMENT;
    }
    else if (6000 <= accumulatedTime && accumulatedTime < 8000){
        musicPin.period(G);
        accumulatedTime += TIME_INCREMENT;
    }
    else{
        accumulatedTime = 0;
    }
}

// twinkle twinkle little star
// ccggaag
void playSong2(){
    if (accumulatedTime < 1000 ){
        musicPin.period(C);
        accumulatedTime += TIME_INCREMENT;
    } 
    else if ( (1000 <= accumulatedTime) && (accumulatedTime < 2000)){
        musicPin.period(C);
        accumulatedTime += TIME_INCREMENT;
    }
    else if (2000 <= accumulatedTime && accumulatedTime < 3000){
        musicPin.period(G);
        accumulatedTime += TIME_INCREMENT;
    }
    else if ( (3000 <= accumulatedTime) && (accumulatedTime < 4000)){
        musicPin.period(G);
        accumulatedTime += TIME_INCREMENT;
    }
    else if (4000 <= accumulatedTime && accumulatedTime < 5000){
        musicPin.period(A);
        accumulatedTime += TIME_INCREMENT;
    }
    else if (5000 <= accumulatedTime && accumulatedTime < 6000){
        musicPin.period(A);
        accumulatedTime += TIME_INCREMENT;
    }
    else if (6000 <= accumulatedTime && accumulatedTime < 8000){
        musicPin.period(G);
        accumulatedTime += TIME_INCREMENT;
    }
    else{
        accumulatedTime = 0;
    }
}

//happy birthday
//ccdcfe
void playSong3(){
    if (accumulatedTime < 1000 ){
        musicPin.period(C);
        accumulatedTime += TIME_INCREMENT;
    } 
    else if ( (1000 <= accumulatedTime) && (accumulatedTime < 2000)){
        musicPin.period(C);
        accumulatedTime += TIME_INCREMENT;
    }
    else if (2000 <= accumulatedTime && accumulatedTime < 3000){
        musicPin.period(D);
        accumulatedTime += TIME_INCREMENT;
    }
    else if ( (3000 <= accumulatedTime) && (accumulatedTime < 4000)){
        musicPin.period(C);
        accumulatedTime += TIME_INCREMENT;
    }
    else if (4000 <= accumulatedTime && accumulatedTime < 5000){
        musicPin.period(F);
        accumulatedTime += TIME_INCREMENT;
    }
    else if (5000 <= accumulatedTime && accumulatedTime < 7000){
        musicPin.period(E);
        accumulatedTime += TIME_INCREMENT;
    }
    else{
        accumulatedTime = 0;
    }
}

//mary had a little lamb
//E D C D E E E
void playSong4(){
    if (accumulatedTime < 1000 ){
        musicPin.period(E);
        accumulatedTime += TIME_INCREMENT;
    } 
    else if ( (1000 <= accumulatedTime) && (accumulatedTime < 2000)){
        musicPin.period(D);
        accumulatedTime += TIME_INCREMENT;
    }
    else if (2000 <= accumulatedTime && accumulatedTime < 3000){
        musicPin.period(C);
        accumulatedTime += TIME_INCREMENT;
    }
    else if ( (3000 <= accumulatedTime) && (accumulatedTime < 4000)){
        musicPin.period(D);
        accumulatedTime += TIME_INCREMENT;
    }
    else if (4000 <= accumulatedTime && accumulatedTime < 5000){
        musicPin.period(E);
        accumulatedTime += TIME_INCREMENT;
    }
    else if (5000 <= accumulatedTime && accumulatedTime < 6000){
        musicPin.period(E);
        accumulatedTime += TIME_INCREMENT;
    }
    else if (6000 <= accumulatedTime && accumulatedTime < 8000){
        musicPin.period(E);
        accumulatedTime += TIME_INCREMENT;
    }
    else{
        accumulatedTime = 0;
    }
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
