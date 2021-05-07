#include "objects.c"

#define PRINT "print"

typedef struct item * Item;
typedef struct var_list * VarList;

struct item {
    Var value;
    String name;
    Item next;
};

struct var_list {
    Item start;
    Item end; 
};

VarList createVarList() {
    VarList self = malloc(sizeof(VarList));
    self->start = NULL;
    self->end = NULL;
    return self;
}

Var getByName(VarList _list, String _varname) {
    Item _item = _list->start;

    while (_item) {
        if (stringCompare(_varname, _item->name)) {
            return _item->value;
        }
        _item = _item->next;
    }

    return createVar(UNDEFINED);
}

void pushVar(VarList _list, Var _var, String _varname) {
    Item _item = malloc(sizeof(Item));
    _item->value = _var;
    _item->next = NULL;
    _item->name = _varname;

    if (_list->start) {
        _list->end->next = _item;
    }
    else {
        _list->start = _item;
    }
    _list->end = _item;
}

void transpile_v1(String program) {
    Char c = program->start;
    VarList _vars = createVarList();

    while (c) {
        String text = createString("");
        
        if (c->value >= 65 && c->value <= 90) {
            pushChar(text, c->value);
        }
        else if (c->value >= 97 && c->value <= 122) {
            pushChar(text, c->value);
        }
        else if (c->value == ' ') {
            while (c->value != '=') {
                c = c->next;
            }
        }

    }

}
