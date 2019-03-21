//
// Created by roguelxx on 19-3-21.
//

/*
 * 写出一个算法, 判定所给的操作序列是否合法.
 * 若合法, 返回1, 否则返回0
 * 假定被判定的操作序列已存入一维char型数组ch[]中,操作序列以"\0"为结束符
 */
typedef struct {
    int top;
    char data[maxSize];
} CharStack;

int isLegal(char ch[]) {
    CharStack stack = (CharStack *) malloc(sizeof(CharStack));
    stack.top = -1;
    int i;
    for (i = 0; ch[i] != '\0'; ++i) {
        if (ch[i] == 'I') {
            stack.data[++stack.top] = 'I';
        } else if (ch[i] == 'O') {
            if (stack.top == -1) {
                return 0;
            } else {
                stack.data[stack.top--];
            }
        }
    }
    if (stack.top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int judge(char ch[]) {
    int i = 0;
    int I = 0, O = 0;
    while (ch[i] != '\0') {
        if (ch[i] == 'I') {
            ++I;
        }
        if (ch[i] == 'O') {
            ++O;
        }
        if (O > I) {
            return 0;
        }
        ++i;
    }
    if (I != O) {
        return 0;
    } else {
        return 1;
    }
}

/*
 * 假设以带头结点的循环链表表示队列,并且只设一个指针指向队尾结点,
 * 但不设头指针,请写出相应的出队,入队算法.
 */
void enQueue(LNode *&rear, int x) {
    LNode *q = (LNode *) mallinfo(sizeof(LNode));
    q->data = x;
    q->next = rear->next;
    rear->next = q;
    rear = q;
}

int deQueue(LNode *&rear, int &x) {
    LNode *s;
    if (rear->next != NULL) {
        s = rear->next->next;
        rear->next->next = s->next;
        x = s->data;
        if (s == rear) {
            rear = rear->next;  // rear指向头结点
        }
        free(s);
    } else {
        return 0
    }
}
/*
 * 如果允许在循环队列两端都可以进行插入和删除操作,要求:
 * 1.写出循环队列的类型定义.
 * 2.分别写出从队尾删除和从队头插入的算法.
 */
typedef struct {
    int data[maxSize];
    int front;
    int rear;
}DoubleQueue;

int frontEnQueue(DoubleQueue &queue, int x) {
    if (queue.rear == (queue.front - 1 + maxSize) % maxSize) {
        return 0;
    } else {
        queue.data[queue.front] = x;
        queue.front = (queue.front - 1 + maxSize) % maxSize;
        return 1;
    }
}

int rearDeQueue(DoubleQueue &queue, int &x) {
    if (queue.front == queue.rear) {
        return 0;
    } else {
        x = queue.data[queue.front];
        queue.rear = (queue.rear - 1 + maxSize) % maxSize;
        return 1;
    }
}

/*
 * 设计一个循环队列,用front和rear分别作为队头和队尾指针,
 * 另外用一个标志tag表示队列是否为空,
 * 约定 tag==0 为空,tag == 1 为非空,
 * 这样就可以使用front=rear作为队满的条件要求,
 * 设计队列的结构和相关基本运算算法.
 */
typedef struct {
    int data[maxSize];
    int front;
    int rear;
    int tag;
} CycleQueue;

int CycleDeQueue(CycleQueue &queue, int &x) {
    if (queue.tag == 0 && queue.front == queue.rear) {
        return 0;
    } else {
        x = queue.data[queue.front];
        queue.front = (queue.front + 1) % maxSize;
        queue.tag = 0;
        return 1;
    }
}

int CycleEnQueue(CycleQueue &queue, int x) {
    if (queue.tag == 1 && queue.front == queue.rear) {
        return 0;
    } else {
        queue.rear = (queue.rear + 1) % maxSize;
        queue.data[queue.rear] = x;
        queue.tag = 1;
        return 1;
    }
}

void initCycleQueue(CycleQueue &queue) {
    queue.tag=0;
    queue.front = queue.rear = 0;
}

int isCycleQueueEmpty(CycleQueue &queue) {
    if (queue.tag == 0 && queue.front == queue.rear) {
        return 1;
    } else {
        return 0;
    }
}

int isCycleQueueFull(CycleQueue &queue) {
    if (queue.tag == 1 && queue.front == queue.rear) {
        return 1;
    } else {
        return 0;
    }
}

/*
 * 编写一个算法,将一个非负的十进制整数N转换为一个二进制数
 */
int transform(int number) {
     int stack[maxSize]; int top = -1;
    int a, result = 0;
    while (number != 0) {
        a = number % 2;
        number = number / 2;
        stack[++top] = a;
    }
    while (top != -1) {
        a = stack[top--];
        result = result * 10 + a;
    }
    return result;
}

/*
 * 编写一个算法,检查一个程序中的花括号,方括号和圆括号是否配对,若全配对,则返回1,否则返回0
 * 对于程序出现的一对单引号或双引号内的字符不进行括号配对检查.39为单引号的ASCII值,
 * 34为双引号的ASCII值,单引号和双引号如果出现则比成对出现.
 * 假设stack是已经定义的顺序栈结构体.可以直接调用的元素进栈/出栈,取栈顶元素,判断栈是否为空的函数定义如下:
 * void push(stack &s, char ch);
 * void pop(stack &s, char &ch);
 * void getTop(stack S, char &ch);
 * int isEmpty(stack S);        // return 1 if isEmpty, else return 0
 */
int bracketsCheck(char f[]) {
    stack S, char ch;
    char *p = f;
    while (*p != '\0') {
        if (*p == 39) {
            ++p;
            while (*p != 39) {
                ++p;
            }
            ++p;
        } else if (*p == 34) {
            ++p;
            while (*p != 34) {
                ++p;
            }
            ++p;
        } else {
            switch (*p) {
                case '{':
                case '(':
                case '[':
                    push(S, *p);
                    break;
                case '}':
                    getTop(S, ch);
                    if (ch == '{') {
                        pop(S, ch);
                    } else {
                        return 0;
                    }
                    break;
                case ')':
                    getTop(S, ch);
                    if (ch == '(') {
                        pop(S, ch);
                    } else {
                        return 0;
                    }
                    break;
                case '[':
                    getTop(S, ch);
                    if (ch == ']') {
                        pop(S, ch);
                    } else {
                        return 0;
                    }
                    break;
            }
        }
        ++p;
    }
    if (isEmpty(S)) {
        return 1;
    } else {
        return 0;
    }
}
