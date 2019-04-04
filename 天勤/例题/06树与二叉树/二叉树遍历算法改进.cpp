//
// Created by roguelxx on 19-4-2.
//
#include "结构体定义.h"


/*
 * 先序遍历非递归算法
 */
void preorderNonrecursion(BTNode *bt) {
    if (bt != NULL) {
        BTNode *stack[maxSize];
        int top = -1;
        BTNode *p;
        stack[++top] = bt;
        while (top != -1) {
            p = stack[top--];
            visit(p);
            if (p->rchild != NULL) {
                stack[++top] = p->rchild;
            }
            if (p->lchild != NULL) {
                stack[++top] = p->lchild;
            }
        }
    }
}

/*
 * 中序遍历非递归算法
 */
void inorderNonrecursion(BTNode *bt) {
    if (bt != NULL) {
        BTNode *stack[maxSize];
        int top = -1;
        BTNode *p;
        p = bt;
        while (top != -1 || p != NULL) {
            while (p != NULL) {
                stack[++top] = p;
                p = p->lchild;
            }
            if (top != -1) {
                p = stack[top--];
                visit(p);
                p = p->rchild;
            }
        }
    }
}

/*
 * 后序遍历非递归算法
 */
void postorderNonrecursion(BTNode *bt) {
    if (bt != NULL) {
        BTNode *stack1[maxSize];
        BTNode *stack2[maxSize];
        BTNode *p;
        int top1 = -1;
        int top2 = -1;
        stack1[++top1] = bt;
        while (top1 != -1) {
            p = stack1[top1--];
            stack2[++top2] = p;
            if (p->lchild != NULL) {
                stack1[++top1] = p->lchild;
            }
            if (p->rchild != NULL) {
                stack1[++top1] = p->rchild;
            }
        }
        while (top2 != -1) {
            p = stack2[top2--];
            visit(p);
        }
    }
}

/*
 * 二叉树中序遍历线索化
 */

void InThread(TBTNode *p, TBTNode *&pre) {
    if (p != NULL) {
        InThread(p->lchild, pre);
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        p = p->rchild;
        InThread(p, pre);
    }
}

void createInThread(TBTNode *root) {
    TBTNode *pre = NULL;
    if (root != NULL) {
        InThread(root, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

/*
 * 遍历中序线索二叉树 - 以p为根的中序线索二叉树中,中序序列下的第一个结点算法
 */
TBTNode *first(TBTNode *p) {
    while (p->ltag == 0) {
        p = p->lchild;
    }
    return p;
}

/*
 * 遍历中序线索二叉树 - 以p为根的中序线索二叉树中,中序序列下的最后一个结点算法
 */
TBTNode *last(TBTNode *p) {
    while (p->rtag == 0) {
        p = p->rchild;
    }
    return p;
}

/*
 * 遍历中序线索二叉树 - 中序线索二叉树中,结点p在中序序列下的后继结点的算法
 */
TBTNode *next(TBTNode *p) {
    if (p->rtag == 0) {
        return first(p->rchild);
    } else {
        return p->rchild;
    }
}

/*
 * 遍历中序线索二叉树 - 中序线索二叉树中,结点p在中序序列下的后继结点的算法
 */
TBTNode *prior(TBTNode *p) {
    if (p->ltag == 0) {
        return last(p->lchild);
    } else {
        return p->lchild;
    }
}

/*
 * 遍历中序线索二叉树
 */
void inorderThread(TBTNode *root) {
    for (TBTNode *p = first(root); p != NULL; p = next(p)) {
        visit(p);
    }
}

/*
 * 二叉树前序遍历线索化
 */

void preThread(TBTNode *p, TBTNode *&pre) {
    if (p != NULL) {
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        if (p->ltag == 0) {
            preThread(p->lchild, pre);
        }
        if (p->rtag == 0) {
            preThread(p->rchild, pre);
        }
    }
}

/*
 * 遍历中序线索二叉树
 */

void preorderThread(TBTNode *root) {
    if (root != NULL) {
        TBTNode *p = root;
        while (p != NULL) {
            while (p->ltag == 0) {
                visit(p);
                p = p->lchild;
            }
            visit(p);
            p = p->rchild;
        }
    }
}

/*
 * 二叉树后序遍历线索化
 */

void postThread(TBTNode *p, TBTNode *&pre) {
    if (p != NULL) {
        postThread(p->lchild, pre);
        postThread(p->rchild, pre);
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild != NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
    }
}