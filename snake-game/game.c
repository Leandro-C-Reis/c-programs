#include "game.h"

void delay(unsigned int seconds)
{
    unsigned int finishTime = time(0) + seconds;
    while (time(0) < finishTime);
}