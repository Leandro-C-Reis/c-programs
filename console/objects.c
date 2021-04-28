#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "./Headers/objects.h"

Int createInt(int value) {
    Int _int;
    _int.value = value;
    _int.type = "Int";

    return _int;
}

Float createFloat(float value) {
    Float _float;
    _float.value = value;
    _float.type = "Float";

    return _float;
}

Char createChar(char value) {
    Char _char;
    _char.value = value;
    _char.type = "Char";

    return _char;
}

String createString(char * value) {
    String _string;
    _string.value = value;
    _string.type = "String";

    return _string;
}

void printInt(Int object) {
    printf("%d", object.value);
    printf("\n"); 
}

void printFloat(Float object) {
    printf("%f", object.value);
    printf("\n"); 
}

void printChar(Char object) {
    printf("%c", object.value);
    printf("\n"); 
}

void printString(String object) {
    printf("%s", object.value);
    printf("\n"); 
}

void print(int count, ...)
{
    va_list list;

    va_start(list, count);

}