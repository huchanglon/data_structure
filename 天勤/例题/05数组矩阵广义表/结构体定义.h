//
// Created by roguelxx on 19-3-29.
//

typedef struct {
    int val;
    int i, j;
} Trimat;

typedef struct OLNode {
    int row, col;
    struct OLNode *right, *down;
    float value;
} OLNode;

typedef struct {
    OLNode *rhead, *chead;
    int m, n, k;
} CrossList;