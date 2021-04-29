#ifndef _OBJECTS_
#define _OBJECTS_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING "string"
#define INT "int"
#define FLOAT "float"

// Define Objects and structs

typedef char * string;
typedef struct line * Line;
typedef struct _string * String;
typedef struct _char * Char;

struct _char {
    Char next;
    char value;
};

struct _string {
    Char start;
    Char end;
};

struct line {
    String str;
    Line next;
};

// STRING FUNCTIONS

/**
 * Receive a pointer to characters chain,
 * parse to String format and return it
*/
String createString(string);

/**
 * Receive a String object and split in break
 * lines character and return Line object
*/
Line splitLine(String);

/**
 * Receive a String object, one char and put
 * the char into String
*/
void pushChar(String, char);

/**
 * Format and print on screen String object
*/
void printString(String);

#endif