//
// Created by roguelxx on 19-3-27.
//

#include <string.h>
#include <malloc.h>
#include "结构体定义.h"

/*
 * 将串str中所有值为ch1的字符转换成ch2的字符,如果str为空串,
 * 或者串中不含值为ch1的字符,则什么都不做
 */

void replace(dynamicStr &str, char ch1, char ch2) {
    int i = 0;
    while (i < str.length) {
        if (str.ch[i] == ch1) {
            str.ch[i] = ch2;
        }
        ++i;
    }
}

/*
 * 实现串str的逆转函数,如果str为空串,则什么都不在.
 */

void reverse(dynamicStr &str) {
    if (str.length == 0) {
        return;
    }
    int i = str.length - 1, j = 0;
    char temp;
    while (j < i) {
        temp = str.ch[i];
        str.ch[i] = str.ch[j];
        str.ch[j] = temp;
        --i;
        ++j;
    }
}

/*
 * 删除str中值为ch的所有字符,如果str为空串,或者串中不含值为ch的字符,则什么都不做
 */
void delChar3(dynamicStr &str, char ch) {
    int ch_num = 0;
    if (str.length != 0) {
        int i = 0, j;
        while (str.ch[i] != '\0') {
            if (str.ch[i] == ch) {
                ++ch_num;
                for (j = i + 1; str.ch[j] != ch && str.ch[j] != '\0'; ++j) {
                    str.ch[j - ch_num] = str.ch[j];
                }
                i = j;
                --str.length;
            } else {
                ++i;
            }
        }
        str.ch[str.length] = '\0';
    }
}

void delChar2(dynamicStr &str, char ch) {
    if (str.length != 0) {
        int sum = 0;
        int i, j;
        for (i = 0; i < str.length; ++i) {
            if (str.ch[i] == ch) {
                ++sum;
            }
        }
        if (sum != 0) {
            char *temp = (char *) malloc(sizeof(str.length - sum + 1));
            for (i = 0, j = 0; i < str.length - 1; ++i) {
                if (str.ch[i] != ch) {
                    temp[j++] = str.ch[i];
                }
            }
            temp[j] = '\0';
            str.length = str.length - sum;
            free(str.ch);
            str.ch = temp;
        }
    }
}

void delChar(dynamicStr &str, char ch) {
    if (str.length == 0) {
        return;
    }
    int i = 0, j;
    while (i < str.length) {
        if (str.ch[i] == ch) {
            j = i;
            while (j < str.length - 1) {
                str.ch[j] = str.ch[j + 1];
                ++j;
            }
            --str.length;
        }
        ++i;
    }
    str.ch[str.length] = '\0';
}

/*
 * 从串str中的pos位置起,求出与substr串匹配的子串的位置,
 * 如果str为空串,或者传中不含与substr匹配的子串,返回-1.
 */

void getNextVal(dynamicStr str, int next[]) {
    int i = 0, j = -1;
    next[i] = j;
    while (i < str.length - 1) {
        if (j == -1 || str.ch[i] == str.ch[j]) {
            ++i;
            ++j;
            if (str.ch[i] != str.ch[j]) {
                next[i] = j;
            } else {
                next[i] = next[j];
            }
        } else {
            j = next[j];
        }
    }
}

int KMPmatch(dynamicStr str, dynamicStr substr, int pos, int next[]) {
    int j = 0;
    int i = pos;
    while (i < str.length && j < substr.length) {
        if (j == -1 || str.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j == substr.length) {
        return i - substr.length;
    } else {
        return -1;
    }
}

/*
 * 采用定长顺序存储表示串,编写一个函数,删除串中从下标为i的字符开始j个字符,
 * 如果第i个字符后没有足够的j个字符,则有几个删除几个.
 * 0,1,2,3,4
 */

void delBatch(fixedStr &str, int i, int j) {
    int k;
    for (k = i + j; k < str.length; ++k) {
        str.ch[k - j] = str.ch[k];
    }
    str.length = str.length < i + j ? i : j;
    str.ch[str.length] = '\0';
}

/*
 * 采用顺序存储方式存储串,编写一个函数,将串str1中的下标i到下标j之间的字符,
 * (包括i和j两个位置上的字符)用str2替换.
 */

int subString(dynamicStr &substr, dynamicStr str, int pos, int length) {
    if (pos < 0 || pos > str.length - 1 || length < 0 || pos + length > str.length) {
        return -1;
    }
//    if (substr.ch) {
//        free(substr.ch);
//        substr.ch = NULL;
//    }
    if (length == 0) {
        substr.ch = NULL;
        substr.length = 0;
        return 1;
    } else {
        substr.ch = (char *) malloc(sizeof(char) * (length + 1));
        int i = pos;
        int j;
        if (substr.ch != NULL) {
            for (j = 0; j < length; ++j, ++i) {
                substr.ch[j] = str.ch[i];
            }
        }
        substr.ch[j] = '\0';
        return 1;
    }
}
int concat(dynamicStr &str, dynamicStr str1, dynamicStr str2) {
//    if (str.ch) {
//        free(str.ch);
//        str.ch = NULL;
//    }
    str.ch = (char *) malloc(sizeof(char) * (str1.length + str2.length + 1));
    int i = 0;
    while (i < str1.length) {
        str.ch[i] = str1.ch[i];
        ++i;
    }
    int j = 0;
    while (j <= str2.length) {
        str.ch[i + j] = str2.ch[j];
        ++j;
    }
    str.length = str1.length + str2.length;
    return 1;
}

int replaceAll();

void testReplaceAll() {
    struct dynamicStr string1;
    struct dynamicStr string2;
    char str1[] = "aaadef";
    char str2[] = "bc";
    string1.ch = str1;
    string2.ch = str2;
    string1.length = strlen(str1);
    string2.length = strlen(str2);
//    replaceAll(string1, string2, 1, 2);
//    printf("%s", string1.ch);
}

void testMatch() {
    struct dynamicStr string1;
    struct dynamicStr string2;
    char str1[] = "aaabcd";
    char str2[] = "abc";
    string1.ch = str1;
    string2.ch = str2;
    string1.length = strlen(str1);
    string2.length = strlen(str2);
    int next[string2.length];
    getNextVal(string2, next);
    int i = KMPmatch(string1, string2, 0, next);
    printf("%d", i);
}

void testDelChar() {
    struct dynamicStr string1;
    char str1[] = "abcdefg";
    char ch = 'c';
    string1.ch = str1;
    string1.length = strlen(str1);
    delChar(string1, ch);
    printf("%s", string1.ch);
}

void testReverse() {
    struct dynamicStr string1;
    char str1[] = "ab  ";
    string1.ch = str1;
    string1.length = strlen(str1);
    reverse(string1);
    printf("%s", string1.ch);
}

void testReplace() {
    struct dynamicStr string1;
    char str1[] = "abccccdefg";
    char ch1 = ' ';
    char ch2 = '1';
    string1.ch = str1;
    string1.length = strlen(str1);
    replace(string1, ch1, ch2);
    printf("%s", string1.ch);
}

int main() {
//    testReplace();
//    testReverse();
//    testDelChar();
//    testMatch();
    testReplaceAll();
}
