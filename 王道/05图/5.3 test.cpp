//
// Created by roguelxx on 19-7-2.
//

/*
 * 设计一个算法,判断一个无向图是否为一棵树.若是一棵树,则算法返回true,反之返回false.
 */

bool visited[maxSize];

bool IsTree(Graph &G) {
    int i;
    for (i = 1; i <= G.vexnum; ++i) {
        visited[i] = false;
    }
    int Vnum = 0, Enum = 0;
    DFS(G, 1, Vnum, Enum, visited);
    if (Vnum == G.vexnum && Enum == 2 * (G.vexnum - 1)) {
        return true;
    } else {
        return false;
    }
}

void DFS(Graph &G, int v, int &Vnum, int &Enum, int visited[]) {
    visited[v] = true;
    int w = FirstNeighbor(G, v);
    while (w != 1) {
        Enum++;
        if (!visited[w]) {
            DFS(G, w, Vnum, Enum, visited);
        }
        w = NextNeighbor(G, v, w);
    }
}

/*
 * 写出图的深度优先搜索DFS算法的非递归算法(图采用邻接表形式).
 */
void DFSNonRecur(AGraph &G, int v) {
    int i, k, w;
    InitStack(S);
    for (i = 1; i <= G.vexnum; ++i) {
        visited[i] = false;
    }
    Push(S, v);
    visited[v] = true;
    while (!Empty(S)) {
        Pop(S, k);
        visit(k);
        for (w = FirstNeighbor; w >= 0; w = NextNeighbor) {
            if (!visited[w]) {
                Push(S, w);
                visited[w] = true;
            }
        }
    }
}

/*
 * 分别采用基于深度优先遍历和广度优先遍历算法判别以邻接表方式存储的有向图中是否存在
 * 由顶点vi到vj的路径(v!=j).算法中涉及的图的基本操作必须在此存储结构上实现.
 */
bool HasRouteDFS(AGraph G, int v, int j) {
    int k;
    if (v == j) {
        return true;
    } else {
        visited[v] = true;
        for (k = FirstNeibor(G, v); k >= 0; k = NextNeighbor(G, v, k)) {
            if (!visited[k] && HasRouteDFS(G, k, j)) {
                return true;
            }
        }
    }
    return false;
}

bool HasRouteBFS(AGraph G, int v, int j) {
    // 初始化visited数组
    InitQueue(Q);
    EnQueue(Q, v);
    visited[v] = true;
    int k, w;
    while (!Empty(Q)) {
        DeQueue(Q, k);
        for (w = FirstNeighbor(G, v); w >= 0; w = NextNeightbor(G, v, w)) {
            if (!visited[w]) {
                if (w == j) {
                    return true;
                }
                EnQueue(Q, w);
                visited[w] = true;
            }
        }
    }
    return false;
}

bool HasRoute1(AGraph G, int v, int j) {
    BFS(G, v);
    return visited[j];
}

void BFS(AGraph G, int v) {
    int i, k, w;
    InitQueue(Q);
    for (i = 1; i <= G.vexnum; ++i) {
        visited[i] = false;
    }
    EnQueue(Q, v);
    visited[k] = true;
    visit(v);
    while (!Empty(Q)) {
        DeQueue(Q, k);
        for (w = FirstNeighbor(G, i); w >= 0; w = NextNeighbor(G, i, w)) {
            if (!visited[w]) {
                visit(w);
                EnQueue(Q, w);
                visited[w] = true;
            }
        }
    }
}

/*
 * 假设图用邻接表表示,设计一个算法,输出从顶点vi到顶点vj的所有简单路径.
 */

void PrintRoute(AGraph *G, int v, int j, int path[], int d) {
    int i, w;
    ArcNode *p;
    visited[v] = true;
    d++;
    path[d] = v;
    if (v == j) {
        print(path[]);
    }
    p = G->adjlist[v].firstArc;
    while (p != NULL) {
        w = p->adjvex;
        if (!visited[w]) {
            PrintRoute(G, w, j, path, d);
        }
        p = p->nextarc;
    }
    visited[v] = false;
}