//
// Created by roguelxx on 19-4-16.
//

using namespace std;

#define maxSize 100
// 已经定义的比图中所有边权值都大的常量
#define INF 1000

#include "malloc.h"
#include <iostream>

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
    int count;  // 顶点入度
    ArcNode *firstarc;
} VNode;

typedef struct {
    VNode adjlist[maxSize];
    int n, e;
} AGraph;

void Visit(int v);

