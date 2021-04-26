#ifndef _SNAKE
#define _SNAKE

#include <stdlib.h>
#include "game.h"

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
    NodeBody start;
    NodeBody end;
} * SnakeHead;


SnakeHead createSnake(int);

#endif