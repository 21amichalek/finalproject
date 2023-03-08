//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "pc_serial_com.h"


#include "lighting.h"


//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

typedef enum{
    PC_SERIAL_COMMANDS,
    PC_SERIAL_GET_CODE,
    PC_SERIAL_SAVE_NEW_CODE,
} pcSerialComMode_t;

//=====[Declaration and initialization of public global objects]===============

UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============



//=====[Declaration and initialization of private global variables]============

static pcSerialComMode_t pcSerialComMode = PC_SERIAL_COMMANDS;



//=====[Declarations (prototypes) of private functions]========================

static void pcSerialComStringRead( char* str, int strLength );

static void pcSerialComCommandUpdate( char receivedChar );

static void instructions();
static void commandChillState();
static void commandPartyState();
static void commandRaveState();
static void commandGetInformation();
static void commandShowCustomizationSelection();
static void commandShowKeys();

//=====[Implementations of public functions]===================================

void pcSerialComInit()
{
    instructions();
}

char pcSerialComCharRead()
{
    char receivedChar = '\0';
    if( uartUsb.readable() ) {
        uartUsb.read( &receivedChar, 1 );
    }
    return receivedChar;
}

void pcSerialComStringWrite( const char* str )
{
    uartUsb.write( str, strlen(str) );
}

void pcSerialComUpdate()
{
    char receivedChar = pcSerialComCharRead();
    if( receivedChar != '\0' ) {
        switch ( pcSerialComMode ) {
            case PC_SERIAL_COMMANDS:
                pcSerialComCommandUpdate( receivedChar );
            break;

            default:
                pcSerialComMode = PC_SERIAL_COMMANDS;
            break;
        }
    }    
}



char pMode = '\0';
char readPartyMode() {
    return pMode;
}

//=====[Implementations of private functions]==================================

static void pcSerialComCommandUpdate( char receivedChar )
{
    switch (receivedChar) {
        case '1': pMode = receivedChar; break;
        case '2': pMode = receivedChar; break;
        case '3': pMode = receivedChar; break;
        case 'i': case 'I': commandGetInformation(); break;
        case 's': case 'S': commandShowCustomizationSelection(); break;
        case 'k': case 'K': commandShowKeys(); break;
        default: instructions(); break;
    } 
}



static void instructions()
{
    pcSerialComStringWrite( "Welcome to the Integrated Entertainment System\r\n" );
    pcSerialComStringWrite( "There are three distinct modes of entertainment to select from\r\n\r\n" );
    pcSerialComStringWrite( "Mode 1: Chill\r\n" );
    pcSerialComStringWrite( "Mode 2: Party\r\n" );
    pcSerialComStringWrite( "Mode 3: Rave\r\n\r\n" );
    pcSerialComStringWrite( "To select a desired party mode please press the according keys:\r\n" );
    pcSerialComStringWrite( "Press '1' to select Chill\r\n" );
    pcSerialComStringWrite( "Press '2' to select Party\r\n" );
    pcSerialComStringWrite( "Press '3' to select Rave\r\n\r\n" );
    pcSerialComStringWrite( "Press 's' or 'S' to show current customization selections\r\n" );
    pcSerialComStringWrite( "Press 'i' or 'I' to show information about each entertainment mode\r\n" );
    pcSerialComStringWrite( "Press 'k' or 'K' to show the keypad's customization buttons\r\n");
    pcSerialComStringWrite( "\r\n" );
}



static void commandGetInformation()
{
    pcSerialComStringWrite( "Using the keypad, you can customize the lighting and music!\r\n\r\n");
    
    pcSerialComStringWrite( "Mode 1: Chill\r\n");
    pcSerialComStringWrite( "Select a color of lighting\r\n\r\n");
    pcSerialComStringWrite( "Mode 2: Party\r\n");
    pcSerialComStringWrite( "Select three colors of slow flashing lighting\r\n\r\n");
    pcSerialComStringWrite( "Mode 1: Rave\r\n");
    pcSerialComStringWrite( "Select three colors of fast flashing lighting\r\n");
    pcSerialComStringWrite( "and\r\n");
    pcSerialComStringWrite( "Select a song to be played\r\n\r\n");
}

static void commandShowCustomizationSelection()
{
    // show current mode
    // show current color(s)
    // show current song
}

static void commandShowKeys()
{
    pcSerialComStringWrite( "To select a lighting color or song, press the according key on the keypad:\r\n\r\n");
    
    pcSerialComStringWrite( "Lighting Colors:\r\n");
    pcSerialComStringWrite( "----------------\r\n");
    pcSerialComStringWrite( "Red: press '1'\r\n");
    pcSerialComStringWrite( "Orange: press '2'\r\n");
    pcSerialComStringWrite( "Yellow: press '3'\r\n");
    pcSerialComStringWrite( "Green: press '4'\r\n");
    pcSerialComStringWrite( "Blue: press '5'\r\n");
    pcSerialComStringWrite( "Purple: press '6'\r\n");
    pcSerialComStringWrite( "White: press '7'\r\n\r\n");
    
    pcSerialComStringWrite( "Songs:\r\n");
    pcSerialComStringWrite( "----------------\r\n");
    pcSerialComStringWrite( "Song 1: press 'A'\r\n");
    pcSerialComStringWrite( "Song 2: press 'B'\r\n");
    pcSerialComStringWrite( "Song 3: press 'C'\r\n");
    pcSerialComStringWrite( "Song 1: press 'D'\r\n\r\n");
}
