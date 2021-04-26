#ifndef GAME_H
#define GAME_H

#include <time.h>

typedef struct surface
{
    int width;
    int height;
} Surface;

Surface surface;

void delay(unsigned int);

#endif