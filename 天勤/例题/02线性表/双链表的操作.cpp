//
// Created by roguelxx on 19-3-16.
//

#include <malloc.h>
#include "结构体定义.h"

/*
 * 使用尾插法建立双链表
 */
void createDListEnd(DLNode *&L, int a[], int n) {
    DLNode *s, *r;
    L = (DLNode *) malloc(sizeof(DLNode));
    L->prior = NULL;
    L->next = NULL;
    r = L;
    for (int i = 0; i < n; ++i) {
        s = (DLNode *) malloc(sizeof(DLNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;      //将r指向s
    }
    r->next = NULL;
}

/*
 * 查找结点的算法
 * 在双链表C中查找第一个值为x的结点，若找到，则返回结点指针，否则返回NULL。
 */
DLNode* findNode(DLNode *C, int x) {
    DLNode *p;
    p = C->next;
    while (p != NULL) {
        if (p->next->data == x) {
            break;
        }
        p = p->next;
    }
    return p;
}

/*
 * 插入结点的算法
 * 假设在双链表中p所指向的结点之后插入一个结点s
 */
void insertNode(DLNode *p, DLNode *s) {
    s->next = p->next;
    s->prior = p;
    p->next = s;
    s->next->prior = s;
}

/*
 * 删除结点的算法
 * 假设要删除双链表中p结点的后继结点
 */
void deleteNextNode(DLNode *p) {
    DLNode * q;
    p->next->next->prior = p;
    q = p->next;
    p->next = p->next->next;
    free(q);
}
