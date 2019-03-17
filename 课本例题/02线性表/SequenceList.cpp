//
// Created by roguelxx on 19-3-15.
//
#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include <malloc.h>
#include <cstdlib>
#include "SequenceList.h"

// 算法2.3
Status InitList_Sq(SqList &L) {
    // 构造一个空的线性表L
    L.elem = (ElemType_Sq *) malloc(LIST_INIT_SIZE * sizeof(ElemType_Sq));
    if (!L.elem) {
        exit(OVERFLOW);
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

// 算法2.4
Status ListInsert_Sq(SqList &L, int i, ElemType_Sq e) {

    ElemType_Sq *newbase;
    ElemType_Sq *p, *q;

    if (i < 1 || i > L.length + 1) {
        return ERROR;
    }
    if (L.length >= L.listsize) {
        newbase = (ElemType_Sq *) realloc(L.elem, (L.listsize + LIST_INCEMENT) * sizeof(ElemType_Sq));
    }
    if (!newbase) {
        exit(OVERFLOW);
    }
    L.listsize += LIST_INCEMENT;
    q = &(L.elem[i - 1]);
    for (p = &(L.elem[L.length - 1]); p >= q; --p) {
        *(p + 1) = *p;
    }
    *q = e;
    ++L.length;
    return OK;
}
#endif


