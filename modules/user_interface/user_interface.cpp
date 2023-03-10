//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "user_interface.h"
#include "lighting.h"
#include "music.h"
#include "display.h"
#include "matrix_keypad.h"
#include "pc_serial_com.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============
static char colorPick;
static char songPick;
static displayState_t displayState = DISPLAY_REPORT_STATE;
static int displayRefreshTimeMs = DISPLAY_REFRESH_TIME_REPORT_MS;



//=====[Declarations (prototypes) of private functions]========================

static void Mode1ColorUpdate();
static void songUpdate();

static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();

static char colorNumberToLetter(int indexColor);

static void UserInterfaceDisplayUpdateMode1();
static void UserInterfaceDisplayUpdateMode2();
static void UserInterfaceDisplayUpdateMode3();
static void UserInterfaceDisplayUpdateLightingMode2And3();

//=====[Implementations of public functions]===================================

void userInterfaceInit()
{
    matrixKeypadInit( SYSTEM_TIME_INCREMENT_MS );
    userInterfaceDisplayInit();
}

void userInterfaceUpdate()
{
    Mode1ColorUpdate();
    songUpdate();
    userInterfaceDisplayUpdate();
}

char readMode1Color(){
    return colorPick;
}


char readSong(){
    return songPick;
}


//=====[Implementations of private functions]==================================
static void Mode1ColorUpdate()
{
    char keyReleased = matrixKeypadUpdate();
    if( keyReleased != '\0' ) {
        colorPick = keyReleased;
        
    }             
}

static void songUpdate() {
    char keyReleased = matrixKeypadUpdate();
    if( keyReleased != '\0' ) {
        songPick = keyReleased;
        
    }
 }

static void userInterfaceDisplayUpdate()
{
    char modeString[1] = "";
    
    sprintf(modeString, "%f", readPartyMode());
    displayCharPositionWrite ( 6,0 );
    displayStringWrite( modeString );

    if ( readPartyMode() == 1 ) {
        userInterfaceDisplayUpdateMode1();

    } else if ( readPartyMode() == 2 ) {
        userInterfaceDisplayUpdateMode2();

    } else if ( readPartyMode() == 3 ) {
        userInterfaceDisplayUpdateMode3();
    }
}

static void userInterfaceDisplayInit()
{
    displayInit( DISPLAY_TYPE_GLCD_ST7920, DISPLAY_CONNECTION_SPI );
    // I don't know if we need this but including it for now
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



static char colorNumberToLetter();
{
    char colorNumber = readMode1Color();
    char colorLetter = "";
    if ( colorNumber == '1' ) {
        colorLetter = "R";
        }
    if ( colorNumber == '2' ) {
        colorLetter = "Y";
        }
    if ( colorNumber == '3' ) {
        colorLetter = "G";
        }
    if ( colorNumber == '4' ) {
        colorLetter = "B";
        }
    if ( colorNumber == '5' ) {
        colorLetter = "I";
        }
    if ( colorNumber == '6' ) {
        colorLetter = "P";
        }
    if ( colorNumber == '7' ) {
        colorLetter = "W";
        }
    return colorLetter;
}

static void UserInterfaceDisplayUpdateMode1()
{
    displayCharPositionWrite( 14,0 );
    displayStringWrite( "NA" );

    char lightingString[1] = "";

    sprintf(lightingString, "%f", colorNumbertoLetter(readMode1Color()));
    displayCharPositionWrite( 10,1 );
    displayStringWrite( lightingString );
}

static void UserInterfaceDisplayUpdateMode2()
{
    displayCharPositionWrite( 14,0 );
    displayStringWrite( "NA" ); // this writes that there is no song playing

    UserInterfaceDisplayUpdateLightingMode2And3();
}

static void UserInterfaceDisplayUpdateMode3()
{
    char songString[2] = "";
    sprintf(songString, "%f", readSong());
    displayCharPositionWrite ( 14,0 );
    displayStringWrite( songString );

    UserInterfaceDisplayUpdateLightingMode2And3();
}

static void UserInterfaceDisplayUpdateLightingMode2And3()
{
    displayCharPositionWrite ( 10,1 );
    displayStringWrite( "RGP" );
}
