#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>

#include "snake.c"
#include "game.c"

void game();
void drawScreen();
Surface SURFACE;

int main()
{   
    game();

    return 0;
}

void game()
{
    SURFACE = createSurface(20, 10);

    SnakeHead snake = createSnake(4, SURFACE);
    Apple apple = createApple(SURFACE);
    snake->direction = RIGHT;

    nonblock(NB_ENABLE);

    while (true)
    { 
        moveSnake(snake, SURFACE);
        
        if (snake->eat)
        {
            apple = createApple(SURFACE);

            while(SURFACE.units[apple.x][apple.y] == '@' ||
                SURFACE.units[apple.x][apple.y] == '#')
            {
                apple = createApple(SURFACE);
            }
        }

        SURFACE = render(SURFACE, snake, apple);
        drawScreen();
        checkColision(snake);

        int key = editorReadKey();
        
        switch (key)
        {
            case UP:
                if (snake->direction != DOWN)
                    snake->direction = key;
                break;
            case DOWN:
                if (snake->direction != UP)
                    snake->direction = key;
                break;
            case RIGHT:
                if (snake->direction != LEFT)
                    snake->direction = key;
                break;
            case LEFT:
                if (snake->direction != RIGHT)
                    snake->direction = key;
                break;
        } 

        delayMs(200);
    }

    nonblock(NB_DISABLE);
}

void drawScreen()
{
    refreshScreen();

    for (int y = 0; y < SURFACE.height; y++)
    {
        for (int x = 0; x < SURFACE.width; x++)
        {
            printf("%c", SURFACE.units[x][y]);
        }
        printf("\n");
    }
}
