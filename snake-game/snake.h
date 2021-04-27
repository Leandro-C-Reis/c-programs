#ifndef _SNAKE
#define _SNAKE

#include <stdlib.h>
#include "game.h"

#define UP 100
#define RIGHT 101
#define LEFT 102
#define DOWN 103

typedef struct nodeBody *NodeBody;

struct nodeBody
{
    int x;
    int y;
    NodeBody before;
    NodeBody next;
};

typedef struct snakeHead
{
    int x;
    int y;
    int length;
    int8_t direction;
    bool eat;
    NodeBody start;
    NodeBody end;
} * SnakeHead;

typedef struct apple {
    int x;
    int y;
} Apple;

SnakeHead createSnake(int, Surface);

#endif