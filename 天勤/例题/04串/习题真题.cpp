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
 * (包括i和j两个位置上的字符)用串str2替换.
 */

int subString(dynamicStr &substr, dynamicStr str, int pos, int length) {
    if (pos < 0 || pos > str.length - 1 || length < 0 || pos + length > str.length) {
        return -1;
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
        substr.ch = (char *) malloc(sizeof(char) * (length + 1));
        int i = pos;
        int j;
        if (substr.ch != NULL) {
            for (j = 0; j < length; ++j, ++i) {
                substr.ch[j] = str.ch[i];
                ++substr.length;
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
    if (str.ch == NULL) {
        return -1;
    }
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

int replaceAll(dynamicStr &str1, dynamicStr str2, int i, int j) {
    dynamicStr substr1;
    substr1.ch = NULL;
    substr1.length = 0;
    dynamicStr substr2;
    substr2.ch = NULL;
    substr2.length = 0;
    dynamicStr tempstr;
    if (subString(substr1, str1, 0, i) == -1) {
        return 0;
    }
    if (subString(substr2, str1, j + 1, str1.length - j - 1) == -1) {
        return 0;
    }
    if (concat(tempstr, substr1, str2) == -1) {
        return 0;
    }
    if (concat(str1, tempstr, substr2) == -1) {
        return 0;
    }
    return 1;
};

/*
 * 编写一个函数,计算一个子串在一个主串中出现的次数,
 * 如果该子串不出现,则返回0.不考虑子串重叠.
 * 如:主串为aaaa,子串为aaa,考虑子串重叠结构为2,不考虑子串重叠结果为1
 */

int matchCount (dynamicStr str, dynamicStr substr, int next[]) {
    int i = 0, j = -1, k = 0;
    while (i < str.length) {
        if (j == 0 && i > str.length - substr.length) {
            return k;
        }
        if (j == -1 || str.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
        if (j == substr.length) {
            ++k;
            j = 0;
        }
    }
    return k;
}

/*
 * 构造串的链表结点数据结构(每个结点内存储一个字符),编写一个函数,找到串str1中第一个不在str2中出现的字符
 */

typedef struct StrNode {
   char data;
   struct StrNode *next;
} StrNode;

char findFirst(StrNode *str1, StrNode *str2) {
    for (StrNode *p = str1; p != NULL; p = p->next) {
        bool flag = false;
        for (StrNode *q = str2; q != NULL; q = q->next) {
            if (p->data == q->data) {
                flag = true;
                break;
            }
            if (flag == false) {
                return p->data;
            }
        }
    }
    return '\0';
}

char exclude(StrNode *str1, StrNode *str2) {
    StrNode *p = str1;
    StrNode *q = str2;
    while (p->next != NULL) {
        if (p->next->data != q->next->data) {
            q = q->next;
            if (q == NULL) {
                return p->next->data;
            }
        } else {
            p = p->next;
            q = str2;
        }
    }
    return '\0';
}

void testMatchCount() {
    struct dynamicStr string1;
    struct dynamicStr string2;
    char str1[] = "aaabcccabc";
    char str2[] = "abc";
    string1.ch = str1;
    string2.ch = str2;
    string1.length = strlen(str1);
    string2.length = strlen(str2);
    int next[string2.length];
    getNextVal(string2, next);
    int i = matchCount(string1, string2, next);
    printf("%d", i);
}

void testReplaceAll() {
    struct dynamicStr string1;
    struct dynamicStr string2;
    char str1[] = "aaadef";
    char str2[] = "bc";
    string1.ch = str1;
    string2.ch = str2;
    string1.length = strlen(str1);
    string2.length = strlen(str2);
    replaceAll(string1, string2, 1, 2);
    printf("%s", string1.ch);
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
//    testReplaceAll();
    testMatchCount();
}
