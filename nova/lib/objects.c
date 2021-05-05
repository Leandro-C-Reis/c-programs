#include "objects.h"

void printString(String str) {
    Char now = str->start;
    
    while (now)
    {
        printf("%c", now->value);
        now = now->next;
    }
}

String createString(string text) {
    int len = strlen(text);

    Char end = malloc(sizeof(Char));
    String str = malloc(sizeof(String));
    
    end->value = '\0';
    end->next = NULL;
    str->start = NULL;
    str->end = end;

    if (!len) {
        str->start = end;
        return str;
    }

    Char bef = malloc(sizeof(Char));

    for (int i = 0; i < len; i++) {
        Char _char = malloc(sizeof(Char));
        _char->value = text[i];
        _char->next = end;   
        bef->next = _char;

        if (!str->start) {
            str->start = _char;
        }

        bef = _char;
    }

    return str;
}

void pushChar(String str, char c) {
   
    Char _char = malloc(sizeof(Char));
    Char _nullChar = malloc(sizeof(Char));

    _char->value = c;
    _nullChar->value = '\0';
    _nullChar->next = NULL;
    _char->next = _nullChar;

    str->end->next = _char;
    str->end = _char;
}

Line splitLine(String text) {
    Line start = malloc(sizeof(Line));
    Line last = start;

    Char _char = text->start;
    String str = createString("\0");
    
    start->str = str;
    start->next = NULL;

    while (_char) {
        if (_char->value == '\n') {
            Line new_line = malloc(sizeof(Line));
            str = createString("\0");
            
            new_line->str = str;
            new_line->next = NULL;

            last->next = new_line;
            
            last = new_line;
        }
        else {
            pushChar(str, _char->value);
        }
        
        _char = _char->next;
    }
    
    return start;
}

Var createVar(string type, ...) {
    va_list ap;
    va_start(ap, type);
    
    Var _var = malloc(sizeof(Var));
    _var->type = malloc(sizeof(type));
    _var->type = type;

    if (strcmp(type, STRING) == false) {
        _var->str = createString(va_arg(ap, string));
    }
    else if (strcmp(type, INT) == false) {
        int _value = va_arg(ap, int);
        _var->intValue = _value;
    }
    else if (strcmp(type, FLOAT) == false) {
        double _value = va_arg(ap, double);
        _var->floatValue = _value;
    }

    return _var;
}

void printFloat(double _value) {
    printf("%f", _value);
}

void printInt(int _value) {
    printf("%i", _value);
}

void print(Var _var, boolean break_line) {
    if (strcmp(_var->type, STRING) == false) {
        printString(_var->str);
    }
    else if (strcmp(_var->type, INT) == false) {
        printInt(_var->intValue);
    }
    else if (strcmp(_var->type, FLOAT) == false) {
        printFloat(_var->floatValue);
    }

    if (break_line) {
        printf("\n");
    }
}

Array createArray() {
    Array _arr = malloc(sizeof(Array));

    _arr->length = 0;
    _arr->start = NULL;
    _arr->end = NULL;

    return _arr;
}

void push(Array _arr, Var _entity) {
    Node _node = malloc(sizeof(Node));
    _node->entity = _entity;
    _node->prev = NULL;
    _node->next = NULL;
    
    if (_arr->length == 0) {
        _arr->start = _node;
        _arr->end = _node;
    }
    else {
        _arr->end->next = _node;
        _node->prev = _arr->end;
        _arr->end = _node;
    }

    _arr->length++;
}

void printArray(Array _arr) {
    Node _now = _arr->start;

    printf("[");
    while (_now) {
        print(_now->entity, false);
        printf(", ");
        _now = _now->next;
    }
    printf("]\n");
}
