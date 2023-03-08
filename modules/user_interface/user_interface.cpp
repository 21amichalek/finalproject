//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "user_interface.h"


#include "smart_home_system.h"

#include "matrix_keypad.h"



//=====[Declaration of private defines]========================================



//=====[Declaration of private data types]=====================================



//=====[Declaration and initialization of public global objects]===============



//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============



//=====[Declaration and initialization of private global variables]============
char color[] = {'8','8','8'};


//=====[Declarations (prototypes) of private functions]========================

static char userInterfaceMatrixKeypadUpdate();






//=====[Implementations of public functions]===================================

void userInterfaceInit()
{
    matrixKeypadInit( SYSTEM_TIME_INCREMENT_MS );
    
    
}

void userInterfaceUpdate()
{
    userInterfaceMatrixKeypadUpdate();
    mode1Keypad();
    modePartyKeypad();
    
    
}
char mode1Keypad(){
    return userInterfaceMatrixKeypadUpdate();
}
 void modePartyKeypad(){
    int i = 0;
    for (i = 0; i < 3; i++) {
        color[i] = userInterfaceMatrixKeypadUpdate();
    }

}

char readColor1(){
    return color[0];
}

char readColor2(){
    return color[1];
}

char readColor3(){
    return color[2];
}




//=====[Implementations of private functions]==================================

static char userInterfaceMatrixKeypadUpdate()
{
    
    char keyReleased = matrixKeypadUpdate();
    
    if( keyReleased == '1'||'2'||'3'||'4'||'5'||'6'||'7') {
        return keyReleased;
        //this part is causing me trouble I can't quite understand how to fix it
                
    }
    
    
    
    
    
}

 
