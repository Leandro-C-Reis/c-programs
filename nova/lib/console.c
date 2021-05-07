#include "console.h"

boolean break_line = true;
int tab_size = 0;

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

void printString(String str, boolean quotes) {
    Char now = str->start;
    
    if (quotes) printf("\"");
    while (now)
    {
        printf("%c", now->value);
        now = now->next;
    }
    if (quotes) printf("\"");
}

void printFloat(double _value) {
    printf("%f", _value);
}

void printInt(int _value) {
    printf("%i", _value);
}

void printBool(boolean _val) {
    if (_val == true) {
        printf("true");
    }
    else {
        printf("false");
    }
}

void printObj(Object _obj) {
    if (!_obj->start) {
        printf("{}");
        return;
    }

    break_line = false;

    printf("{\n");
    tab_size += 4;

    Property prop = _obj->start;
    String tab = createString("\0");
    
    for (int i = 0; i < tab_size; i++) {
        pushChar(tab, ' ');
    }

    while (prop) {
        printString(tab, false);
        printf("%s: ",prop->key);
        print(prop->value);
        
        if (prop->next) printf(",\n");
        else printf("\n");

        prop = prop->next;
    }

    tab_size -= 4;
    free(tab);
    tab = createString("\0");
    for (int i = 0; i < tab_size; i++) {
        pushChar(tab, ' ');
    }

    printString(tab, false);
    printf("}");

    if (tab_size == 0) break_line = true;
}

void print(Var _var) {
    if (strcmp(_var->type, STRING) == false) {
        printString(_var->str, true);
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
    else if (strcmp(_var->type, OBJECT) == false) {
        printObj(_var->obj);
    }
    else if (strcmp(_var->type, UNDEFINED) == false) {
        printf("undefined");
    }
    else if (strcmp(_var->type, BOOLEAN) == false) {
        printBool(_var->_bool);
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
