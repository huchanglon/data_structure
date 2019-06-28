//
// Created by roguelxx on 19-6-26.
//

/*
 * 编写一个算法,判断给定的二叉树是否是二叉排序树
 */
ElemType predata = -32767;

int JudgeBST(Bitree T) {
    int b1, b2;
    if (T == NULL) {
        return 1;
    } else {
        b1 = JudgeBST(T->lchild);
        if (b1 == 0 || predata >= T->data) {
            return 0;
        }
        predata = T->data;
        b2 = JudgeBST(T->rchild);
        return b2;
    }
}

/*
 * 设计一个算法,求出指定结点在给定二叉排序树中的层次.
 */
int NodeLevel(BiTree T, int depth, BiTNode x) {
    if (T == x) {
        return depth;
    } else if (x->data < T->data) {
        NodeLevel(T->lchild, depth + 1, x);
    } else if (x->data > T->data) {
        NodeLevel(T->rchild, depth + 1, x);
    }
    return 0;
}

int NodeLevelNonRecur(BiTree bt, BSTNode x) {
    int depth = 1;
    BiTree p = bt;
    while (p != NULL) {
        if (p->data == x->data) {
            return depth;
        } else if (x->data > p->data) {
            depth++;
            p = p->rchild;
        } else if (x->data < p->data) {
            depth++;
            p = p->lchild;
        }
    }
    return 0;
}

/*
 * 利用二叉树遍历的思想编写一个判断二叉树是否是平衡二叉树的算法.
 */
void JudgeAVL(BiTree bt, int &balance, int &h) {
    int bl = 0, br = 0, hl = 0, hr = 0;
    if (bt == NULL) {
        h = 0;
        balance = 1;
    } else if (bt->lchild == NULL && bt->rchild == NULL) {
        h = 1;
        balance = 1;
    } else {
        JudgeAVL(bt->lchild, bl, hl);
        JudgeAVL(bt->rchild, br, hr);
        h = (hl > hr ? hl : hr) + 1;
        if (abs(hl - hr) < 2) {
            balance = bl && br;
        } else {
            balance = 0;
        }
    }
}

/*
 * 设计一个算法,求出给定二叉排序树中最大和最小的关键字.
 */
void BSTMinMax(BiTree bt, ElemType &min, ElemType &max) {
    BiTree p = bt;
    while (p != NULL) {
        p = p->lchild;
    }
    min = p->data;
    while (p != NULL) {
        p = p->rchild;
    }
    max = p->data;
}

/*
 * 设计一个算法,从大到小输出二叉排序树中值不小于k的关键字.
 */
void OutPut(BSTNode bt, ElemType k) {
    if (bt == NULL) {
        return;
    }
    if (bt->rchild != NULL) {
        OutPut(bt->rchild, k);
    }
    if (bt->data >= k) {
        printf(bt->data);
    }
    if (bt->lchild != NULL) {
        OutPut(bt->lchild, k);
    }
}

void OutPut2(BSTNode bt, ElemType k) {
    InitStack(s);
    InitStack(s1);
    BSTNode p = bt;
    while (p != NULL || !Empty(s)) {
        if (p != NULL) {
            Push(s, p);
            p = p->lchild;
        } else {
            Pop(s, p);
            if (p->data >= k) {
                Push(s1, p);
            }
            p = p->rchild;
        }
    }
    while (!Empty(s1)) {
        Pop(s1, p);
        printf(p->data);
    }
}

/*
 * 编写一个递归算法,在一棵有n个结点的、随机建立起来的二叉排序树上查找第k(1<=k<=n)小
 * 的元素,并返回指向该结点的指针.要求算法平均时间复杂度为O(log2n).二叉排序树中结点
 * 属性为data、lchild、rchild、count,count中保存以该结点为根的子树上的结点个数.
 */
BSTNode KthNode(BSTNode bt, int k) {
    if (k > bt->count || k < 1) {
        return NULL;
    }
    if (bt->lchild == NULL) {
        if (k == 1) {
            return bt;
        } else {
            return KthNode(bt->rchild, k - 1);
        }
    } else {
        int rank = bt->lchild->count + 1;
        if (k == rank) {
            return bt;
        } else if (k < rank) {
            return KthNode(bt->lchild, k);
        } else {
            return KthNode(bt->rchild, k - rank);
        }
    }
}
