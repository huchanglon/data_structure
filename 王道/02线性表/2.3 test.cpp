//
// Created by roguelxx on 19-6-6.
//

/*
 * 设计一个递归算法,删除不带头结点的单链表L中所有值为x的结点
 */
void deleteSameValue1(LinkList &L, ElemType x) {
    if (L == NULL) {
        return;
    }
    LNode *p;
    if (L->data == x) {
        p = L;
        L = L->next;
        free(p);
        deleteSameValue(L, x);
    } else {
        deleteSameValue(L->next, x);
    }
}

/*
 * 在带头结点的单链表L中,删除所有值为x的结点,并释放空间,
 * 假设值为x的结点不唯一,设计算法实现上述操作.
 */
void deleteSameValue2(LinkList &L, ElemType x) {
    LNode *pre = L, *q, *p = L->next;
    while (p != NULL) {
        if (p->data == x) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
}

void deleteSameValue3(LinkList &L, ElemType x) {
    LNode *p = L->next, *r = L, *q;
    while (p != NULL) {
        if (p->data != x) {
            r->next = p;
            r = p;
            p = p->next;
        } else {
            q = p;
            p = p->next;
            free(q);
        }
    }
    r->next = NULL;
}

/*
 * 设L为带头结点的单链表,编写算法实现从尾到头反向输出每个节点的值.
 */
void printReverse(LinkList L) {
    if (L->next != NULL) {
        printReverse(L->next);
    }
    print(L->data);
}

/*
 * 试编写在带头结点的单链表L中删除一个最小值结点的高效算法(假设最小值结点是唯一的)
 */
LinkList deleteMin(LinkList &L) {
    LNode *pre = L, *p = L->next;
    LNode *minp = pre, *min = p;
    while (p != NULL) {
        if (p->data < min->data) {
            minp = pre;
            min = p;
        } else {
            pre = p;
            p = p->next;
        }
    }
    minp->next = min->next;
    free(min);
    return L;
}

/*
 * 试编写算法将带头结点的单链表就地逆置,即辅助空间复杂度为O(1).
 */
LinkList reverseLinkList1(LinkList L) {
    LNode *p, *r;
    p = L->next;
    L->next = NULL;
    while (p != NULL) {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return L
}

LinkList reverseLinkList(LinkList L) {
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL;
    while (r != NULL) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
    return L;
}

/*
 * 有一个带头结点的单链表L,设计一个算法使其元素递增有序.
 */
LinkList sort(LinkList L) {
    LNode *p = L->next, *pre;
    LNode *r = p->next;
    p->next = NULL;
    p = r;
    while (p != NULL) {
        r = p->next;
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data) {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}

/*
 * 设在一个带头节点的单链表中所有元素结点的数据值无序,编写一个函数,
 * 删除表中所有介于给定的两个值(参数形式给出)之间的元素.
 */
void deleteBetween(LinkList &L, ElemType min, ElemType max) {
    LNode *pre = L, *p = L->next, *q;
    while (p != NULL) {
        if (p->data > min && p - data < max) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
}

/*
 * 给定两个单链表,编写算法找出两个链表的公共结点.
 */
int getLength(LinkList L) {
    int n = 0;
    while (L->next != NULL) {
        ++n;
    }
    return n;
}

LNode findSameNode(LinkList L1, LinkList L2) {
    int length1 = getLength(L1);
    int length2 = getLength(L2);
    int dist;
    LinkList longList, shortList;
    if (length1 > length2) {
        longList = L1->next;
        shortList = L2->next;
        dist = length1 - length2;
    } else if (length2 > length1) {
        longList = L2->next;
        shortList = L1->next;
        dist = length2 - length1;
    }
    while (--dist) {
        longList = longList->next;
    }
    while (longList != NULL) {
        if (longList == shortList) {
            return longList;
        } else {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;
}

/*
 * 给定一个带头结点的单链表,设head为头指针,节点结构为(data,next),
 * data为整型元素,next为指针,写出算法:按递增次序输出单链表中各结点的数据元素,
 * 并释放节点所占的存储空间(不允许使用数组作为辅助空间).
 */
void printInAscending(LinkList &head) {
    LNode *pre, *p;
    LNode *minpre, min;
    while (head->next != NULL) {
        pre = head;
        p = head->next;
        minpre = pre;
        min = p;
        while (p != NULL) {
            if (p->data < min->data) {
                minpre = pre;
                min = p;
            }
            pre = p;
            p = p->next;
        }
        print(min->data);
        minpre->next = min->next;
        free(min);
    }
    free(head);
}

/*
 * 将一个带头结点的单链表A分解为两个带头结点的单链表A和B,使得A中含有原表
 * 中序号为奇数的元素,而B中含有原表中序号为偶数的元素,且保持其相对顺序不变,
 * 假设序号从0开始,结果返回单链表B.
 */
LinkList divideLinkList(LinkList &A) {
    B = (LinkList *) malloc(sizeof(LNode));
    B->next = NULL;
    LNode *ra = A, *rb = B;
    LNode *p = A->next;
    A->next = NULL;
    int n = 0;
    while (p != NULL) {
        if (n % 2 == 0) {
            rb->next = p;
            rb = p;
        } else {
            ra->next = p;
            ra = p;
        }
        p = p->next;
        ++n;
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}

LinkList divideLinkList(LinkList &A) {
    B = (LinkList *) malloc(sizeof(LNode));
    B->next = NULL;
    LNode *ra = A, *rb = B;
    LNode *p = A->next;
    A->next = NULL;
    int n = 0;
    while (p != NULL) {
        ra->next = p;
        ra = p;
        p = p->next;
        if (p != NULL) {
            rb->next = p;
            rb = p;
            p = p->next;
        }
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}