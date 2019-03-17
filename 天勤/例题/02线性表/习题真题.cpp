#include <cstdio>
#include <malloc.h>
#include "结构体定义.h"

//
// Created by roguelxx on 19-3-16.
//
/*
 * 1.2).(3)
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
 * 1.2).(4)
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

/*
 * (5)
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
 * (6)
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

int main() {

}

