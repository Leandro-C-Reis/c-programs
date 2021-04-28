#ifndef _OBJECTS_
#define _OBJECTS_

typedef struct _int{
    int value;
    char * type;
} Int;

typedef struct _float{
    float value;
    char * type;
} Float;

typedef struct _char{
    char value;
    char * type;
} Char;

typedef struct _string{
    char * value;
    char * type;
} String;

typedef Int (* Constructor)(int i);

typedef struct _console {
    Constructor log;
} Console;

#endif