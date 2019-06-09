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
LinkList divideLinkList1(LinkList &A) {
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

LinkList divideLinkList2(LinkList &A) {
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

/*
 * 设A={a1,b1,a2,b2,...,an,bn}为线性表,采用带头结点的A单链表存放,设计一个就地算法,
 * 将其拆分为两个线性表,使得A={a1,a2,...,an},B={bn,...,b2,b1}
 */
LinkList divideLinkList3(LinkList &A) {
    LinkList B = (LinkList *) malloc(sizeof(LinkList));
    B->next = NULL;
    LNode *r = A;
    LNode *p = A->next, *q;
    while (p != NULL) {
        r->next=p;
        r = p;
        p = p->next;
        q = p->next;
        p->next = B->next;
        B->next = p;
        p = q;
    }
    r->next = NULL;
    return B;
}

/*
 * 在一个递增有序的线性表中,有数值相同的元素存在.若存储方式为单链表,
 * 设计算法去掉数值相同的元素.
 */
void deleteDuplicate(LinkList &L) {
    LNode *p = L->next, *q;
    while (p != NULL) {
        if (p->data == p->next->data) {
            q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
}

/*
 * 假设有两个按元素值递增次序排列的线性表,均以单链表形式存储.编写一个算法,
 * 将这两个单链表归并为一个按元素值递减次序排列的单链表,并要求利用原来两个
 * 单链表的结点存放归并后的单链表.
 */
void mergeToDescend(LinkList &A, LinkList &B) {
    LNode *s1 = A->next, *q;
    LNode *s2 = B->next;
    A->next = NULL;
    while (s1 != NULL && s2 != NULL) {
        if (s1->data <= s2->data) {
            q = s1->next;
            s1->next = A->next;
            A->next = s1;
            s1 = q;
        } else {
            q = s2->next;
            s2->next = A->next;
            A->next = s2;
            s2 = q;
        }
    }
    if (s1 != NULL) {
        s2 = s1;
    }
    while (s2 != NULL) {
        q = s2->next;
        s2->next = A->next;
        A->next = s2;
        s2 = q;
    }
    free(B)
}

/*
 * 设A和B是两个单链表(带头结点),其中元素递增有序.设计一个算法从A和B中
 * 的公共元素产生单链表C,要求不破坏A、B的结点.
 */
LinkList sameValueList(LinkList A, LinkList B) {
    LinkList C = (LinkList *) malloc(sizeof(LNode));
    C->next = NULL;
    LNode *pa = A->next, *pb = B->next, *q, *rc = C;
    while (pa && pb) {
        if (pa->data == pb->data) {
            q = (LNode *) malloc(sizeof(LNode));
            q->data = pa->data;
            rc->next = q;
            rc = q;
            pb = pb->next;
            pa = pa->next;
        }
        if (pa->data > pb->data) {
            pb = pb->next;
        } else {
            pa = pa->next;
        }
    }
    rc - next = NULL;
    return C;
}

/*
 * 已知两个链表A和B分别表示两个集合,其元素递增有序.编写一个算法,求A和B的交集,
 * 并存放在A链表中,其余结点全部释放.
 */
void getIntersection(LinkList &A, LinkList B) {
    LNode *pa = A->next, *r = A, *pb = B->next, *q;
    A->next = NULL;
    while (pa && pb) {
        if (pa->data == pb->data) {
            q = pa->next;
            r->next = pa;
            r = pa;
            pb = pb->next;
            pa = q;
        }
        if (pa->data > pb->data) {
            q = pb->next;
            free(pb);
            pb = q;
        } else {
            q = pa->next;
            free(pa);
            pa = q;
        }
    }
    if (pa) {
        pb = pa;
    }
    while (pb) {
        q = pb->next;
        free(pb);
        pb = q;
    }
    r->next = NULL;
    free(B);
}

/*
 * 两个整数序列A=a1,a2,a3,...am和B=b1,b2,b3,...,bn已经存入两个单链表中,
 * 设计一个算法,判断序列B是否是序列A的连续子序列,假设AB带头结点
 */
bool isSubList(LinkList A, LinkList B) {
    LNode *pa = A->next, *pre, *pb = B->next;
    while (pa && pb) {
        if (pa->data == pb->data) {
            pre = pa;
            pa = pa->next;
            pb = pb->next;
        } else {
            pre = pre->next
            pa = pre;
            pb = B->next;
        }
    }
    if (pb == NULL) {
        return true;
    } else {
        return false;
    }
}

/*
 * 设计一个算法用于判断带头结点的循环双链表是否对称,奇数偶数个都存在对称性.
 */
bool isSymmetry(LinkList A) {
    LNode *s = A->next, *r = A->prior;
    while (s != r && r->next != s) {
        if (s->data != r->data) {
            return false;
        } else {
            s = s->next;
            r = r->prior;
        }
    }
    return true;
}

/*
 * 有两个循环单链表,链表头指针分别为h1和h2,编写一个算法将h2链接到h1之后,
 * 要求链接后的链表仍保持循环链表形式.
 */
void linkAfter(LinkList &h1, LinkList &h2) {
    LNode *p1 = h1, *p2 = h2;
    while (p1->next != h1) {
        p1 = p1->next;
    }
    p1->next = h2;
    while (p2->next != h2) {
        p2 = p2->next;
    }
    p2->next = h1;
}

/*
 * 设有一个带头结点的循环单链表,其结点值均为正整数.设计一个算法,反复找出单链表中结点值
 * 最小的结点并输出,然后将该结点从中删除,直到单链表空为止,再删除表头结点.
 */
void deleteByMin(LinkList &L) {
    LNode *p = L->next, *pre = L;
    LNode *min = p, *minpre = pre;
    while (L->next != NULL) {
        p = L->next;
        pre = L;
        min = p;
        minpre = pre;
        while (p != L) {
            if (p->data < min->data) {
                min = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        minpre->next = min->next;
        free(min);
    }
    free(L);
}

/*
 * 设头指针为L的带有头结点的非循环双向链表,其每个结点中添加一个属性,访问频度域freq.
 * 在链表被启用前,其值均初始化为零.每当在链表中进行一次Locate(L,x)运算,令元素值为x
 * 的结点中freq域的值增加1,并使此链表中结点保持按访问频度非增的顺序排列,同时最近访问
 * 的结点排在频度相同的结点前,以便使频繁访问的结点总是靠近表头.试写符合上述要求的Locate(L, x)
 * 运算的算法,该算法返回找到结点的地址,类型为指针型.
 */
LNode *Locate(LinkList &L, ElemType x) {
    LNode *p = L->next, *q;
    while (p != NULL && p->data != x) {
        p = p->next;
    };
    if (!p) {
        printf("不存在值为x的结点\n");
        exit(0);
    } else {
        ++p->freq;
        p->next->pred = p->pred;
        p->pred->next = p->next;
        q = p->pred;
        while (q != L && q->freq > p->freq) {
            q = q->freq;
        }
        p->next = q->next;
        q->next->pred = p;
        p->pred = q;
        q->next = p;
    }
    return q;
}

/*
 * 已知一个带头结点的单链表,结点结构为data,link.假设该链表只给了头指针list.在不改变链表的前提下,
 * 请设计一个算法,查找链表中倒数第k个位置上的结点(k为正整数).若查找成功,输出该结点的data,并返回1;
 * 否则,返回0.
 */
int locateReciprocal(LinkList list, int k) {
    if (k <= 0) {
        return 0;
    }
    LNode *p = list->link, *pre = list->link;
    int count = 0;
    while (p != NULL) {
        if (count < k) {
            ++count;
        } else {
            q = q->link;
        }
        p = p->link;
    }
    if (count < k) {
        return 0;
    } else {
        printf("%d", q->data);
        return 1;
    }
}

/*
 * 假定采用带头结点的单链表保存单词,当两个单词有相同的后缀时,可共享相同的后缀空间,
 * 例如,"loading"和"being".设str1和str2分别指向两个单词所在单链表的头结点,
 * 链表结构为data,next.设计一个高效算法,由str1和str2所指向两个链表共同后缀的起始位置.
 */
LNode *findCommon(LinkList str1, LinkList str2) {
    int l1 = getLength(str1);
    int l2 = getLength(str2);
    int diff;
    LNode *shortWord, *longWord, *p;
    if (l1 > l2) {
        shortWord = str2;
        longWord = str1;
        diff = l1 - l2;
    } else {
        shortWord = str1;
        longWord = str2;
        diff = l2 - l1;
    }
    while (diff > 0) {
        longWord = longWord->next;
        --diff;
    }
    while (longWord != NULL) {
        if (longWord == shortWord) {
            p = longWord;
            return p;
        } else {
            longWord = longWord->next;
            shortWord = shortWord->next;
        }
    }
    return NULL;
}

/*
 * 用单链表保存m个整数,结点的结构为data,link.且|data|<=n(n为正整数).设计一个时间复杂度
 * 尽可能高的算法,对于链表中data的绝对值相等的结点,仅保留第一次出现的结点,删除其余结点.
 */
typedef struct LNode {
    int data,
    struct LNode *link;
} LNode;
void delSameAbs(LNode *L, int n) {
    int *arr, i;
    arr = (int *) malloc(sizeof(int) * (n + 1));
    for (i = 0; i < n; ++i) {
        *(arr + i) = 0;
    }
    LNode *p = L, *q;
    while (p->link != NULL) {
        i = p->link->data > 0 ? p->link->data : -p->link->data;
        if (*(arr + i) == 1) {
            q = p->link;
            p->link = q->link;
            free(q);
        } else {
            *(arr + i) = 1;
            p = p->link;
        }
    }
    free(arr);
}