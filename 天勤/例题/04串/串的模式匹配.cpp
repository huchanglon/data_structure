//
// Created by roguelxx on 19-3-21.
//

/*
 * 字符串存储在1~length的位置上
 */

#include <stdio.h>
#include <string.h>
#include "结构体定义.h"

/*
 * 寻找子串索引算法
 */
int index(dynamicStr str, dynamicStr substr) {
    if (str.length < substr.length) {
        return 0;
    }
    int i = 1, j = 1, k = i;
    while (i <= str.length && j <= substr.length) {
        if (str.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
        } else {
            // 匹配失败,j从子串首位开始,i从主串下一位开始,k记录了i上一次的位置
            j=1;
            i = ++k;
        }
    }
    if (j > substr.length) {
        return k;
    } else {
        return 0;
    }
}

int main() {
    struct dynamicStr str1;
    struct dynamicStr str2;
    char ch1[] = "abcdef";
    char ch2[] = "def";
    str1.ch = ch1;
    str1.length = strlen(ch1);
    str2.ch = ch2;
    str2.length = strlen(ch2);
    printf("%d", index(str1, str2));
}
