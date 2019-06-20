//
// Created by roguelxx on 19-6-15.
//

/*
 * 写出二叉树自下而上、从右到左的层次遍历算法.
 */
void reverseLevelTravel(BiTree T) {
    if (T != NULL) {
        InitQueue(Q);
        InitStack(S);
        BiTree *p;
        EnQueue(Q, T);
        while (!Empty(Q)) {
            DeQueue(Q, p);
            Push(Q, p);
            if (p->lchild) {
                EnQueue(Q, p->lchild);
            }
            if (p->rchild) {
                EnQueue(Q, p->rchild);
            }
        }
        while (!Empty(S)) {
            Pop(S, p);
            visit(p);
        }
    }
}

/*
 * 假设二叉树采用二叉链表存储结构,设计一个非递归算法求二叉树的高度.
 */
int BtDepth(BiTree T) {
    if (!T) {
        return 0;
    } else {
        int level = 0, last = 0, front = -1, rear = -1;
        BiTree Q[maxSize];
        Q[++rear] = T;
        BiTree *p;
        while (front < rear) {
            p = Q[++front];
            if (p->lchild) {
                Q[++rear] = p->lchild;
            }
            if (p->rchild) {
                Q[++rear] = p->rchild;
            }
            if (front == last) {
                level++;
                last = rear;
            }
        }
        return level;
    }
}

int BtDepth2(BiTree T) {
    if (!T) {
        return 0;
    } else {
        int ldep = BtDepth(T->lchild);
        int rdep = BtDepth(T->rchild);
        return ldep > rdep ? ldep + 1 : rdep + 1;
    }
}

/*
 * 设一棵二叉树中各结点的值互不相同,其先序遍历序列和中序遍历序列分别存于两个
 * 一维数组A[1...n]和B[1...n]中,编写算法建立该二叉树的二叉链表.
 */
