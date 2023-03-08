//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "user_interface.h"

#include "lighting.h"
#include "music.h"
#include "display.h"
#include "matrix_keypad.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

 // InterruptIn gateOpenButton(PF_9);
 // InterruptIn gateCloseButton(PF_8);

 // DigitalOut incorrectCodeLed(LED3);
 // DigitalOut systemBlockedLed(LED2);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

char codeSequenceFromUserInterface[CODE_NUMBER_OF_KEYS];

//=====[Declaration and initialization of private global variables]============

static displayState_t displayState = DISPLAY_REPORT_STATE;
static int displayRefreshTimeMs = DISPLAY_REFRESH_TIME_REPORT_MS;

char color[] = {'8','8','8'};

//=====[Declarations (prototypes) of private functions]========================

static void userInterfaceMatrixKeypadUpdate();

static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();

//=====[Implementations of public functions]===================================

void userInterfaceInit()
{
    matrixKeypadInit( SYSTEM_TIME_INCREMENT_MS );
    userInterfaceDisplayInit();
}

void userInterfaceUpdate()
{
    userInterfaceMatrixKeypadUpdate();
    userInterfaceDisplayUpdate();

    mode1Keypad();
    modePartyKeypad();
}

char mode1Keypad()
{
    return userInterfaceMatrixKeypadUpdate();
}

void modePartyKeypad()
{
    int i = 0;
    for (i = 0; i < 3; i++) {
        color[i] = userInterfaceMatrixKeypadUpdate();
    }
}

char readColor1()
{
    return color[0];
}

char readColor2()
{
    return color[1];
}

char readColor3()
{
    return color[2];
}

//=====[Implementations of private functions]==================================

static void userInterfaceDisplayUpdate()
{
    char modeString[1] = "";
    
    // modeRead() is a temporary function (hasnt been written yet)
    // songRead() is a temporary function (hasnt been written yet)
    // lightingRead() is a temporary function (hasnt been written yet)
    // replace these with the correct functions

    sprintf(modeString, "%f", modeRead());
    displayCharPositionWrite ( 6,0 );
    displayStringWrite( modeString );

    if ( modeRead() == 1 ) {
        displayCharPositionWrite( 14,0 );
        displayStringWrite( "NA" );

        char lightingString[1] = "";

        sprintf(lightingString, "%f", lightingRead());
        displayCharPositionWrite( 10,1 );
        displayStringWrite( lightingString );
    } else if ( modeRead() == 2 ) {
        displayCharPositionWrite( 14,0 );
        displayStringWrite( "NA" );

        char lightingString[3] = "";

        sprintf(lightingString, "%f", lightingRead());
        displayCharPositionWrite( 10,1 );
        displayStringWrite( lightingString );
    } else {
        char songString[2] = "";

        sprintf(songString, "%f", songRead());
        displayCharPositionWrite ( 14,0 );
        displayStringWrite( songString );

        char lightingString[3] = "";
        
        sprintf(lightingString, "%f", lightingRead());
        displayCharPositionWrite( 10,1 );
        displayStringWrite( lightingString );
    }
}

static void userInterfaceDisplayInit()
{
    displayInit( DISPLAY_TYPE_GLCD_ST7920, DISPLAY_CONNECTION_SPI );
    // idk if we need this but including it for now
    displayState = DISPLAY_REPORT_STATE;
    displayRefreshTimeMs = DISPLAY_REFRESH_TIME_REPORT_MS;

    displayModeWrite( DISPLAY_MODE_CHAR );

    displayClear();

    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Mode: " );

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "Lighting: " );

    displayCharPositionWrite ( 8,0 );
    displayStringWrite( "Song: " );
}

static char userInterfaceMatrixKeypadUpdate()
{ 
    char keyReleased = matrixKeypadUpdate();
    
    if( keyReleased == '1'||'2'||'3'||'4'||'5'||'6'||'7') {
        return keyReleased;
        //this part is causing me trouble I can't quite understand how to fix it       
    }
}
