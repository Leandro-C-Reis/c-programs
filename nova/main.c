#include "lib/objects.c"
#include "lib/console.c"
#include "lib/transpiler.c"

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

int main() {
    Console console = createConsole();
    FILE * nova_file = fopen("index.nova", "r");
    
    string nova_text = readFile(nova_file);
    String nova_string = createString(nova_text);
    Line line = splitLine(nova_string);

    // transpile_v1(nova_string);
    
    fclose(nova_file);
    return 0;
}
