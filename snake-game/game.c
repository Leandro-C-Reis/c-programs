#include "game.h"
#include "termios.h"

clock_t oldTime = 0;

void delay(unsigned int seconds)
{
    unsigned int finishTime = time(0) + seconds;
    while (time(0) < finishTime);
}

void delayMs(unsigned int miliSeconds)
{
    long pause;
    clock_t now, then;

    pause = miliSeconds * (CLOCKS_PER_SEC / 1000);
    now = then = clock();

    while ( (now - then) < pause)
    {
        now = clock();
    }
}

double deltaTime()
{
    float timeSinceStart = clock();
    double deltaTime = timeSinceStart - oldTime;
    oldTime = timeSinceStart;

    return deltaTime;
}

Surface createSurface(unsigned int width, unsigned int height)
{
    Surface surface;

    surface.height = height;
    surface.width = width;

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            surface.units[x][y] = ' ';
        }
    }

    return surface;
}

Surface render(Surface surface, SnakeHead snake, Apple apple)
{
    for (int x = 0; x < surface.width; x++)
    {
        for (int y = 0; y < surface.height; y++)
        {
            surface.units[x][y] = ' ';
        }
    }

    int x = snake->x;
    int y = snake->y;
    surface.units[x][y] = '@';

    NodeBody next = snake->start;

    while (next)
    {
        x = next->x;
        y = next->y;
        next = next->next;
        surface.units[x][y] = '#';
    }

    x = apple.x;
    y = apple.y;

    surface.units[x][y] = '*';

    return surface;
}

int kbhit()
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

void nonblock(int state)
{
    struct termios ttystate;

    //get the terminal state
    tcgetattr(STDIN_FILENO, &ttystate);

    if (state==NB_ENABLE)
    {
        //turn off canonical mode
        ttystate.c_lflag &= ~ICANON;
        //minimum of number input read.
        ttystate.c_cc[VMIN] = 0;
        ttystate.c_cc[VTIME] = 1;
    }
    else if (state==NB_DISABLE)
    {
        //turn on canonical mode
        ttystate.c_lflag |= ICANON;
    }
    //set the terminal attributes.
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);

}

void die(const  char *s)
{
    perror(s);
    exit(1);
}

int editorReadKey() {
    int nread;
    char c = '\0';
    
    nread = read(STDIN_FILENO, &c, 1);
    
    if (c == 'q') die("quit");
    
    if (c == '\x1b')
    {
        char seq[3];
        
        read(STDIN_FILENO, &seq[0], 1);
        read(STDIN_FILENO, &seq[1], 1);
        
        if (seq[0])
        {
            switch (seq[1])
            {
                case 'A': return UP;
                case 'B': return DOWN;
                case 'C': return RIGHT;
                case 'D': return LEFT;
            }
        }
    }
}

void refreshScreen() {
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
}
