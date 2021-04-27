#include "snake.h"

SnakeHead createSnake(int length, Surface surface)
{
    SnakeHead snakeHead = malloc(sizeof(SnakeHead));
    snakeHead->x = surface.width / 2;
    snakeHead->y = surface.height / 2;
    snakeHead->length = length;
    snakeHead->direction = RIGHT;

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

void moveSnake(SnakeHead head, Surface surface)
{
    NodeBody now = head->end;

    while (now)
    {
        NodeBody next = now->before;
        
        if (next)
        {
            now->x = next->x;
            now->y = next->y;
        }
        else {
            now->x = head->x;
            now->y = head->y;
        }

        now = next;
    }
    

    switch (head->direction)
    {
        case UP:
            if (head->y == 0)
                head->y = surface.height - 1;
            else head->y -= 1;

            break;
        case RIGHT:
            if (head->x == surface.width - 1)
                head->x = 0;
            else head->x += 1;

            break;
        case LEFT:
            if (head->x == 0)
                head->x = surface.width - 1;
            else head->x -= 1;
            
            break;
        case DOWN:
            if (head->y == surface.height - 1)
                head->y = 0;
            else head->y += 1;

            break;
    }

    int x = head->x;
    int y = head->y;
    
    if (surface.units[x][y] == '*')
    {
        head->eat = true;
       
        NodeBody new = malloc(sizeof(NodeBody));
        new->x = head->end->x;
        new->y = head->end->y;
        new->before = head->end;
        new->next = NULL;
        
        head->length++;
        head->end->next = new;
        head->end = new;
    }
    else {
        head->eat = false;
    }
}

void checkColision(SnakeHead head)
{
    NodeBody now = head->start;

    while(now)
    {
        if (now->x == head->x && now->y == head->y)
            exit(1);

        now = now->next;
    }
}

void printSnake(SnakeHead snake)
{
    NodeBody now = snake->start;
    NodeBody next = now->next;

    int len = 0;
    int count = 0;

    printf("Head: x: %i, y: %i\n", snake->x, snake->y);

    while (now)
    {
        count++;
        len++;
        printf("Node %i: x: %i, y: %i\n", count, now->x, now->y);
        
        now = now->next;
    }
    printf("Length: %i\n", len);
}

Apple createApple(Surface surface)
{
    Apple apple;
    apple.x = rand() % (surface.width - 1);
    apple.y = rand() % (surface.height - 1);

    return apple;  
}
