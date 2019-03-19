//
// Created by roguelxx on 19-3-19.
//

/*
 * 使用优化后的顺序循环队列存储结构
 * 指针移动情况可以表示为：front = (front+1)%maxSize
 * 队空条件：front == rear
 * 队满条件：(rear+1)%maxSize == front
 */

/*
 * 初始化队列
 */
void initQueue(SqQueue &queue) {
    queue.front = queue.rear = 0;
}

/*
 * 判断队列为空
 */
int isEmpty(SqQueue queue) {
    if (queue.front == queue.rear) {
        return 1;
    } else {
        return 0;
    }
}

/*
 * 判断队列满
 */
int isFull(SqQueue queue) {
    if ((queue.rear + 1) % maxSize == queue.front) {
        return 1;
    } else {
        return 0;
    }
}
/*
 * 进队
 */
int enQueue(SqQueue &queue, int x) {
    if (isFull(queue)) {
        return 0;
    } else {
        queue.rear = (queue.rear + 1) % maxSize;
        queue.data[queue.rear] = x;
        return 1;
    }
}

/*
 * 出队
 */
int deQueue(SqQueue &queue, int &x) {
    if (isEmpty(queue)) {
        return 0;
    } else {
        queue.front = (queue.front + 1) % maxSize;
        x = queue.data[queue.front];
        return 1;
    }
}
