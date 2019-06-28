//
// Created by roguelxx on 19-6-26.
//

/*
 * 统计二叉树结点总数
 */
int TotalNodes(BiTree bt) {
    if (bt == NULL) {
        return 0;
    } else {
        int l = TotalNodes(bt->lchild);
        int r = TotalNodes(bt->rchild);
        return l + r + 1;
    }
}

/*
 * 统计二叉树中度为1的结点个数
 */
