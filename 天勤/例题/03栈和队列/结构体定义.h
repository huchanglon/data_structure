//
// Created by roguelxx on 19-3-18.
//

#ifndef 结构体定义_H
#define 结构体定义_H

#define maxSize 100

/*
 * 顺序栈定义
 */
typedef struct {
    int data[maxSize];
    int top;
} SqStack;

/*
 * 链栈结点定义
 */
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

/*
 * 顺序队列定义
 */
typedef struct {
    int data[maxSize];
    int front;
    int rear;
} SqQueue;

/*
 * 链队定义 - 队结点类型定义
 */
typedef struct QNode {
    int data;
    struct QNode *next;
} QNode;

/*
 * 链队定义 - 链队类型定义
 */
typedef struct {
    QNode *front;
    QNode *rear;
} LiQueue;

#endif //结构体定义_H
