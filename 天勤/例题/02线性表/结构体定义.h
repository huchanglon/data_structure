//
// Created by roguelxx on 19-3-15.
//

#define maxSize 100

/*
 * 线性表的结构体定义
 */


typedef struct Sqlist{
    int data[maxSize];
    int length;
} Sqlist;

/*
 * 单链表结点定义
 */

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

/*
 * 双链表结点定义
 */

typedef struct DLNode {
    int data;
    struct DLNode *prior;
    struct DLNode *next;
} DLNode;

