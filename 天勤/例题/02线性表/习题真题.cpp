#include <cstdio>
#include <malloc.h>
#include "结构体定义.h"

//
// Created by roguelxx on 19-3-16.
//
/*
 * 设计一个算法，将顺序表中的所有元素逆置
 */
void reverse(Sqlist &L) {
    int i, j;
    int temp;
    for (i = 0, j = L.length - 1; i < j; ++i, --j) {
        temp = L.data[i];
        L.data[i] = L.data[j];
        L.data[j] = temp;
    }
}

/*
 * 从给定的顺序表L中删除下标i~j(i<=j, 包括i、j)的所有元素，设i、j都是合法输入。
 */
void deleteBatch(Sqlist &L, int i, int j) {
    int k, delta;
    delta = j - i + 1;
    for (k = j; k < L.length; ++k) {
        L.data[k - delta] = L.data[k];
    }
    L.length -= delta;
}

/* 错题
 * 顺序表L，元素为整型元素，将L中小于表头元素的整数放在前半部分，大于表头元素的整数放在后半部分。
 */
void move(Sqlist &L) {
    int temp;
    int i = 0, j = L.length - 1;
    temp = L.data[i];
    while (i < j) {
        while (i < j && L.data[j] > temp) {
            --j;
        }
        if (i < j) {
            L.data[i] = L.data[j];
            ++i;
        }
        while (i < j && L.data[i] < temp) {
            ++i;
        }
        if (i < j) {
            L.data[j] = L.data[i];
            --j;
        }
    }
    L.data[i] = temp;
}

/*
 * 有一个递增非空单链表，设计一个算法删除值域重复的结点。
 */
void unique1(LNode *&L) {
    LNode *p = L->next;
    LNode *q;
    while (p->next != NULL) {
        if (p->data == p->next->data) {
            q = p->next;
            p->next = p->next->next;
            free(q);
        } else {
            p = p->next;
        }
    }
}
void unique2(LNode *&L) {
    LNode *p = L->next, *q = L->next->next, *r;
    while (q != NULL) {
        while (q != NULL && q->data == p->data) {
            q = q->next;
        }
        if (q != NULL) {
            p = p->next;
            p->data = q->data;
        }
    }
    q = p->next;
    p->next = NULL;
    while (q != NULL) {
        r=q;
        q = q->next;
        free(r);
    }
}

/*
 * 设计一个算法删除单链表L（有头结点）中的一个最小值结点
 */
void deleteMin(LNode *&L) {
    // p - 从头扫描的指针
    // pre - p 前驱
    // minp - 最小值的结点指针
    // minpre - minp 前驱
    LNode *pre = L, *p = pre->next, *minp = p, *minpre = pre;
    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
}

/*
 * 有一个线性表，采用带头结点的单链表L存储。设计一个算法将其逆置。
 * 要求不能建立新结点，只能通过表中已有结点的重新组合完成。
 */
