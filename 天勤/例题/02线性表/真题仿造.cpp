//
// Created by roguelxx on 19-3-16.
//

#include <iostream>
#include "结构体定义.h"

/*
 * 1.
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
//    for (int i = 0; i < m + n; ++i) {
//        temp = A[i];
//        for (int j = i - 1; j >= 0 && temp < A[j]; --j) {
//            A[j + 1] = A[j];
//            A[j] = temp;
//        }
//    }
}

/*
 * 2.
 * 已知递增有序单链表A、B
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
//int main() {
//    int a[6]={ 4,5,6,1,2,3 };
//    int i;
//    insertElem(a, 3, 3);
//    for (i = 0; i<6; i++)
//        scanf("%d", &a[i]);
//    for (i = 0; i<6; i++)
//        printf("%d-", a[i]);
//    printf("\n");
//}

