//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "user_interface.h"

#include "display.h"
#include "matrix_keypad.h"
#include "pc_serial_com.h"
#include "entertainment_system.h"

//=====[Declaration of private defines]========================================

#define DISPLAY_REFRESH_TIME_MS 1000

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static char matrixInput;

//=====[Declarations (prototypes) of private functions]========================

static void matrixInputUpdate();

static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();

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
    matrixInputUpdate();
    userInterfaceDisplayUpdate();
}

char readMatrixInput(){
    return matrixInput;
}

//=====[Implementations of private functions]==================================

static void matrixInputUpdate()
{
    char keyReleased = matrixKeypadUpdate();
    if( keyReleased != '\0' ) {
        matrixInput = keyReleased;
    }             
}

static void userInterfaceDisplayUpdate()
{
    static int accumulatedDisplayTime = 0;
    if ( accumulatedDisplayTime >= DISPLAY_REFRESH_TIME_MS ) {
        if ( readPartyMode() == '1' ) {
        displayCharPositionWrite ( 6,0 );
        displayStringWrite( "1" );
        UserInterfaceDisplayUpdateMode1();

    } else if ( readPartyMode() == '2' ) {
        displayCharPositionWrite ( 6,0 );
        displayStringWrite( "2" );
        UserInterfaceDisplayUpdateMode2();

    } else if ( readPartyMode() == '3' ) {
        displayCharPositionWrite ( 6,0 );
        displayStringWrite( "3" );
        UserInterfaceDisplayUpdateMode3();
    }
    } else {
        accumulatedDisplayTime = accumulatedDisplayTime + SYSTEM_TIME_INCREMENT_MS;
    }
}

static void userInterfaceDisplayInit()
{
    displayInit();

    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Mode: " );

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "Lighting: " );

    displayCharPositionWrite ( 8,0 );
    displayStringWrite( "Song: " );
    
}

static void UserInterfaceDisplayUpdateMode1()
{
    displayCharPositionWrite( 14,0 );
    displayStringWrite( "NA" );  // this writes that there is no song playing
    
    char colorNumber = readMatrixInput();

    if ( colorNumber == '1' ) {
        displayCharPositionWrite ( 10,1 );
        displayStringWrite( "R" );
        }
    if ( colorNumber == '2' ) {
        displayCharPositionWrite ( 10,1 );
        displayStringWrite( "Y" );
        }
    if ( colorNumber == '3' ) {
        displayCharPositionWrite ( 10,1 );
        displayStringWrite( "G" );
        }
    if ( colorNumber == '4' ) {
        displayCharPositionWrite ( 10,1 );
        displayStringWrite( "B" );
        }
    if ( colorNumber == '5' ) {
        displayCharPositionWrite ( 10,1 );
        displayStringWrite( "I" );
        }
    if ( colorNumber == '6' ) {
        displayCharPositionWrite ( 10,1 );
        displayStringWrite( "P" );
        }
    if ( colorNumber == '7' ) {
        displayCharPositionWrite ( 10,1 );
        displayStringWrite( "W" );
        }
}

static void UserInterfaceDisplayUpdateMode2()
{
    displayCharPositionWrite( 14,0 );
    displayStringWrite( "NA" ); // this writes that there is no song playing

    UserInterfaceDisplayUpdateLightingMode2And3();
}

static void UserInterfaceDisplayUpdateMode3()
{
    if ( readMatrixInput() == 'A' ) {
        displayCharPositionWrite ( 14,0 );
        displayStringWrite( "1" );

    } else if ( readMatrixInput() == 'B' ) {
        displayCharPositionWrite ( 14,0 );
        displayStringWrite( "2" );

    } else if ( readMatrixInput() == 'C' ) {
        displayCharPositionWrite ( 14,0 );
        displayStringWrite( "3" );

    } else if ( readMatrixInput() == 'D' ) {
        displayCharPositionWrite ( 14,0 );
        displayStringWrite( "4" );
    }
    UserInterfaceDisplayUpdateLightingMode2And3();
}

static void UserInterfaceDisplayUpdateLightingMode2And3()
{
    displayCharPositionWrite ( 10,1 );
    displayStringWrite( "RGP" );
}
