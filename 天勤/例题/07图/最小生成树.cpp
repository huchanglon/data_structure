//
// Created by roguelxx on 19-4-17.
//

#include "结构体定义.h"


/*
 * Prim's Algorithm
 */
void Prim(MGraph g, int v0, int &sum) {
    int lowcost[maxSize], vset[maxSize], v;
    int i, j, k, min;
    v = v0;
    for (i = 0; i < g.n; ++i) {
        lowcost[i] = g.edges[v0][i];
        vset[i] = 0;
    }
    vset[v] = 1;
    sum = 0;
    for (i = 0; i < g.n - 1; ++i) {
        min = INF;
        // 找出侯选边中的最小者
        for (j = 0; j < g.n; ++j) {
            if (vset[j] == 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }
        }
        vset[k] = 1;
        v = k;
        sum += min;
        // 以刚并入的顶点v为媒介更新侯选边
        for (j = 0; j < g.n; ++j) {
            if (vset[j] == 0 && g.edges[v][j] < lowcost[j]) {
                lowcost[j] = g.edges[v][j];
            }
        }
    }
}

/*
 * Kruskal's Algorithm
 */
typedef struct {
    int a, b; // a,b为一条边所连的两个顶点
    int w;    // 边的权值
} Road;

void sort(Road road[], int edges); // 对road数组中的E条边按其权值从小到大排序.

Road road[maxSize];
int v[maxSize]; // 并查集
int getRoot(int a) {
    while (a != v[a]) {
        a = v[a];
    }
    return a;
}
void Kruskal(MGraph g, int &sum, Road road[]) {
    int i, N, E, a, b;
    N = g.n;
    E = g.e;
    sum = 0;
    for (i = 0; i < N; ++i) {
        v[i] = i;
    }
    sort(road, E);
    for (i = 0; i < E; ++i) {
        a = getRoot(road[i].a);
        b = getRoot(road[i].b);
        if (a != b) {
            v[a] = b;
            sum += road[i].w;
        }
    }
}


