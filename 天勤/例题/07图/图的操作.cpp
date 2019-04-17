//
// Created by roguelxx on 19-4-16.
//

#include "结构体定义.h"

int visit[maxSize];
/*
 * visit[]是一个全局数组,作为顶点的访问标记,初始时所有元素均为0,表示所有顶点都未被访问.
 */
void DFS(AGraph *G, int v) {
    ArcNode *p;
    visit[v] = 1;
    Visit(v);
    p = G->adjlist[v].firstarc;
    while (p != NULL) {
        if (visit[p->adjvex] == 0) {
            DFS(G, p->adjvex);
        }
        p = p->nextarc;
    }
}

void BFS(AGraph *G, int v, int visit[maxSize]) {
    ArcNode *p;
    int queue[maxSize], front = 0, rear = 0;
    int j;
    Visit(v);
    visit[v] = 1;
    rear = (rear + 1) % maxSize;
    queue[rear] = v;
    while (front != rear) {
        front = (front + 1) % maxSize;
        j = queue[front];
        p = G->adjlist[j].firstarc;
        while (p != NULL) {
            if (visit[p->adjvex] == 0) {
                Visit(p->adjvex);
                visit[p->adjvex] = 1;
                rear = (rear + 1) % maxSize;
                queue[rear] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
}
/*
 * 针对非连通图遍历
 */
void dfs(AGraph *g) {
    int i;
    for (i = 0; i < g->n; ++i) {
        if (visit[i] == 0) {
            DFS(g, i);
        }
    }
}

void bfs(AGraph *g) {
    int i;
    for (i = 0; i < g->n; ++i) {
        if (visit[i] == 0) {
            BFS(g, i, visit);
        }
    }
}

/*
 * 设计一个算法,求不带权无向连通图G中距离顶点v最远的一个顶点.
 */
int BFS(AGraph *g, int v) {
    int visit[maxSize];
    int i, j;
    ArcNode *p;
    for (i = 0; i < g->n; ++i) {
        visit[i] = 0;
    }
    int queue[maxSize], front = 0, rear = 0;
    visit[v] = 1;
    rear = (rear + 1) % maxSize;
    queue[rear] = v;
    while (front != rear) {
        front = (front + 1) % maxSize;
        j = visit[front];
        p = g->adjlist[j].firstarc;
        while (p != NULL) {
            if (visit[p->adjvex == 0]) {
                visit[p->adjvex] = 1;
                rear = (rear + 1) % maxSize;
                queue[rear] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
    return j;
}

/*
 * 设计一个算法,判断无向图G是否是一棵树.若是树,返回1,否则返回0.
 */
void DFS2(AGraph *g, int v, int &vn, int &en) {
    ArcNode *p;
    visit[v] = 1;
    ++vn;
    p = g->adjlist[v].firstarc;
    while (p != NULL) {
        ++en;
        if (visit[p->adjvex] == 0) {
            DFS2(g, p->adjvex, vn, en);
        }
        p = p->nextarc;
    }
}

int GisTree(AGraph *g) {
    int vn = 0, en = 0, i;
    for (i = 0; i < g->n; ++i) {
        visit[i] = 0;
    }
    DFS2(g, 1, vn, en);
    if (vn == g->n && en / 2 == (g->n - 1)) {
        return 1;
    } else {
        return 0;
    }
}

/*
 * 图采用邻接表存储,设计一个算法,判别顶点i和顶点j(i!=j)之间是否有路径.
 */
int isConnected(AGraph *g, int i, int j) {
    int k;
    for (k = 0; i < g->n; ++k) {
        visit[k] = 0;
    }
    DFS(g, i);
    if (visit[j] == 1) {
        return 1;
    } else {
        return 0;
    }
}
