#ifndef _OBJECTS_
#define _OBJECTS_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#define STRING "string"
#define INT "int"
#define FLOAT "float"
#define ARRAY "array"
#define OBJECT "object"
#define UNDEFINED "undefined"

// Define Objects and structs

typedef char * string;
typedef struct line * Line;
typedef struct _string * String;
typedef struct _char * Char;
typedef struct var * Var;
typedef struct array * Array;
typedef struct node * Node;
typedef struct object * Object;
typedef struct property * Property;

typedef enum { false, true } boolean;

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

struct var {
    String str;
    int intValue;
    double floatValue;
    Array list;
    Object obj;
    
    string type;
};

struct array {
    Node start;
    Node end;
    unsigned int length;
};

struct node {
    Var entity;
    Node next;
    Node prev;
};

struct property {
    string key;
    Var value;
    Property next;
};

struct object {
    Property start;
    Property end;
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

#endif