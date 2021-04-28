#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char * string;

typedef struct line * Line;

struct line {
    string str;
    Line next;
};

string readFile(FILE * file)
{
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

Line getLine(string text) {
    size_t len = strlen(text);

    Line start = malloc(sizeof(Line));
    Line l = start;

    int start_of_line = 0;
    
    for (int i = 0; i < len; i++) {
        char c = text[i];
        
        if (c == '\n');
        {
            string str = malloc((i - start_of_line) * sizeof(char));

            for (int j = start_of_line; j < i; j++) {
                string _char = '\0';
                _char[0] = text[j];

                strcat(str, _char);
            }

            Line newL = malloc(sizeof(Line));

            l->str = str;
            l->next = newL;
            l = newL;

            start_of_line = i + 1;
        }
    }

    return start;
}

int main() {
    FILE * nova_file = fopen("index.nova", "r");
    
    string nova_text = readFile(nova_file);

    Line line = getLine(nova_text);

    printf("%s", line->str);


    fclose(nova_file);
    return 0;
}