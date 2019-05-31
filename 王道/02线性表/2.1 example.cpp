//
// Created by roguelxx on 19-5-30.
//

/*
 * 插入
 * 1<=i<=L.length+1,若i输入不合法,则返回false
 */
bool ListInsert(SqList &L, int i, ElemType elem) {
    if (L.length >= MaxSize) {
        return false;
    }
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    int j = L.length;
    while (j >= i) {
        L.data[j] = L.data[j - 1];
        --j;
    }
    L.data[i - 1] = elem;
    ++L.length;
    return true;
}

/*
 * 删除
 * 1<=i<=L.length,若成功则返回true,并将被删除的元素用引用变量e返回,否则返回false
 */
bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) {
        return false;
    }
    if (L.length == 0) {
        return false;
    }
    int j;
    e = L.data[i - 1];
    for (j = i; j < L.length; ++j) {
        L.data[j - 1] = L.data[j];
    }
    --L.length;
    return true;
}

/*
 * 按值查找(顺序查找)
 * 在顺序表L中找到第一个元素值等于e的元素,并返回其位序
 */
int LocateElem(SqList L, ElemType e) {
    int i;
    for (i = 0; i < L.length; ++i) {
        if (L.data[i] == e) {
            return i;
        }
    }
    return 0;
}
