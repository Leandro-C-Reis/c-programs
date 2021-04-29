#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


string readFile(FILE * file) {
    int count = 0;
    while (fgetc(file) != EOF)
    {
        count++;
    }

    rewind(file);

    string text = malloc(count * sizeof(char));
    string _char = malloc(sizeof(char));
    
    int c = fgetc(file);

    while (c != EOF)
    {
        _char[0] = c;
        strcat(text, _char);
        c = fgetc(file);
    }

    return text;
}

void printString(String str) {
    Char now = str->start;
    
    while (now)
    {
        printf("%c", now->value);
        now = now->next;
    }

    printf("\n");
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

Line getLine(String text) {
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

int main() {
    FILE * nova_file = fopen("index.nova", "r");
    
    string nova_text = readFile(nova_file);
    String nova_string = createString(nova_text);
    
    Line line = getLine(nova_string);

    fclose(nova_file);
    return 0;
}
