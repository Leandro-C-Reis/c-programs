#include <stdio.h>

#include "snake.c"
#include "game.c"

enum boolean
{
    false = 0,
    true = 1
};

void game();
void drawScreen(SnakeHead snake);
Surface surface;

int main()
{
    game();

    return 0;
}

void game()
{
    surface.height = 10;
    surface.width = 20;

    SnakeHead snake = createSnake(4);
    
    clock_t oldTime = clock();
    while (true)
    {
        // drawScreen(snake);

        clock_t deltaTime= clock() - oldTime;
        double fps = (1.0 / deltaTime) * 1000;
        oldTime = clock();
        delay(1);

        printf("%.2ld\n", clock());
    }
}

void drawScreen(SnakeHead snake)
{
    system("clear");

    for (int y = 0; y < surface.height; y++)
    {
        for (int x = 0; x < surface.width; x++)
        {
            if (x == snake->x && y == snake->y)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}