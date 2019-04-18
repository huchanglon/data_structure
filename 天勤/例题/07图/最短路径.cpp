//
// Created by roguelxx on 19-4-18.
//

#include <iostream>
#include "结构体定义.h"

/*
 * Dijkstra's Algorithm
 */
void Dijkstra(MGraph g, int v, int dist[], int path[]) {
    int i, j, min, u;
    int set[maxSize];
    // 初始化辅助数组
    for (i = 0; i < g.n; ++i) {
        dist[i] = g.edges[v][i];
        set[i] = 0;
        if (g.edges[v][i] < INF) {
            path[i] = v;
        } else {
            path[i] = -1;
        }
    }
    set[v] = 1;
    path[v] = -1;
    min = INF;
    for (i = 0; i < g.n - 1; ++i) {
        for (j = 0; j < g.n; ++j) {
            if (set[j] == 0 && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        set[u] = 1;
        for (j = 0; j < g.n; ++j) {
            if (set[j] == 0 && dist[u] + g.edges[u][j] < dist[j]) {
                dist[j] = dist[u] + g.edges[u][j];
                path[j] = u;
            }
        }
    }
}

void printPath(int path[], int a) {
    int stack[maxSize], top = -1;
    while (path[a] != -1) {
        stack[++top] = a;
        a = path[a];
    }
    stack[++top] = a;
    while (top != -1) {
        cout << stack[top--] << " ";
    }
    cout << endl;
}

/*
 * Floyd's Algorithm
 */
void Floyd(MGraph g, int path[][maxSize]) {
    int i, j, k;
    int A[maxSize][maxSize];
    // 初始化数据
    for (i = 0; i < g.n; ++i) {
        for (j = 0; j < g.n; ++j) {
            A[i][j] = g.edges[i][j];
            path[i][j] = -1;
        }
    }
    for (k = 0; k < g.n; ++k) {
        for (i = 0; i < g.n; ++i) {
            for (j = 0; j < g.n; ++j) {
                if (A[i][j] < A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}

void printPath(int u, int v, int path[][maxSize]) {
    if (path[u][v] == -1) {
        cout << path[u][v];
    } else {
        int mid = path[u][v];
        printPath(u, mid, path);
        printPath(mid, v, path);
    }
}

