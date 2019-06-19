//
// Created by roguelxx on 19-6-15.
//

/*
 * 中序遍历-NonRecursive
 */
void inOrderNonRecur(BiTree T) {
    InitStack(S);
    BiTree p = T;
    while (p != NULL || !EmptyStack(S)) {
        if (p != NULL) {
            Push(S, p);
            p = p->lchild;
        } else {
            Pop(S, p);
            visit(p);
            p = p->rchild;
        }
    }
}

/*
 * 前序遍历-NonRecursive
 */
void preOrderNonRecur(BiTree T) {
    if (T != NULL) {
        InitStack(S);
        BiTree p = T;
        Push(S, p);
        while (!EmptyStack(S)) {
            Pop(S, p);
            visit(p);
            if (p->rchild) {
                Push(S, p->rchild);
            } else if (p->lchild) {
                Push(S, p->lchild);
            }
        }
    }
}

/*
 * 后序遍历-NonRecursive-2 Stacks
 */
void postOrderNonRecur(BiTree T) {
    if (T != NULL) {
        InitStack(S1);
        InitStack(S2);
        BiTree *p;
        Push(S1, T);
        while (!EmptyStack(S1)) {
            Pop(S1, p);
            Push(S2, p);
            if (p->lchild) {
                Push(S1, p->lchild);
            }
            if (p->rchild) {
                Push(S1, p->rchild);
            }
        }
        while (!EmptyStack(S2)) {
            Pop(S2, p);
            visit(p);
        }
    }
}

/*
 * 后序遍历-NonRecur-1 Stack
 */
void postOrderNonRecur2(BiTree T) {
    if (T != NULL) {
        InitStack(S);
        BiTree *p = T, *r = NULL;
        while (p || !Empty(S)) {
            if (p) {
                Push(S, p);
                p = p->lchild;
            } else {
                GetTop(S, p);
                if (p->rchild && p->rchild != r) {
                    p = p->rchild;
                    Push(S, p);
                    p = p->lchild;
                } else {
                    Pop(S, p);
                    visit(p);
                    r = p;
                    p = NULL;
                }
            }
        }
    }
}

/*
 * 层次遍历
 */
void levelOrder(BiTree T) {
    if (T != NULL) {
        BiTree *p;
        InitQueue(Q);
        EnQueue(Q, T);
        while (!EmptyQueue(Q)) {
            p = DeQueue(Q);
            if (p->lchild) {
                EnQueue(Q, p->lchild);
            }
            if (p->rchild) {
                EnQueue(Q, p->rchild);
            }
            visit(p);
        }
    }
}

/*
 * 通过中序遍历将二叉树线索化
 */
void InThread(ThreadTree &p, ThreadTree &pre) {
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
        InThread(p->rchild, pre);
    }
}

void createInThread(ThreadTree T) {
    ThreadTree pre = NULL;
    if (T != NULL) {
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}
