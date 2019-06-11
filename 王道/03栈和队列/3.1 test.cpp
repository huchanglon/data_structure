//
// Created by roguelxx on 19-6-11.
//

/*
 * 假设以I和O分别表示入栈和出栈操作,栈的初态和终态均为空,入栈和出栈的操作
 * 序列可表示为仅由I和O组成的序列,可以操作额序列称为合法序列,设计一个算法,
 * 假设被判定的序列已存入一维数组中,判定所给序列是否合法.合法返回true,反之false. */
bool isLegal(int arr[]) {
    int j = 0, k = 0, i;
    for (i = 0; arr[i] != '\0'; ++i) {
        switch (arr[i]) {
            case 'I':
                ++j;
                break;
            case 'O':
                ++k;
                if (k > j) {
                    printf("非法序列\n");
                    return false;
                }
        }
    }
    if (j != k) {
        printf("非法序列\n");
        return false;
    } else {
        printf("合法序列\n");
        return true;
    }
}

/*
 * 设单链表的表头指针为L,结点结构由data和next构成,其中data域为字符型.设计
 * 一个算法判断链表全部n个字符是否中心对称.
 */
bool isSymmetric(LinkList L, int n) {
    int half = n / 2;
    bool isEven = n % 2 == 0;
    char s[n/2], top = -1;
    LNode *p = L->next;
    while (half > 0) {
        s[++top] = p->data;
        p = p->next;
        --half;
    }
    if (!isEven) {
        p = p->next;
    }
    char q;
    while (p != NULL) {
        if (p->data == s[top]) {
            --top;
        }
        p = p->next;
    }
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

/*
 * 设有两个栈s1,s2都采用顺序栈方式,并共享一个存储区[0,...,maxsize-1],为了尽量
 * 利用空间,减少溢出的可能,采用栈顶相向,迎面增长的存储方式.写出s1,s2出栈入栈的算法.
 * 设s1栈底为0,s2栈底为maxsize-1.top1=-1,top2=maxsize
 */
bool bilateralPush(int i, ElemType x) {
    if (top1 + 1 == top2) {
        return false;
    }
    if (i == 1) {
        s1[++top] = x;
    } else {
        s2[--maxsize] = x;
    }
    return true;
}

bool bilateralPop(int i, ElemType &x) {
    if (i == 1) {
        if (top1 == -1) {
            return false;
        }
        x = s1[top--];
    }
    if (i == 2) {
        if (top2 == maxsize) {
            return false;
        }
        x = s2[top++];
    }
    return true;
}

