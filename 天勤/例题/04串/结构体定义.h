//
// Created by roguelxx on 19-3-21.
//

#define maxSize 100

typedef struct fixedStr{
    char str[maxSize + 1];
    int length;
} fixedStr;

typedef struct dynamicStr{
    char *ch;
    int length;
} dynamicStr;
