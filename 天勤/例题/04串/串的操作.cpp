//
// Created by roguelxx on 19-3-21.
//

#include <malloc.h>
#include "结构体定义.h"

/*
 * 赋值操作
 */

int strAssign(dynamicStr &str, char *ch) {
    if (str.ch) {
        free(str.ch);
    }
    int length = 0;
    int i = 0;
    char *c = ch;
    while (*c) {
        ++length;
        ++c;
    }
    if (length == 0) {
        str.ch = NULL;
        str.length = 0;
        return 1;
    } else {
        str.ch = (char *) malloc(sizeof(char) * (length + 1));
        // 分配存储空间成功返回起始地址的指针,失败返回NULL
        if (str.ch == NULL) {
            return 0;
        } else {
            // 将c重新指向串数组起始指针
            c = ch;
            for (i = 0; i <= length; ++i, ++c) {
                str.ch[i] = *c;
            }
            str.length = length;
            return 1;
        }
    }
}

/*
 * 串比较操作
 */
int strCompare(dynamicStr str1, dynamicStr str2) {
    for (int i = 0; i < str1.length && i < str2.length; ++i) {
        if (str1.ch[i] != str2.ch[i]) {
            return str1.ch[i] - str2.ch[i];
        }
    }
    return str1.length - str2.length;
}

/*
 * 串连接操作:将两个串首尾相连,合并成一个字符串的操作
 */
int concat(dynamicStr &str, dynamicStr str1, dynamicStr str2) {
    if (str.ch) {
        free(str.ch);
        str.ch = NULL;
    }
    str.ch = (char *) malloc(sizeof(char) * (str1.length + str2.length + 1));
    if (str.ch == NULL) {
        return 0;
    }
    int i = 0, j = 0;
    while (i < str1.length) {
        str.ch[i] = str1.ch[i];
        ++i;
    }
    // 去等为了复制str中的'\0'
    while (j <= str2.length) {
        str.ch[i + j] = str2.ch[j];
        ++j;
    }
    str.length = str1.length + str2.length;
    return 1;
}

/*
 * 求子串操作
 * pos - 索引
 */
int subSting(dynamicStr &substr, dynamicStr str, int pos, int length) {
    if (pos < 0 ||
        pos >= str.length ||
        length < 0 ||
        length > str.length - pos) {
        return 0;
    }
    if (substr.ch) {
        free(substr.ch);
        substr.ch = NULL;
    }
    if (length == 0) {
        substr.ch = NULL;
        substr.length = 0;
        return 1;
    } else {
        substr.ch = (char *) malloc(sizeof(char) * length);
        int i = pos;
        int j = 0;
        while (i < pos + length) {
            substr.ch[j] = str.ch[i];
            ++i;
            ++j;
        }
        substr.ch[j] = '\0';
        substr.length = length;
        return 1;
    }
}

/*
 * 清空串操作
 */
int clearString(dynamicStr &str) {
    if (str.ch) {
        free(str.ch);
        str.ch = NULL;
    }
    str.length = 0;
    return 1;
}
int main() {
    struct dynamicStr string;
    char str[] = "hello world!";
    strAssign(string, str);
    printf("%s", string.ch);
}
