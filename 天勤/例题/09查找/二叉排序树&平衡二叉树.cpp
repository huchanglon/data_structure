//
// Created by roguelxx on 19-4-25.
//

#include "../06树与二叉树/结构体定义.h"

/*
 * 查找算法
 */
BTNode* BSTSearch(BTNode *p, int key) {
    if (p == NULL) {
        return NULL;
    } else {
        if (p->data == key) {
            return p;
        } else if (p->data < key) {
            return BSTSearch(p->rchild, key);
        } else {
            return BSTSearch(p->lchild, key);
        }
    }
}

/*
 * 插入算法
 */
int BSTInsert(BTNode *&p, int key) {
    if (p == NULL) {
        BTNode *q = (BTNode *) malloc(sizeof(BTNode));
        q->data = key;
        q->lchild = q->rchild = NULL;
        return 1;
    } else {
        if (key == p->data) {
            return 0;
        } else if (key > p->data) {
            return BSTInsert(p->rchild, key);
        } else if (key < p->data) {
            return BSTInsert(p->lchild, key);
        }
    }
}

/*
 * 构造算法
 */
void createBST(BTNode *&p, int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        BSTInsert(p, arr[i]);
    }
}

/*
 * 删除算法
 */

