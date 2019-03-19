//
// Created by roguelxx on 19-3-16.
//

#include <iostream>
#include "结构体定义.h"

/*
 * 设顺序表用数组A[]表示，表中元素存储在数组下标 0~m+n-1 的范围内，
 * 前m个元素递增有序，后n个元素也递增有序，设计一个算法，使整个顺序表有序。
 * 时间复杂度为O(mn)，空间复杂度为O(1)
 */
void insertElem(int A[], int m, int n) {
    int temp; // 辅助变量，用来暂存带插入元素
    int i, j;
    for (i = m; i < m + n; ++i) {
        temp = A[i];
        for (j = i - 1; j >= 0 && temp < A[j]; --j) {
            A[j + 1] = A[j];
        }
        A[j + 1] = temp;
    }
}

/*
 * 已知递增有序单链表A、B(A、B中元素个数分别为m、n，且A、B都带有头结点)，
 * 分别存储了一个集合，请设计算法，求两个集合A和B的差集A-B，
 * 即仅在A中出现而不在B中出现的元素所构成的集合，差集保存在单链表A中，
 * 并保持元素的递增有序性
 */
void difference(LNode *A, LNode *B) {
    LNode *p = A->next, *q = B->next;
    LNode *pre = A; // A中p所指结点的前驱结点的指针
    LNode *r;
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            pre=p;
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else {
            pre->next = p->next;
            r = p;
            p = p->next;
            free(r);
        }
    }
}

