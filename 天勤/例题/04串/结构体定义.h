//
// Created by roguelxx on 19-3-21.
//

#define maxSize 10

typedef struct fixedStr{
    char ch[maxSize + 1];
    int length;
} fixedStr;

typedef struct dynamicStr{
    char *ch;
    int length;
} dynamicStr;