BiTree PreInCreat(ElemType A[], ElemType B[], int l1, int h1, int l2, int h2) {
    BiTNode root = (BiTNode *) malloc(sizeof(BiTNode));
    root->data = A[l1];
    int i = l2;
    while (B[i] != root->data) {
        ++i;
    }
    int llen = i - l2;
    int rlen = h2 - i;
    if (llen) {
        root->lchild = PreInCreat(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
    } else {
        root->lchild = NULL;
    }
    if (rlen) {
        root->rchild = PreInCreat(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
    } else {
        root->rchild = NULL;
    }
    return root;
}

/*
 * 二叉树按二叉链表形式存储,写一个判定给定二叉树是否是完全二叉树的算法.
 */
bool IsCompleteBiTree(BiTree T) {
    if (!T) {
        return true;
    }
    InitQueue(Q);
    EnQueue(Q, T);
    BiTree *p;
    while (!Empty(Q)) {
        DeQueue(Q, p);
        if (p != NULL) {
            EnQueue(Q, p->lchild);
            EnQueue(Q, p->rchild);
        } else {
            while (!Empty(Q)) {
                DeQueue(Q, p);
                if (p != NULL) {
                    return false;
                }
            }
        }
    }
    return true;
}

/*
 * 假设二叉树采用二叉链表存储结构存储,设计一个算法,计算一棵给定二叉树的所有双
 * 分支结点个数.
 */
int DsonNodes1(BiTree T) {
    InitStack(s);
    BiTree *p = T;
    int num = 0;
    while (p != NULL || !Empty(s)) {
        if (p != NULL) {
            Push(s, p);
            p = p->lchild;
        } else {
            Pop(s, p);
            if (p->lchild && p->rchild) {
                num++;
            }
            p = p->rchild;
        }
    }
    return num;
}

int DsonNodes2(BiTree T) {
    if (T = NULL) {
        return 0;
    } else if (T->lchild != NULL && T->rchild != NULL) {
        return DsonNodes2(T->lchild) + DsonNodes2(T->rchild) + 1;
    } else {
        return DsonNodes2(T->lchild) + DsonNodes2(T->rchild);
    }
}

/*
 * 设树B是一棵采用链式结构存储的二叉树,编写一个算法,把树中所有节点的左右子树
 * 进行交换的算法.
 */
void SwapChildren(BiTree T) {
    if (T) {
        SwapChildren(T->lchild);
        SwapChildren(T->rchild);
        BiTree temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
}

/*
 * 假设二叉树采用二叉链存储结构存储,设计一个算法,求先序遍历序列中第k个结点的值,
 * 1<=k<=结点总数.
 */
ElemType LocateNode(BiTree T, int k) {
    if (T != NULL) {
        InitStack(s);
        Push(s, T);
        BiTree *p;
        int num = 0;
        while (!Empty(s)) {
            Pop(s, p);
            num++;
            if (num == k) {
                return p->data;
            }
            if (p->rchild) {
                Push(s, p->rchild);
            }
            if (p->lchild) {
                Push(s, p->lchild);
            }
        }
    }
    return NULL;
}

/*
 * 已知二叉树以二叉链表存储,编写算法,对于树中每个元素值为x的结点,删去以它为
 * 根的子树,并释放相应的空间.
 */
void DelByElemType(BiTree T, ElemType x) {
    if (T != NULL) {
        if (T->data == x) {
            InitStack(S);
            BiTree *r = NULL, *p = T;
            while (p != NULL || !Empty(S)) {
                if (p != NULL) {
                    Push(S, p);
                    p = p->lchild;
                } else {
                    GetTop(S, p);
                    if (p->rchild != NULL && p->rchild != r) {
                        p = p->rchild;
                        Push(S, p);
                        p = p->lchild;
                    } else {
                        Pop(S, p);
                        free(p);
                        r = p;
                        p = NULL;
                    }
                }
            }
        }
        DelByElemType(T->lchild, x);
        DelByElemType(T->rchild, x);
    }
}

void DelTree(BiTree T) {
    if (T != NULL) {
        DelTree(T->lchild);
        DelTree(T->rchild);
        free(T);
    }
}

void DelByElemType2(BiTree T, ElemType x) {
    if (T != NULL) {
        if (T->data == x) {
            DelTree(T);
            exit(0);
        }
        InitQueue(Q);
        BiTree *p;
        EnQueue(Q, T);
        while (!Empty(Q)) {
            DeQueue(Q, p);
            if (p->lchild) {
                if (p->lchild->data == x) {
                    DelTree(p->lchild);
                    p->lchild = NULL;
                } else {
                    EnQueue(Q, p->lchild);
                }
            }
            if (p->rchild) {
                if (p->rchild->data == x) {
                    DelTree(p->rchild);
                    p->rchild = NULL;
                } else {
                    EnQueue(Q, p->rchild);
                }
            }
        }
    }
}

/*
 * 设一棵二叉树的结点结构为(llink,info,rlink),root为指向该二叉树根节点的指针,
 * p和q分别为指向该二叉树中任意两个结点的指针,编写算法ancestor(root, p, q, r),
 * 找到p和q的最近公共祖先r,假设p在q的左边.
 */
typedef struct {
    BiTree t;
    int tag;    // tag=0表示左子女已被访问,tag=1表示右子女已被访问
} stack;
stack s[], s1[];
BiTree Ancestor(BiTree root, BiTNode *p, BiTNode *q) {
    int top = -1, i, j;
    BiTree bt = root;
    while (bt != NULL || top > -1) {
        while (bt != NULL && bt != p && bt != q) {
            s[++top] = bt;
            s[top].tag = 0;
            bt = bt->llink;
        }
        while (top > -1 && s[top].tag == 1) {
            if (s[top].t == p) {
                for (i = 0; i <= top; ++i) {
                    s1[i] = s[i];
                    top1 = top;
                }
            }
            if (s[top].t == q) {
                for (i = top; i > -1; --i) {
                    for (j = top1; j > -1; --j) {
                        if (s1[j].t == s[i].t) {
                            return s[i].t;
                        }
                    }
                }
                --top;
            }
        }
        if (top != -1) {
            s[top].tag = 1;
            bt = s[top].t->rchild;
        }
    }
    return NULL;
}

/*
 * 假设二叉树采用二叉链表存储结构,设计一个算法,求非空二叉树b的宽度.
 */
typedef struct {
    BiTree data[maxSize];
    int level[maxSize];
    int front, rear;
} q;

int BiTreeWidth(BiTree b) {
    BiTree p;
    int max, i, n, k;
    q.rear = q.front = -1;
    q.rear++;
    q.data[q.rear] = b;
    q.level[q.rear] = 1;
    while (q.rear > q.front) {
        q.front++;
        p = q.data[q.front];
        k = q.level[q.front];
        if (p->lchild) {
            q.rear++;
            q.data[q.rear] = p->lchild;
            q.level[q.rear] = k + 1;
        }
        if (p->rchild) {
            q.rear++;
            q.data[q.rear] = p->rchild;
            q.level[q.rear] = k + 1;
        }
    }
    max = 0, i = 0, k = 1;
    while (i <= q.rear) {
        n = 0;
        while (i<=q.rear&&q.level[i] == k) {
            n++;
            i++;
        }
        if (n > max) {
            max = n;
        }
    }
    return max;
}

/*
 * 设有一棵满二叉树(所有结点值均不同),已知其先序序列为pre,设计一个算法求其后序序列post.
 */
void PreToPost(ElemType pre[], int l1, int h1, ElemType post[], int l2, int h2) {
    int half;
    if (l1 <= h1) {
        half = (h1 - l1) / 2;
        post[h2] = pre[l1];
        PreToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
        PreToPost(pre, l1 + half + 1, h1, post, l2 + half, h2 - 1);
    }
}

/*
 * 设计一个算法将二叉树的结点按从左到右的顺序连成一个单链表,表头指针为head.二叉树
 * 按照二叉链表方式存储,连接时用叶结点的右指针域来存放单链表指针.
 */
LinkList LinkLeafNodes(BiTree T, LinkList *head) {
    LinkList *pre = NULL;
    BiTree p = T;
    InitStack(S);
    while (p != NULL||!Empty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        } else {
            Pop(S, p);
            if (p->lchild == NULL && p->rchild == NULL) {
                if (head == NULL) {
                    head = p;
                    pre = p;
                } else {
                    pre->rchild = p;
                    pre = p;
                }
            }
            p = p->rchild;
        }
    }
    pre->rchild = NULL;
    return head;
}

LinkedList head, pre = NULL;
LinkList LinkLeafNodes2(BiTree T) {
    if (T != NULL) {
        LinkLeafNodes2(T->lchild);
        if (T->lchild == NULL && T->rchild == NULL) {
            if (head == NULL) {
                head = T;
                pre = T;
            } else {
                pre->rchild = T;
                pre = T;
            }
        }
        LinkLeafNodes2(T->rchild);
        pre->rchild = NULL;
    }
    return head;
}

/*
 * 设计一个算法,判断两棵二叉树是否相似.所谓相似,指的是T1和T2都是空的二叉树或都
 * 只有一个根结点;或T1的左子树和T2的左子树相似,T1的右子树和T2的右子树相似.
 */
bool IsSimilar(BiTree T1, BiTree T2) {
    if (T1 == NULL && T2 == NULL) {
        return true;
    } else if (T1 == NULL || T2 == NULL) {
        return false;
    } else {
        return IsSimilar(T1->lchild, T2->lchild) && IsSimilar(T1->rchild, T2->rchild);
    }
}

/*
 * 写出在中序线索二叉树中查找指定结点在后序的前驱结点的算法.
 */
BiThrTree InPostPre(BiThrTree t, BiThrTree p) {
    BiThrTree q;
    if (p->rtag == 0) {
        q = p->rchild;
    } else if (p->ltag == 0) {
        q = p->lchild;
    } else if (p->lchild == NULL) {
        q = NULL;
    } else {
        while (p->ltag == 1 && p->lchild != NULL) {
            p = p->lchild;
        }
        if (p->ltag == 0) {
            q = p->lchild;
        } else {
            q = NULL;
        }
    }
    return q;
}