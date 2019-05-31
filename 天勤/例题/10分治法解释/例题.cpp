//
// Created by roguelxx on 19-4-28.
//

#include <iostream>
#include "../06树与二叉树/结构体定义.h"
#include "../07图/结构体定义.h"

using namespace std;

/*
 * 用分治法打印数组a[l,...,r]
 */
void print(int a[], int l, int r) {
    if (l > r) {
        return;
    } else if (l == r) {
        cout << a[l] << "";
    } else {
        print(a, l + 1, r);
    }
}

/*
 * 假设存在一个函数divide(),可以将一个数组a[l,...,r]分成两部分,返回分界点
 * 元素a[l]为分界线,小于a[l]的元素在左边,大于a[l]的元素在右边.
 * 试用分治法,对数组a[l,...,r]中的元素进行快速排序.
 */
int divide(int a[], int l, int r);

void quickSort(int a[], int l, int r) {
    int mid;
    if (l >= r) {
        return;
    } else {
        mid = divide(a, l, r);
        quickSort(a, l, mid - 1);
        quickSort(a, mid + 1, r);
    }
}

/*
 * 一棵二叉树存储在二叉链表中,用分治法打印所有节点值,根节点由p所指.
 */
void printBT(BTNode *p) {
    if (p == NULL) {
        return;
    } else {
        cout << p->data << "";
        printBT(p->lchild);
        printBT(p->rchild);
    }
}

/*
 * 一个连通图G用邻接表存储,用分治法打印图中的所有顶点值,假设图中结点数大于1.
 */
int visited[maxSize];
void printGraph(AGraph *g, int v) {
    ArcNode *p;
    visited[v] = 1;
    cout << v << "";
    p = g->adjlist[v].firstarc;
    while (p != NULL) {
        if (visited[p->adjvex] == 0) {
            printGraph(g, p->adjvex);
        }
        p = p->nextarc;
    }
}

/*
 * 已知二叉树的先序遍历序列和中序遍历序列,分别存储在a[l1,...,r1]与
 * b[l2,...,r2]两个数组中,用分治法由这两个序列建立一棵二叉树,并存储在二叉链表存储结构中.
 */
BTNode* createBT(int a[], int b[], int l1, int l2, int r1, int r2) {
    int k;
    if (l1 > r1) {
        return NULL;
    } else {
        BTNode *s = (BTNode *) malloc(sizeof(BTNode));
        s->data = a[l1];
        for (k = l2; k <= r2; ++k) {
            if (a[l1] = b[k]) {
                break;
            }
        }
        s->lchild = createBT(a, b, l1 + 1, l1 + k - l2, l2, k - 1);
        s->rchild = createBT(a, b, l1 + k - l2 + 1, r1, k + 1, r2);
        return s;
    }
}

/*
 * 汉诺塔问题,有3根柱子:x、y、z,第一根柱子上有n个盘子,从上到下依次增大,
 * 要求将第一根柱子上的所有盘子移动到第三根柱子上,整个过程都必须满足一根柱子上的
 * 盘子从上到下依次增大.
 */
void move(int x, int z) {}

void Han(int x, int y, int z, int n) {
    if (n == 1) {
        move(x, z);
    } else {
        Han(x, y, z, n - 1);
        move(x, z);
        Han(y, x, z, n - 1);
    }
}
