//
// Created by roguelxx on 19-4-16.
//

#define maxSize 100

#include "malloc.h"

// 邻接矩阵
typedef struct {
    int no;
    char info;
} VertexType;

typedef struct {
    int edges[maxSize][maxSize];
    int n, e;
    VertexType vex[maxSize];
} MGraph;

// 邻接表
typedef struct ArcNode {
    int adjvex;
    int info;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct {
    char data;
    ArcNode *firstarc;
} VNode;

typedef struct {
    VNode adjlist[maxSize];
    int n, e;
} AGraph;

void Visit(int v);

