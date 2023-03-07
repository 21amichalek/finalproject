#include "arm_book_lib.h"
#include "mbed.h"
#include "lighting.h"
#include "smart_home_system.h"

//=====[Declaration of private defines]========================================
#define strobeTime 1000
//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

PwmOut RGBLed[] = {(PD_12), (PA_0), (PB_4)};

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================
static void setPeriod( lightSystem_t light, float period );

//=====[Implementations of public functions]===================================

void lightLevelControlInit() { }

void lightLevelControlUpdate() { }

void brightControlInit()
{
    setPeriod( RGB_LED_RED, 0.01f );
    setPeriod( RGB_LED_GREEN, 0.01f );
    setPeriod( RGB_LED_BLUE, 0.01f );

    setDutyCycle( RGB_LED_RED, 0.5f );
    setDutyCycle( RGB_LED_GREEN, 0.5f );
    setDutyCycle( RGB_LED_BLUE, 0.5f );
}

void setDutyCycle( lightSystem_t light, float dutyCycle )
{
    RGBLed[light].write(dutyCycle);
}
void mode1Color(char color) {
    setLight(color);
}

void mode2Color(char color1, char color2, char color3) {
    char color[] = {color1, color2, color3};
    
    
    static int accumulatedTimeAlarm = 0;
    static int i = 0;
    if (i == 3) {
        i = 0;
    }

    accumulatedTimeAlarm = accumulatedTimeAlarm + SYSTEM_TIME_INCREMENT_MS;
    if( accumulatedTimeAlarm >= strobeTime ) {
        accumulatedTimeAlarm = 0;
        setLight(color[i]); 
        i++;      
    }       
    
}
 void mode3Color(char color1, char color2, char color3) {
    char color[] = {color1,'8', color2,'8', color3,'8'};

    static int accumulatedTimeAlarm = 0;
    static int i = 0;
    if (i == 6) {
        i = 0;
    }
    
    accumulatedTimeAlarm = accumulatedTimeAlarm + SYSTEM_TIME_INCREMENT_MS;
    
        if( accumulatedTimeAlarm >= (strobeTime/10) ) {
            accumulatedTimeAlarm = 0;
            setLight(color[i]);  
            i++;
              
        }   
    
 }


void setLight (char color) {
    switch(color) {
    case '1':
        setDutyCycle( RGB_LED_RED, 0.95f ); //RED
        setDutyCycle( RGB_LED_GREEN, 0.0f );
        setDutyCycle( RGB_LED_BLUE, 0.0f );
    break;

    case '2':
        setDutyCycle( RGB_LED_RED, 0.75f ); //Yellow
        setDutyCycle( RGB_LED_GREEN, 0.25f );
        setDutyCycle( RGB_LED_BLUE, 0.0f );
    break;

    case '3':
        setDutyCycle( RGB_LED_RED, 0.0f ); //Green
        setDutyCycle( RGB_LED_GREEN, 0.5f );
        setDutyCycle( RGB_LED_BLUE, 0.0f );
    break;

    case '4':
        setDutyCycle( RGB_LED_RED, 0.0f ); //Light Blue
        setDutyCycle( RGB_LED_GREEN, 0.5f );
        setDutyCycle( RGB_LED_BLUE, 0.75f );
    break;

    case '5':
        setDutyCycle( RGB_LED_RED, 0.0f ); //Dark Blue
        setDutyCycle( RGB_LED_GREEN, 0.0f );
        setDutyCycle( RGB_LED_BLUE, 0.5f );
    break;

    case '6':
        setDutyCycle( RGB_LED_RED, 0.5f ); //Magenta
        setDutyCycle( RGB_LED_GREEN, 0.0f );
        setDutyCycle( RGB_LED_BLUE, 0.5f );
    break;

    case '7':
        setDutyCycle( RGB_LED_RED, 0.5f ); //White
        setDutyCycle( RGB_LED_GREEN, 0.5f );
        setDutyCycle( RGB_LED_BLUE, 0.5f );
    break;

    default:
        setDutyCycle( RGB_LED_RED, 0.0f ); //OFF
        setDutyCycle( RGB_LED_GREEN, 0.0f );
        setDutyCycle( RGB_LED_BLUE, 0.0f );

    }
}



//=====[Implementations of private functions]==================================

static void setPeriod( lightSystem_t light, float period )
{
    RGBLed[light].period(period);
}


