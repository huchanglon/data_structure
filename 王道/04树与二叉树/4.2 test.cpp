//
// Created by roguelxx on 19-6-15.
//

/*
 * 已知一棵二叉树按顺序存储结构进行存储,设计一个算法,求编号分别为i和j的两个结点
 * 的最近的公共祖先结点的值.
 */
ElemType findAncestor(ElemType tree[], int i, int j) {
    if (tree[i] == '#' || tree[j] == '#') {
        return NULL;
    }
    if (i > j) {
        i = i / 2;
    } else if (j > i) {
        j = j / 2;
    } else {
        return tree[i];
    }
    return findAncestor(tree, i, j);
}

