//
// Created by roguelxx on 19-3-22.
//
#include "结构体定义.h"

/*
 * KMP算法
 */
void getnext(dynamicStr substr, int next[]) {
    next[1] = 0;
    int i = 1, j = 0;
    while (i < substr.length) {
        if (j == 0 || substr.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

void getNextVal(dynamicStr substr, int nextval[]) {
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < substr.length) {
        if (j == 0 || substr.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
            if (substr.ch[i] != substr.ch[j]) {
                nextval[i] = j;
            } else {
                nextval[i] = nextval[j];
            }
        } else {
            j = nextval[j];
        }
    }
}

int KMP(dynamicStr str, dynamicStr substr, int next[]) {
    int i = 1, j = 1;
    while (i <= str.length && j <= substr.length) {
        if (j == 0 || str.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j > substr.length) {
        return i - substr.length;
    } else {
        return 0;
    }
}


