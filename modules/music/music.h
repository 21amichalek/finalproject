//=====[#include guards - begin]===============================================

#ifndef _MUSIC_H_
#define _MUSIC_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void musicInit();
void songPlayingWrite( bool state );
void setMusicDutyCycle(float dutyCycle);

void playSong1();
void playSong2();
void playSong3();
void playSong4();

void setMusic(char song);
void stopMusic();

//=====[#include guards - end]=================================================

#endif // _MUSIC_H_
