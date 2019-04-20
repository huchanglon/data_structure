//
// Created by roguelxx on 19-4-19.
//

#include "结构体定义.h"

/*
 * 判断以邻接表方式存储的有向图中是否存在顶点vi到顶点vj的路径.
 */
int isConnected(AGraph *g, int vi, int vj) {
    int queue[maxSize], front = 0, rear = 0;
    int visit[maxSize];
    int i, j;
    for (i = 0; i < g->n; ++i) {
        visit[i] = 0;
    }
    ArcNode *p;
    rear = (rear + 1) % maxSize;
    queue[rear] = vi;
    visit[vi] =1;
    while (front != rear) {
        front = (front + 1) % maxSize;
        j = queue[front];
        if (j == vj) {
            return 1;
        }
        p = g->adjlist[j].firstarc;
        while (p != NULL) {
            if (visit[p->adjvex] == 0) {
                rear = (rear + 1) % maxSize;
                queue[rear] = p->adjvex;
                visit[p->adjvex] = 1;
            }
            p = p->nextarc;
        }
    }
    return 0;
}

/*
 * 在有向图G中,如果r到G中的每个结点都有路径可达,则称结点r为G的根节点.
 * 编写一个算法判断有向图G是否有根,若有,则打印出所有根节点的值.
 * 假设图已经存在于邻接表g中.
 */
int visit[maxSize], sum;
void haveRoot(AGraph *g, int r) {
    visit[r] = 1;
    ++sum;
    ArcNode *p = g->adjlist[r].firstarc;
    while (p != NULL) {
        if (visit[p->adjvex] == 0) {
            haveRoot(g, p->adjvex);
        }
        p = p->nextarc;
    }
}

void printRoot(AGraph *g) {
    int i, j;
    for (i = 0; i < g->n; ++i) {
        sum = 0;
        for (j = 0; j < g->n; ++j) {
            visit[j] = 0;
        }
        haveRoot(g, i);
        if (sum == g->n) {
            cout << i << endl;
        }
    }
}
/*
 * 写出从无权图的邻接表表示转换成邻接矩阵表示的算法.
 */
void table2matrix(MGraph &g1, AGraph *g2) {
    int i, j;
    ArcNode *p;
    for (i = 0; i < g1.n; ++i) {
        for (j = 0; j < g1.n; ++j) {
            g1.edges[i][j] = 0;
        }
    }
    for (i = 0; i < g2->n; ++i) {
        p = g2->adjlist[i].firstarc;
        while (p) {
            g1.edges[i][p->adjvex] = 1;
            p = p->nextarc;
        }
    }
}

/*
 * 有向图用邻接表表示,图有n个顶点,表示为1~n,试写一个算法求顶点k的入度.
 */
int indegree(MGraph g, int k) {
    int i, sum = 0;
    for (i = 0; i < g.n; ++i) {
        if (g.edges[i][k] != 0) {
            ++sum;
        }
    }
    return sum;
}
int indegree(AGraph *g, int k) {
    int i, sum = 0;
    ArcNode *p;
    for (i = 0; i < g->n; ++i) {
        p = g->adjlist[i].firstarc;
        while (p != NULL) {
            if (p->adjvex == k) {
                ++sum;
                break;
            }
            p = p->nextarc;
        }
    }
    return sum;
}

/*
 * 写出以邻接表为存储结构的图的深度优先搜索DFS算法的非递归算法
 */
void DFS(AGraph *g, int v) {
    int visit[maxSize];
    int stack[maxSize], top = -1;
    int i, j;
    for (i = 0; i < g->n; ++i) {
        visit[i] = 0;
    }
    visit[v] = 1;
    stack[++top] = v;
    ArcNode *p;
    while (top != -1) {
        j = stack[top];
        p = g->adjlist[j].firstarc;
        while (p != NULL && visit[p->adjvex] == 1) {
            p = p->nextarc;
        }
        if (p == NULL) {
            --top;
        } else {
            visit[p->adjvex];
            stack[++top] = p->adjvex;
        }
    }
}
