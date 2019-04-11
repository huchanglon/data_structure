//
// Created by roguelxx on 19-3-31.
//

#include "malloc.h"
#define maxSize 10


typedef struct BTNode {
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

/*
 * tag = 0, child,
 * tag= 1, successor, predecessor
 */
typedef struct TBTNode {
    char data;
    int ltag, rtag;
    struct TBTNode *lchild;
    struct TBTNode *rchild;
} TBTNode;

typedef struct BTPNode {
    char data;
    struct BTPNode *parent;
    struct BTPNode *lchild;
    struct BTPNode *rchild;
} BTPNode;

void visit(BTNode *p) {}
void visit(TBTNode *p) {}
