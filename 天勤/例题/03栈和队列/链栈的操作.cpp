//
// Created by roguelxx on 19-3-18.
//

#include "结构体定义.h"

/*
 * 栈初始化
 */
void initStack(LNode *&head {
    head = (LNode *) malloc(sizeof(LNode));
    head->next = NULL;
}

/*
 * 栈为空判断
 */
int isEmpty(LNode *head) {
    if (head->next == NULL) {
        return -1;
    } else {
        return 0;
    }
}

/*
 * 入栈
 */
void push(LNode *head, int x) {
    LNode *p;
    p = (LNode *) malloc(sizeof(LNode));
    p->next = NULL;
    p->data = x;
    p->next = head->next;
    head->next = p;
}

/*
 * 出栈
 */
int pop(LNode *&head, int &x) {
    if (isEmpty(head)) {
        return 0;
    }
    LNode *p = head->next;
    x = p->data;
    head->next = p->next;
    free(p);
    return 1;
}
