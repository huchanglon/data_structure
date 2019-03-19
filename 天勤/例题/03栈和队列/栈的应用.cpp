//
// Created by roguelxx on 19-3-18.
//

typedef struct {
    int top;
    char data[maxSize];
} CharStack;

typedef struct {
    int top;
    int data[maxSize];
} IntStack;
/*
 * 编写算法，判断一个表达式中的括号是否正确配对，表达时已经存入字符数组exp[]中，
 * 表达式中的字符个数为n。
 */
int match(char exp[], int n) {
    // char stack[maxSize]; int top = -1;
    CharStack.top = -1;
    int i;
    for (i = 0; i < n; ++i) {
        if (exp[i] == '(') {
            CharStack.data[++CharStack.top] = exp[i];
        } else if (exp[i] == ')') {
            if (CharStack.top == -1) {
                return 0;
            } else {
                --(CharStack.top);
            }
        }
    }
    if (CharStack.top == -1) {
        return 1;
    } else {
        return 0;
    }
}

/*
 * 编写一个函数，求后缀式的数值，其中后缀式存于一个字符数组exp中，exp中最后一个字符为“\0”，
 * 作为结束符，并且假设后缀式中的数字都只有一位。
 */
int op(int a, char op, int b) {
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else if (op == '*') {
        return a * b;
    } else if (op == '/') {
        if (b == 0) {
            cout << "Hello, world!" << endl;
        } else {
            return a / b;
        }
    }
}
int com(char exp[]) {
    // int stack[maxSize]; int top = -1;
    IntStack.top = -1
    int i;
    int a, b, c;
    for (i = 0; exp[i] != '\0'; ++i) {
        if (exp[i] >= '0' && exp[i] <= '9') {
            IntStack.data[++IntStack.top] = exp[i] - '0';
        } else {
            a = IntStack.data[IntStack.top--];
            b = IntStack.data[IntStack.top--];
            c = op(a, exp[i], b);
            IntStack.data[++IntStack.top] = c;
        }
    }
    return IntStack.data[IntStack.top];
}

/*
 * 用不带头结点的单链表存储链栈，设计初始化栈、判断栈是否为空、入栈和出栈等相应算法。
 */

