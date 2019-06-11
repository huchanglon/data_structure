//
// Created by roguelxx on 19-6-11.
//

/*
 * 设置一个标志域tag,并以tag的值为0或1来区分队头指针front和队尾指针rear相同时
 * 队列状态是"空"还是"满".写出此结构对应的入队和出队算法.
 */
typedef struct {
    ElemType data[maxSize];
    int tag;
    int front;
    int rear;
} TagQueue;

bool tagEnQueue(TagQueue &queue, ElemType x) {
    if (tag == 1 && queue.front == queue.rear) {
        printf("队列满");
        return false;
    }
    queue.data[queue.rear] = x;
    queue.rear = (queue.rear + 1) % maxSize;
    queue.tag = 1;
    return true;
}

bool tagDeQueue(TagQueue &queue, ElemType &x) {
    if (tag == 0 && queue.front == queue.rear) {
        printf("队列空");
        return false;
    }
    x = queue.data[queue.front];
    queue.front = (queue.front + 1) % maxSize;
    queue.tag = 0;
    return true;
}

/*
 * Q是一个队列,S是一个空栈,实现将队列中的元素逆置的算法.
 */
void reverseQueue(Queue Q, Stack S) {
    while (Q.front != Q.rear) {
        S.data[++S.top] = Q.data[front++];
    }
    while (S.top != -1) {
        Q.data[rear++] = S.data[S.top--];
    }
}

/*
 * 利用两个栈S1,S2来模拟一个队列,已知栈的4个运算定义如下:Push(S,x);Pop(S,x);
 * StackEmpty(S);StackOverFlow(S);实现该队列的三个运算:Enqueue;Dequeue;
 * QueueEmpty;
 */
bool Enqueue(Stack s1, Stack s2, ElemType x) {
    ElemType t;
    if (StackOverFlow(s1)) {
        if (StackEmpty(s2)) {
            while (!StackEmpty(s1)) {
                Pop(s1, t);
                Push(s2, t);
            }
        } else {
            return false;
        }
    }
    Push(s1, x);
    return true;
}

bool Dequeue(Stack s1, Stack s2, ElemType &x) {
    if (StackEmpty(s2)) {
        if (!StackEmpty(s1)) {
            while (s1.top != -1) {
                s2.data[++s2.top] = s1.data[s1.top--];
            }
        } else {
            return false;
        }
    }
    x = s2.data[s2.top--];
    return true;
}

bool QueueEmpty(Stack s1, Stack s2) {
    if (StackEmpty(s1) && StackEmpty(s2)) {
        return true;
    } else {
        return false;
    }
}


