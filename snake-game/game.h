#ifndef GAME_H
#define GAME_H

#include <time.h>

#define NB_ENABLE 1
#define NB_DISABLE 0

typedef struct surface
{
    int width;
    int height;
    char units[100][50];
} Surface;

Surface surface;

void delay(unsigned int);

#endif