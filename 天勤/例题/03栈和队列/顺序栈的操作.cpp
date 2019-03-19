//
// Created by roguelxx on 19-3-18.
//

#include "结构体定义.h"

/*
 * 初始化栈
 * int stack[maxSize]; int top = -1;
 */
void initStack(SqStack &stack) {
    stack.top = -1;
}

/*
 * 判断栈空
 */
int isEmpty(SqStack stack) {
    if (stack.top == -1) {
        return 1;
    } else {
        return 0;
    }
}

/*
 * 入栈
 * stack[++top] = x;
 */
int push(SqStack &stack, int x) {
    if (stack.top = maxSize - 1) {
        return 0;
    }
    ++(stack.top);
    stack.data[stack.top] = x;
    return 1;
}

/*
 * 出栈
 * stack[top--] = x;
 */
int pop(SqStack &stack, int &x) {
    if (stack.top = -1) {
        return 0;
    }
    x = stack.data[stack.top];
    --(stack.top);
    return 1;
}
