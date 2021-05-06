#ifndef _CONSOLE_
#define _CONSOLE_

#include "objects.h"

typedef void (*Printable)(Var);

typedef struct _con {
    Printable log;
} Console;

void printString(String);

void printInt(int);

void printFloat(double);

void printArray(Array);

void print(Var);

Console createConsole();

#endif