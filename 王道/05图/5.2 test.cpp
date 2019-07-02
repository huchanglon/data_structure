//
// Created by roguelxx on 19-6-28.
//

/*
 * 写出从图的邻接表表示转换成邻接矩阵表示的算法.
 */
void TableToMatrix(ALGraph &g) {
    int vexnum = g.vexnum, i, j;
    int matrix[vexnum][vexnum];
    for (i = 0; i < vexnum; ++i) {
        for (j = 0; j < vexnum; ++j) {
            matrix[i][j] = 0;
        }
    }
    ArcNode node;
    for (i = 0; i < vexnum; ++i) {
        node = g.vertices[i]->first;
        while (node != NULL) {
            matrix[i][node.adjvex] = 1;
            node = node.nextarc;
        }
    }
}
