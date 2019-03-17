//
// Created by roguelxx on 19-3-15.
//

#include <malloc.h>
#include "结构体定义.h"


/*
 * A和B是两个单链表，其中元素递增有序。
 * 设计一个算法，将A和B归并成一个按元素值非递减有序的链表C，
 * C由A和B中的结点组成
 */
void mergeEnd(LNode *A, LNode *B, LNode *&C){
    LNode *p = A->next;     // 指针变量p用于跟踪A的最小值结点
    LNode *q = B->next;
    LNode *r;               // r始终指向C的终端结点
    C = A;                  // 用A的头结点作为C的头结点
    C->next = NULL;
    free(B);
    r = C;
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            r->next = p;
            p = p->next;
            r = r->next;
        } else {
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }
    r->next = NULL;
    if (p != NULL) {
        r->next = p;
    }
    if (q != NULL) {
        r->next = q;
    }
}

/*
 * 假设有n个元素存储在数组a中，用尾插法建立链表C
 */
void createListEnd(LNode *& list, int a[], int n) {
    LNode *start, *end;
    list = (LNode *) malloc(sizeof(LNode));
    list->next = NULL;
    end = list;
    for (int i = 0; i < n; ++i) {
        start = (LNode *) malloc(sizeof(LNode));
        start->data = a[i];
        end->next = start;
        end = end->next;
    }
    end->next = NULL;
}

/**
 * 与尾插法对应的头插法
 * 新建立的链表中元素的次序和数组a中元素的次序是相反的
 */
void createListFirst(LNode *&list, int a[], int n) {
    LNode *start;
    list = (LNode *) malloc(sizeof(LNode));
    list->next = NULL;
    for (int i = 0; i < n; ++i) {
        start = (LNode *) malloc(sizeof(LNode));
        start->data = a[i];
        start->next = list->next;
        list->next = start;
    }
}

/*
 * A和B是两个单链表，其中元素递增有序。
 * 设计一个算法，将A和B归并成一个按元素值递减有序的链表C，
 * C由A和B中的结点组成
 */
void mergeFirst(LNode *A, LNode *B, LNode *&C) {
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *start;
    C=A;
    C->next = NULL;
    free(B);
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            start = p;
            p = p->next;
            start->next = C->next;
            C->next = start;
        } else {
            start = q;
            q = q->next;
            start->next = C->next;
            C->next = start;
        }
    }
    while (p != NULL) {
        start = p;
        p = p->next;
        start->next = C->next;
        C->next = start;
    }
    while (q != NULL) {
        start = q;
        q = q->next;
        start->next = C->next;
        C->next = start;
    }
}

// 考试中，删除结点后，还要释放删除结点的空间
// q = p->next;
// p->next = p->next->next;
// free(q);

/*
 * 查找链表C（带头结点）中是否存在一个值为x的结点，若存在，则删除该节点并返回1，否则返回0。
 */
int findAndDelete(LNode *C, int x) {
    LNode *p, *q;
    p = C;
    while (p->next != NULL) {
        if (p->next->data == x) {
            break;
        }
        p = p->next;
    }
    if (p->next == NULL) {
        return 0;
    } else {
        q = p->next;
        p->next = p->next->next;
        free(q);
        return 1;
    }
}
