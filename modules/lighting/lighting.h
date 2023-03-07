//=====[#include guards - begin]===============================================

#ifndef _LIGHTING_H_
#define _LIGHTING_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

typedef enum {
    RGB_LED_RED,
    RGB_LED_GREEN,
    RGB_LED_BLUE,
} lightSystem_t;

//=====[Declarations (prototypes) of public functions]=========================

void lightSystemInit();
void lightSystemUpdate();

void brightControlInit();
void setDutyCycle( lightSystem_t light, float dutyCycle );
void setLight (char color);
void mode1Color(char color);
void mode2Color(char color1, char color2, char color3);
void mode3Color(char color1, char color2, char color3);

//=====[#include guards - end]=================================================

#endif // _LIGHTING_H_
