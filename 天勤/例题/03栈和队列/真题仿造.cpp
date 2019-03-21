//
// Created by roguelxx on 19-3-19.
//

/*
 * 为了充分利用空间，顺序栈s0、s1共享一个存储区elem[0,1,2,...,maxSize-1]。
 * 设计共享栈s0、s1以及有关入栈和出栈操作的算法，假设栈中元素为int型。
 */

/*
 * 共享栈结构定义
 */
typedef struct {
    int elem[maxSize];      // 栈空间
    int top[2];             // top[0]为s0栈顶，top[1]为s1栈顶
}ShareStack;

/*
 * 入栈操作
 */
int push(ShareStack &stack, int stNo, int x) {
    if (stack.top[0] + 1 < stack.top[1]) {
        if (stNo == 0) {
            stack.elem[++stack.top[0]] = x;
            return 1;
        } else if (stNo == 1) {
            stack.elem[--stack.top[1]] = x;
            return 1;
        } else {
            return -1;
        }
    } else {
        return 0;
    }
}


/*
 * 出栈操作
 */
int pop(ShareStack &stack, int stNo, int &x) {
    if (stNo == 0) {
        if (stack.top[0] == -1) {
            return 0;
        } else {
            x = stack.elem[stack.top[0]--];
            return 1;
        }
    } else if (stNo == 1) {
        if (stack.top[1] == maxSize) {
            return 0;
        } else {
            x = stack.elem[stack.top[1]++];
            return 1;
        }
    } else {
        return -1;
    }
}

/*
 * 请利用两个栈s1、s2来模拟一个队列，假设栈中元素为int型，栈中元素最多为maxSize。
 * 已知栈的3个运算定义如下：
 * 1. push(ST, x)：元素x入栈。
 * 2. pop(ST, &x)：ST栈顶元素出栈，赋给变量x。
 * 3. isEmpty(ST):判断ST栈是否为空。
 * 实现队列对应的3个运算：enQueue、deQueue、isQueueEmpty
 */

/*
 * 入队
 */
int enQueue(SqStack &s1, SqStack &s2, int x) {
    int y;
    if (s1.top == maxSize - 1) {
        if (!isEmpty(s2)) {
            return 0;
        } else {
            while (!isEmpty(s1)) {
                pop(s1, y);
                push(s2, y);
            }
            push(s1, x);
            return 1;
        }
    } else {
        push(s1, x);
        return 1;
    }
}

/*
 * 出队
 */
int deQueue(SqStack &s1, SqStack &s2, int &x) {
    int y;
    if (isEmpty(s2)) {
        if (!isEmpty(s1)) {
            while (!isEmpty(s1)) {
                pop(s1, y);
                push(s2, y);
            }
            pop(s2, x);
            return 1;
        } else {
            return 0;
        }
    } else {
        pop(s2, x);
        return 1;
    }
}

/*
 * 判断队空
 */
int isQueueEmpty(SqStack &s1, SqStack &s2) {
    if (isEmpty(s1) && isEmpty(s2)) {
        return 1;
    } else {
        return 0;
    }
}
