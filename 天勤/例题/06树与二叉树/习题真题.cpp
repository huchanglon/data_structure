//
// Created by roguelxx on 19-4-4.
//

#include "结构体定义.h"

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
