//
// Created by roguelxx on 19-4-18.
//

#include "结构体定义.h"

/*
 * TopSort
 */
int TopSort(AGraph *g) {
    int i, j, n = 0;
    int stack[maxSize], top = -1;
    ArcNode *p;
    for (i = 0; i < g->n; ++i) {
        if (g->adjlist[i].count == 0) {
            stack[++top] = i;
        }
    }
    while (top != -1) {
        i = stack[top--];
        ++n;
        cout << i << "";
        p = g->adjlist[i].firstarc;
        while (p != NULL) {
            j = p->adjvex;
            --(g->adjlist[j].count);
            if (g->adjlist[j].count == 0) {
                stack[++top] = j;
            }
            p = p->nextarc;
        }
    }
    if (n == g->n) {
        return 1;
    } else {
        return 0;
    }
}
