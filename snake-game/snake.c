#include "snake.h"

SnakeHead createSnake(int length)
{
    SnakeHead snakeHead = malloc(sizeof(SnakeHead));
    snakeHead->x = surface.width / 2;
    snakeHead->y = surface.height / 2;
    snakeHead->length = length;
    length--;

    NodeBody start = malloc(sizeof(NodeBody));
    NodeBody before = malloc(sizeof(NodeBody));

    start->x = snakeHead->x - 1;
    start->y = snakeHead->y;
    start->before = NULL;
    start->next = NULL;

    before = start;

    for (int i = 1; i < length; i++)
    {
        NodeBody node = malloc(sizeof(NodeBody));
        node->x = before->x - 1;
        node->y = before->y;

        before->next = node;
        node->before = before;
        node->next = NULL;

        before = node;
        snakeHead->end = node;
    }

    snakeHead->start = start;

    return snakeHead;
}