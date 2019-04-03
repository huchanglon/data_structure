//
// Created by roguelxx on 19-3-31.
//

#include "结构体定义.h"

/*
 * 先序遍历
 */
void preorder(BTNode *p) {
    if (p != NULL) {
        visit(p);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

/*
 * 中序遍历
 */
void inorder(BTNode *p) {
    if (p != NULL) {
        inorder(p->lchild);
        visit(p);
        inorder(p->rchild);
    }
}

/*
 * 后序遍历
 */
void postorder(BTNode *p) {
    if (p != NULL) {
        postorder(p->lchild);
        postorder(p->rchild);
        visit(p);
    }
}

/*
 * 写一个算法求一棵二叉树的深度,二叉树以二叉链表为存储方式
 */
int getDepth(BTNode *p) {
    int LD, RD;
    if (p == NULL) {
        return 0;
    } else {
        LD = getDepth(p->lchild);
        RD = getDepth(p->rchild);
        return (LD > RD ? LD : RD) + 1;
    }
}

/*
 * 在一棵以二叉链表为存储结构的二叉树p中,查找data域值等于key的结点是否存在,
 * 找到一个满足要求的结点即可,如果存在,则将二叉树结点q指向该结点,否则q赋值为NULL,
 * 假设data为int型
 */
void search(BTNode *p, BTNode *&q, int key) {
    if (p != NULL) {
        if (p->data == key) {
            q = p;
        } else {
            search(p->lchild, q, key);
            if (q == NULL) {
                search(p->rchild, q, key);
            }
        }
    }
}

/*
 * 假设二叉树采用二叉链表存储结构,编写一个算法,
 * 输出先序遍历序列中第k个结点的值,假设k不大于总的结点数,
 * 结点data域类型为char型.
 */
char preorderTravel(BTNode *p, int k) {
    int n = 0;
    if (p != NULL) {
        ++n;
        if (k == n) {
            return p->data;
        } else {
            preorderTravel(p->lchild, k);
            preorderTravel(p->rchild, k);
        }
    }
}

char inorderTravel(BTNode *p, int k) {
    int n = 0;
    if (p != NULL) {
        inorderTravel(p->lchild, k);
        ++n;
        if (k == n) {
            return p->data;
        } else {
            inorderTravel(p->rchild, k);
        }
    }
}

char postorderTravel(BTNode *p, int k) {
    int n = 0;
    if (p != NULL) {
        postorderTravel(p->lchild, k);
        postorderTravel(p->rchild, k);
        if (k == n) {
            return p->data;
        }
    }
}

/*
 * 层次遍历
 */
void levelTravel(BTNode *p) {
    int front, rear;
    BTNode *que[maxSize];
    front = rear = 0;
    BTNode *q;
    if (p != NULL) {
        rear = (rear + 1) % maxSize;
        que[rear] = p;
        while (front != rear) {
            front = (front + 1) % maxSize;
            q = que[front];
            visit(q);
            if (q->lchild != NULL) {
                rear = (rear + 1) % maxSize;
                que[rear] = q->lchild;
            }
            if (q->rchild != NULL) {
                rear = (rear + 1) % maxSize;
                que[rear] = q->rchild;
            }

        }
    }
}

/*
 * 假设二叉树采用二叉链表存储结构,设计一个算法,求出该二叉树的宽度.
 */
typedef struct {
    BTNode *p;
    int lno;
} SqTree;

int maxNode(BTNode *b) {
    SqTree que[maxSize];
    int front, rear;
    int Lno, i, j, n, max;
    BTNode *q;
    front = rear = 0;
    if (b != NULL) {
        ++rear;
        que[rear].p = b;
        que[rear].lno = 1;
        while (front != rear) {
            q = que[++front].p;
            Lno = que[front].lno;
            if (q->lchild != NULL) {
                que[++rear].p = q->lchild;
                que[rear].lno = Lno + 1;
            }
            if (q->rchild != NULL) {
                que[++rear].p = q->rchild;
                que[rear].lno = Lno + 1;
            }
        }
        max = 0;
        for (i = 1; i <= Lno; ++i) {
            n = 0;
            for (j = 1; j <= rear; ++j) {
                if (que[j].lno == i) {
                    ++n;
                }
                if (max < n) {
                    max = n;
                }
            }
            return max;
        }
    } else {
        return 0;
    }
}