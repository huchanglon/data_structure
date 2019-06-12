//
// Created by roguelxx on 19-6-12.
//

/*
 * 假设一个算术表达式中包含圆括号、方括号、花括号3种类型的括号,写一个算法来判别
 * 表达式中的括号是否配对,以字符'\0'作为算术表达式的结束符.
 */
bool isMatched(char *p) {
    char stack[];
    int top = -1, i = 0;
    while (p[i] != '\0') {
        if (p[i] == '(' || p[i] == '[' || p[i] == '{') {
            stack[++top] = p[i];
        } else if (p[i] == ')') {
            if (stack[top] == '(') {
                --top;
            } else {
                return false;
            }
        } else if (p[i] == ']') {
            if (stack[top] == '[') {
                --top;
            } else {
                return false;
            }
        } else if (p[i] == '}') {
            if (stack[top] == '{') {
                --top;
            } else {
                return false;
            }
        }
        ++i;
    }
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

/*
 * 按下图所示铁道进行车厢调度(注意,两侧铁道均为单向行驶道,火车调度站有一个用于
 * 调度的"栈道"),火车调度站的入口处有n节硬座和软座车厢(分别用H和S表示)等待调度,
 * 编写算法,输出对这n节车厢进行调度的操作(即入栈和出栈操作)序列,使得所有软座车厢
 * 都被调整到硬座车厢之前.
 */
void trainSchedule(char *trains, int n) {
    char *p = trains, *q = trains, c;
    Stack s;
    InitStack(s);
    while (*p) {
        if (*p == 'H') {
            Pop(s, *p);
        } else {
            *(q++) = *p;
        }
        ++p;
    }
    while (!StackEmpty(s)) {
        Pop(s, c);
        *(q++) = c;
    }
}

/*
 * 利用一个栈实现一下递归函数的非递归计算.
 */

double nonRecursive(int n, double x) {
    struct stack {
        int no;
        double value;
    } stack[maxSize];
    int top = -1, i;
    double fv0 = 1, fv1 = 2 * x;
    for (i = n; i >= 2; --i) {
        stack[++top].no = i;
    }
    while (top != -1) {
        stack[top].value = 2 * x * fv1 - 2 * (stack[top].no - 1) * fv0;
        fv0 = fv1;
        fv1 = stack[top].value;
        top--;
    }
    if (n == 0) {
        return fv0;
    }
    return fv1;
}

/*
 * 某汽车轮渡口,过江渡船每次能载10辆车过江.过江车辆分为客车类和货车类,上渡船有
 * 如下规定:同类车先到先上船;客车先于货车上船,且每上4辆客车,才允许放上1辆货车;
 * 若等待客车不足4辆,则以货车代替;若无货车等待,允许客车都上船.设计一个算法模拟渡口管理.
 * 假设客车货车已存于各自的序列中
 */
void carSchedule(int seq[]) {
    Queue q  // 渡船队列
    Queue q1 // 客车队列
    Queue q2 // 货车队列
    int i = 0, j = 0, x;
    while (j < 10) {
        if (!QueueEmpty(q1) && i < 4) {
            Dequeue(q1, x);
            Enqueue(q, x);
            ++i;
            ++j;
        } else if (i == 4 && !QueueEmpty(q2)) {
            Dequeue(q2, x);
            Enqueue(q, x);
            i=0;
            ++j;
        } else {
            while (j < 10 && i < 4 && !QueueEmpty(q2)) {
                Dequeue(q2, x);
                Enqueue(q, x);
                ++j;
                ++i;
            }
            i = 0;
        }
        if (QueueEmpty(q1) && QueueEmpty(q2)) {
            break;
        }
    }
}
