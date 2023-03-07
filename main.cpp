//=====[Libraries]=============================================================

#include "entertainment_system.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    entertainmentSystemInit();
    while (true) {
        entertainmentSystemUpdate();
    }
}