void reverse2(LNode *&L) {
    LNode *p = L->next, *q;
    L->next = NULL;
    while (p != NULL) {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}

/*
 * 设计一个算法，将一个头结点为A的单链表（其数据域为整数）分解成两个单链表A和B，
 * 使得A链表只含有原来链表中data域为奇数的结点，而B链表只含有原链表中data域为偶数的结点，
 * 且保持原来的相对顺序。
 */
void diverse(LNode *A, LNode *&B) {
    LNode *p, *q, *r;
    B = (LNode *) malloc(sizeof(LNode));
    B->next = NULL;
    r = B;
    p = A;
    while (p->next != NULL) {
        if (p->next->data % 2 == 0) {
            q = p->next;
            p->next = q->next;
            q->next = NULL;
            r->next = q;
            r = q;
        } else {
            p = p->next;
        }
    }
}

/*
 * 有N个个位正整数存放在int型数组A[0,...,N-1]中,N为已定义的常量且N<=9,
 * 数组A[]的长度为N,另给一个int型变量i,要求之用上述变量(A[0]~A[N-1]与i),
 * 写一个算法,找出这N个整数中的最小者,并且要求不能破坏数组A[]中的数组.
 */
void findMin(int A[], int &i) {
    i = A[0];
    while (i / 10 < N) {
        if (i % 10 > A[i / 10]) {
            i = i - i % 10;
            i = i + A[i / 10];
        }
        i = i + 10;
    }
    i = i % 10;
}

/*
 * 写一个函数,逆序打印单链表中的数据,假设指针L指向了单链表的开始结点.
 */
void printReverse(LNode *L) {
    if (L != NULL) {
        printReverse(L->next);
        cout << L->data << " ";
    }
}

/*
 * 试编写一个函数,以不多于3n/2的平均比较次数,在一个有n个整数的顺序表A中找出最大值和最小值
 */
void findMax&Min(int A[], int n, int &max, int &min) {
    min = max = A[0];
    int i;
    for (i = 1; i < n; ++i) {
        if (A[i] > max) {
            max = A[i];
        } else if (A[i] < min) {
            min = A[i];
        }
    }
    /*
     * 最坏情况:当表中n个整数按从大到小非递增排列时,数据比较次数为2(n-1)次.
     * 最好情况:当表中n个整数按从小到大递增排列时,数据比较次数为n-1次.
     * A中数据的有序性可以认为是等可能的,因此最好和最坏的情况的概率相同,都是1/2.
     * 综上所述,数据平均比较次数为(2(n-1)+(n-1))/2 = 3n/2-3/2 < 3n/2
     */
}

/*
 * 设A=(a1,a2,a3,...,am)和B=(b1,b2,b3,...,bn)均为顺序表,A'和B'分别是
 * 除去最大公共前缀的子表.若A'=B'=空表,则A=B.若A'=空表且B'≠空表,或两者均不为空
 * 且A'的第一个元素值小于B'的第一个元素值,则A<B,反之A>B.
 * 编写一个函数,比较数组A和B的大小.
 */
int compare(float A[], int An, float B[], int Bn) {
    int i = 0;
    while (i < An && i < Bn) {
        // min是已定义的足够小的数
        if (fabs(A[i] - B[i]) < min) {
            ++i;
        } else {}
        break;
    }
    if (i >= An && i >= Bn) {
        return 0;
    } else if ((i >= An && i < Bn) || A[i] < B[i]) {
        return -1;
    } else {
        return 1;
    }
}

/*
 * 假设该链表只给出了头指针head.在不改变链表的前提下,请设计一个算法,
 * 查找链表中倒数第k个位置上的结点.若查找成功,算法输出该结点的data值,并返回1;反之,返回0.
 */
int findReciprocal(LNode *head, int k) {
    LNode *p1 = head->next;
    LNode *p = head;
    int i = 1;
    while (p1 != NULL) {
        p1 = p1->next;
        ++i;
        if (i >= k) {
            p = p->next;
        }
    }
    if (p == head) {
        return 0;
    } else {
        cout << p->data;
        return 1;
    }
}

/*
 * 设将n(n>1)个整数存放到一维数组R中.设计一个在时间和空间两个方面尽可能高效的算法.
 * 将R中保存的序列循环左移P(0<P<n)个位置.
 */
void reverseArr(int arr[], int n, int m) {
    int i, j, temp;
    for (i = n, j = m; i < j; ++i, --j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
void leftRemove(int R[], int P, int n) {
    reverse(R, 0, P - 1);
    reverse(R, P, n - 1);
    reverse(R, 0, n - 1);
}

/*
 * 已知一个整数序列A=(a0,a1,a2,...,an-1),其中0<=ai<n(0<=i<n).
 * 若存在ap1=ap2=ap3=...-apm=x且m>n/2(0<=pk<n, 1<=k<m),
 * 则称x为A的主元素.假设A中的n个元素保存在一个一位数组中,设计一个算法,
 * 找出A的主元素.若存在,输出该元素;反之,输出-1.
 */
int findMain(int A[], int n) {
    int i, c, count = 1;
    c = A[0];
    for (i = 0; i < n; ++i) {
        if (A[i] == c) {
            ++count;
        } else {
            if (count > 0) {
                count--;
            } else {
                c = A[i];
                count = 1;
            }
        }
    }
    if (count > 0) {
        int i;
        count = 0;
        for (i = 0; i < n; ++i) {
            if (A[i] == c) {
                ++count;
            }
        }
    }
    if (count > n / 2) {
        return c;
    } else {
        return -1;
    }
}