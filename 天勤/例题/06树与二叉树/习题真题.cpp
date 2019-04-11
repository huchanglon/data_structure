//
// Created by roguelxx on 19-4-4.
//

#include <iostream>
#include "结构体定义.h"
using namespace std;

/*
 * 已知二叉树的结点按先序遍历下的序列存储在一维数组pre[l1,..,r1]中,
 * 按中序遍历下的序列存储在一维数组in[l2,...,r2]中,
 * 其中l1,l2,r1,r2指示了数组中元素(类型为char)存储的下标范围,
 * 假定二叉树中结点数据值互不相同.试写出由这两个数组构造二叉树的算法.
 */
BTNode *createBT(char pre[], char in[], int l1, int r1, int l2, int r2) {
    if (l1 > r1) {
        return NULL;
    }
    BTNode *s = (BTNode *) malloc(sizeof(BTNode));
    int i;
    for (i = l2; i <= r2; ++i) {
        if (in[i] == pre[l1]) {
            break;
        }
    }
    s->data = in[i];
    s->lchild = createBT(pre, in, l1 + 1, l1 + i - l2, l2, i - 1);
    s->rchild = createBT(pre, in, l1 + i - 12 + 1, r1, i + 1, r2);
    return s;
}

/*
 * 假设二叉树采用二叉链存储结构,设计一个算法,计算一棵给定二叉树的所有结点数.
 */
int countNodes(BTNode *p) {
    if (p == NULL) {
        return 0;
    } else {
        int left = countNodes(p->lchild);
        int right = countNodes(p->rchild);
        return left + right + 1;
    }
}

/*
 * 假设二叉树采用二叉链存储结构,设计一个算法,计算一棵给定二叉树的所有叶子结点数.
 */
int countLeaves(BTNode *p) {
    int left, right;
    if (p == NULL) {
        return 0;
    }
    if (p->lchild == NULL && p->rchild == NULL) {
        return 1;
    } else {
        left = countLeaves(p->lchild);
        right = countLeaves(p->rchild);
        return left + right;
    }
}

/*
 * 假设二叉树采用二叉链存储结构,设计一个算法,利用结点的右孩子指针rchild
 * 将一棵二叉树的叶子结点按照从左往右的顺序串成一个单链表
 */
void convert2List(BTNode *p, BTNode *&head, BTNode *&tail) {
    if (p != NULL) {
        if (p->lchild == NULL && p->rchild == NULL) {
            if (head == NULL) {
                head = p;
                tail = p;
            } else {
                tail->rchild = p;
                tail = p;
            }
        }
        convert2List(p->lchild, head, tail);
        convert2List(p->rchild, head, tail);
    }
}

/*
 * 在二叉树的二叉链存储结构中,增加一个指向双亲结点的parent指针,
 * 设计一个算法,给这个指针赋值,并输出所有结点到根结点的路径.
 */
void constructPath(BTPNode *p, BTPNode *q) {
    if (p != NULL) {
        p->parent = q;
        q = p;
        constructPath(p->lchild, q);
        constructPath(p->rchild, q);
    }
}

void printPath(BTPNode *p) {
    while (p != NULL) {
        cout << p->data << " " << endl;
        p = p->parent;
    }
}

void allPath(BTPNode *p) {
    if (p != NULL) {
        printPath(p);
        allPath(p->lchild);
        allPath(p->rchild);
    }
}

/*
 * 假设满二叉树b的先序遍历已经存在于数组中,此数组名称可自定义,
 * 长度为n,设计一个算法将其转换为后序遍历序列.
 */

void change(char pre[], int L1, int R1, char post[], int L2, int R2) {
    if (L1 <= R1) {
        post[R2] = pre[L1];
        change(pre, L1 + 1, (L1 + 1 + R1) / 2, post, L2, (L2 + R2 - 1) / 2);
        change(pre, (L1 + 1 + R1) / 2 + 1, R1, post, (L2 + R2 - 1) / 2 + 1, R2 - 1);
    }
}

/*
 * 假设二叉树采用二叉链存储结构,设计一个算法,求二叉树b中值为x的结点的层号.
 */
int L = 1;
void leno(BTNode *p, char x) {
    if (p != NULL) {
        if (p->data == x) {
            cout << L << endl;
        }
        ++L;
        leno(p->lchild, x);
        leno(p->rchild, x);
        --L;
    }
}

/*
 * 以数据集合{2,5,7,9,13}为权值构造一棵赫夫曼树,并计算其带权路径长度.
 */

/*
 * 二叉树的双序遍历是指:对于二叉树的每一个结点来说,先访问这个结点,
 * 再按照双序遍历它的左子树,然后再一次访问这个结点,接下来按双序遍历它的右子树.
 * 试写出执行这种双序遍历的算法.
 */
void doubleTravel(BTNode *p) {
    if (p != NULL) {
        visit(p);
        doubleTravel(p->lchild);
        visit(p);
        doubleTravel(p->rchild);
    }
}

/*
 * 设中序线索二叉树的类型为TBTNode *InThTree;
 * ①设计算法,在一棵中序线索二叉树中寻找结点t的子树上中序遍历下的最后一个结点.
 */
TBTNode *last(TBTNode *InThTree) {
    while (InThTree->rtag == 0) {
        InThTree = InThTree->rchild;
    }
    return InThTree;
}

/*
 * ②设计算法,在一棵中序线索二叉树中寻找结点t的中序遍历下的前驱.
 */
TBTNode *prior(TBTNode *InThTree) {
    if (InThTree != NULL && InThTree->ltag == 0) {
        return last(InThTree->lchild);
    }
}

/*
 * ③设计算法,在一棵中序线索二叉树中寻找结点t的前序遍历下的后继.
 */
TBTNode *prenext(TBTNode *InThTree) {
    if (InThTree->ltag == 0) {
        return InThTree->lchild;
    } else if (InThTree->rtag == 0) {
        return InThTree->rchild;
    } else {
        while (InThTree != NULL && InThTree->rtag == 1) {
            InThTree = InThTree->rchild;
        }
        if (InThTree != NULL) {
            return InThTree->rchild;
        }
    }
}

/*
 * 假设二叉树采用二叉链存储结构,设计一个算法,输出根节点到每个叶子结点的路径.
 */
int i;
int top=0;
char pathstack[maxSize];
void allPath(BTNode *p) {
    if (p != NULL) {
        pathstack[top] = p->data;
        ++top;
        if (p->lchild == NULL && p->rchild == NULL) {
            for (i = 0; i < top; ++i) {
                cout << pathstack[i];
            }
        }
        allPath(p->lchild);
        allPath(p->rchild);
        --top;
    }
}
