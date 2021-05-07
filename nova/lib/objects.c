#include "objects.h"

String createString(string text) {
    int len = strlen(text);

    Char end = malloc(sizeof(Char));
    String str = malloc(sizeof(String));
    
    end->value = '\0';
    end->next = NULL;
    str->start = NULL;
    str->end = end;
    str->length = len;

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
    str->length += 1;
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
    else if (strcmp(type, ARRAY) == false) {
        Array _list = va_arg(ap, Array);
        _var->list = _list;
    }
    else if (strcmp(type, OBJECT) == false) {
        Object _obj = va_arg(ap, Object);
        _var->obj = _obj;
    }
    else if (strcmp(type, BOOLEAN)) {
        boolean _bool = va_arg(ap, boolean);
        _var->_bool = _bool;
    }

    return _var;
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

Array createArray() {
    Array _arr = malloc(sizeof(Array));

    _arr->length = 0;
    _arr->start = NULL;
    _arr->end = NULL;

    return _arr;
}

Object createObj() {
    Object _obj = malloc(sizeof(Object));
    _obj->start = NULL;
    _obj->end = NULL;

    return _obj;
}

void addProperty(Object _obj, string key, Var value) {
    Property _prop = malloc(sizeof(Property));
    _prop->key = key;
    _prop->value = value;
    _prop->next = NULL;

    if (_obj->start) {
        _obj->end->next = _prop;
        _obj->end = _prop;
    }
    else {
        _obj->start = _prop;
        _obj->end = _prop;
    }
}

Var getProp(Object _obj, string key) {
    Property _prop = _obj->start;
    
    while (_prop) {
        if (strcmp(_prop->key, key) == false) {
            return _prop->value;
        }
        _prop = _prop->next;
    }

    return createVar(UNDEFINED);
}

boolean stringCompare(String _string1, String _string2) {
    Char _char1 = _string1->start;
    Char _char2 = _string2->start;

    if (_string1->length != _string2->length) {
        return false;
    }
    else if (_string1->length == 0) {
        return true;
    }
    else {
        while (_char1) {
            if (_char1->value != _char2->value) {
                return false;
            }
            _char1 = _char1->next;
            _char2 = _char2->next;
        }

        return true;
    }
}

