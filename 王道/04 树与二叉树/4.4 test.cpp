//
// Created by roguelxx on 19-6-24.
//

/*
 * 设计算法,求以孩子兄弟表示法存储的森林的叶子结点.
 */

typedef struct CSNode{
    ElemType data;
    struct CSNode *fch, *nsib;
}CSNode, *CSTree;

int CSTreeChildren(CSTree T) {
    if (T == NULL) {
        return 0;
    } else if (T->fch == NULL) {
        return 1 + CSTreeChildren(T->nsib);
    } else {
        return CSTreeChildren(T->fch) + CSTreeChildren(T->nsib);
    }
}

/*
 * 以孩子兄弟链表为存储结构,设计递归算法求树的深度.
 */

int CSTreeDepth(CSTree T) {
    if (T == NULL) {
        return 0;
    } else {
        int hc, hs;
        hc = CSTreeDepth(T->fch);
        hs = CSTreeDepth(T->nsib);
        return hc + 1 > hs ? hc + 1 : hs;
    }
}

/*
 * 已知一棵树的层次序列及每个结点的度,编写算法,构造此树的孩子兄弟链表.
 */
void createCSTree(CSTree &T, ElemType e[], int degree[], int n) {
    CSTRee *pointer = new CSTree[maxSize];
    int i, j, d, k = 0;
    for (i = 0; i < n; ++i) {
        CSNode *p = (CSNode *) malloc(sizeof(CSNode));
        p->data = e[i];
        p->fch = NULL;
        p->nsib = NULL;
        pointer[i] = p;
    }
    for (i = 0; i < n; ++i) {
        d = degree[i];
        if (d != 0) {
            ++k;
            pointer[i]->nsib = pointer[k];
            for (j = 2; j <= d; ++j) {
                ++k;
                pointer[k - 1]->nsib = pointer[k];
            }
        }
    }
    T = pointer[0];
    delete[] pointer;
}