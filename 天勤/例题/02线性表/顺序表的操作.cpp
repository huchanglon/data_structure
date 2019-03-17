//
// Created by roguelxx on 19-3-15.
//

#include "结构体定义.h"

/*
 * 查找元素值
 */
int findElem(Sqlist &L, int elem){
    int i;
    for (i = 0; i < L.length; ++i) {
        if (elem == L.data[i]) {
            return i;
        }
    }
    return -1;
}

/*
 * 插入元素值
 */
int insertElem(Sqlist &L, int index, int elem) {
    if (index < 0 || index > L.length) {
        return 0;
    }
    int i;
    for (i = L.length - 1; i >= index; --i) {
        L.data[i + 1] = L.data[i];
    }
    L.data[index] = elem;
    ++(L.length);
    return 1;
}

/*
 * 删除顺序表L中下标为p的元素，成功返回1，否则返回0，并将删除元素的值赋给 elem
 */
int deleteElem(Sqlist &L, int index, int &elem){
    if (index < 0 || index > L.length) {
        return 0;
    }
    int i;
    elem = L.data[index];
    for (i = index; i < L.length; ++i) {
        L.data[i] = L.data[i + 1];
    }
    --(L.length);
    return 1;
}
