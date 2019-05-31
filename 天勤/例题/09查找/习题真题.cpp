//
// Created by roguelxx on 19-4-26.
//

#include "../06树与二叉树/结构体定义.h"

/*
 * 设计一个算法,判断给定的二叉树是否是二叉排序树,
 * 假设二叉树已经存储在二叉链表存储结构中,树结点为n,结点值为int型.
 */

int predt = 0; // predt结点前驱值

int isBST(BTNode *p) {
    int b1, b2;
    if (p == NULL) {
        return 1;
    } else {
        b1 = isBST(p->lchild);
        if (b1 == 0 || predt > p->data) {
            return 0;
        }
        predt = p->data;
        b2 = isBST(p->rchild);
        return b2;
    }
}

/*
 * 在平衡二叉树的每个结点中增设一个域lsize,
 * 存储以该结点为根的左子树中的结点个数加1.编写一个算法,
 * 确定树中第k(k>=1)个结点的位置.
 */
NBTNode *getNode(NBTNode *p, int n) {
    if (p == NULL || n < 1) {
        return NULL;
    }
    if (n == p->lsize) {
        return p;
    } else if (n > p->lsize) {
        return getNode(p->rchild, n - p->lsize);
    } else if (n < p->lsize) {
        return getNode(p->lchild, n);
    }
}

