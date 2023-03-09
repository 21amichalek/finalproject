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

char codeSequenceFromUserInterface[CODE_NUMBER_OF_KEYS];

//=====[Declaration and initialization of private global variables]============

static displayState_t displayState = DISPLAY_REPORT_STATE;
static int displayRefreshTimeMs = DISPLAY_REFRESH_TIME_REPORT_MS;

char color[] = {'8','8','8'};

//=====[Declarations (prototypes) of private functions]========================

static void userInterfaceMatrixKeypadUpdate();

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

int readSong()
{
    int song = 0;
    if (readMode() == 3) {
        song = getSong();
        // getSong() will be a function in the music 
    }
    return song;
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
    
    sprintf(modeString, "%f", readMode());
    displayCharPositionWrite ( 6,0 );
    displayStringWrite( modeString );

    if ( readMode() == 1 ) {
        userInterfaceDisplayUpdateMode1();

    } else if ( readMode() == 2 ) {
        userInterfaceDisplayUpdateMode2();

    } else if ( readMode() == 3 ) {
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

static char userInterfaceMatrixKeypadUpdate()
{ 
    char keyReleased = matrixKeypadUpdate();
    
    if( keyReleased == '1'||'2'||'3'||'4'||'5'||'6'||'7') {
        return keyReleased;
        //this part is causing me trouble I can't quite understand how to fix it       
    }
}

static char colorNumberToLetter(int indexColor);
{
    char colorLetter = "";
    if ( color[indexColor] == "1" ) {
        colorLetter = "R";
        }
    if ( color[indexColor] == "2" ) {
        colorLetter = "O";
        }
    if ( color[indexColor] == "3" ) {
        colorLetter = "Y";
        }
    if ( color[indexColor] == "4" ) {
        colorLetter = "G";
        }
    if ( color[indexColor] == "5" ) {
        colorLetter = "B";
        }
    if ( color[indexColor] == "6" ) {
        colorLetter = "P";
        }
    if ( color[indexColor] == "7" ) {
        colorLetter = "W";
        }
    return colorLetter;
}

static void UserInterfaceDisplayUpdateMode1()
{
    displayCharPositionWrite( 14,0 );
    displayStringWrite( "NA" );

    char lightingString[1] = "";

    sprintf(lightingString, "%f", colorNumbertoLetter(readColor1()));
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
    sprintf(songString, "%f", songRead());
    displayCharPositionWrite ( 14,0 );
    displayStringWrite( songString );

    UserInterfaceDisplayUpdateLightingMode2And3();
}

static void UserInterfaceDisplayUpdateLightingMode2And3()
{
    char lighting1String[1] = "";

    sprintf(lighting1String, "%f", colorNumbertoLetter(readColor1()));
    displayCharPositionWrite( 10,1 );
    displayStringWrite( lighting1String );

    char lighting2String[1] = "";

    sprintf(lighting2String, "%f", colorNumbertoLetter(readColor2()));
    displayCharPositionWrite( 11,1 );
    displayStringWrite( lighting2String );

    char lighting3String[1] = "";

    sprintf(lighting3String, "%f", colorNumbertoLetter(readColor3()));
    displayCharPositionWrite( 12,1 );
    displayStringWrite( lighting3String );
}
