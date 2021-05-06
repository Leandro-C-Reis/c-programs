#include "console.h"

boolean break_line = true;

void printArray(Array _arr) {
    break_line = false;
    
    Node _now = _arr->start;

    printf("[");
    while (_now) {
        print(_now->entity);
        if (_now->next) printf(", ");
        _now = _now->next;
    }
    printf("]");

    break_line = true;
}

void printString(String str) {
    Char now = str->start;
    
    while (now)
    {
        printf("%c", now->value);
        now = now->next;
    }
}

void printFloat(double _value) {
    printf("%f", _value);
}

void printInt(int _value) {
    printf("%i", _value);
}

void print(Var _var) {
    if (strcmp(_var->type, STRING) == false) {
        printString(_var->str);
    }
    else if (strcmp(_var->type, INT) == false) {
        printInt(_var->intValue);
    }
    else if (strcmp(_var->type, FLOAT) == false) {
        printFloat(_var->floatValue);
    }
    else if (strcmp(_var->type, ARRAY) == false) {
        printArray(_var->list);
    }

    if (break_line) {
        printf("\n");
    }
}

Console createConsole() {
    Console con;
    con.log = print;
    return con;
}
