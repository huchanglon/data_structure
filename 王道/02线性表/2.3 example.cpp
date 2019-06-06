//
// Created by roguelxx on 19-6-5.
//

LinkList headInsert(LinkList &L) {
    LNode *s;
    int x;
    L = (LinkList *) malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 99) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data=x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

LinkList tailInsert(LinkList &L) {
    int x;
    L = (LinkList *)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 99) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next=s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

LNode *GetElem(LinkList L, int i) {
    int j = 1;
    LNode *p = L->next;
    if (i == 0) {
        return L;
    }
    if (i < 1) {
        return NULL;
    }
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    return p;
}

LNode *LocateElem(LinkList L, ElemType elemType) {
    LNode *p = L->next;
    while (p != NULL) {
        if (p->data == elemType) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}



