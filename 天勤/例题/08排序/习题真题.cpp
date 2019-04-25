//
// Created by roguelxx on 19-4-24.
//

#include "../02线性表/结构体定义.h"
#include "malloc.h"

/*
 * 设计一个算法,使得在尽可能少的时间内重排数组,
 * 将所有取负值的关键字放在所有取非负值的关键字之前,
 * 假设关键字存储在arr[0,...,n-1]中.
 */
void reSort(int arr[], int n) {
    int i = 0, j = n - 1, temp;
    while (i < j) {
        while (i < j && arr[j] < 0) {
            --j;
        }
        while (i < j && arr[i] > 0) {
            ++i;
        }
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            --j;
            ++i;
        }
    }
}

/*
 * 设向量A[0,...,n-1]中存有n个互不相同的整数,每个关键字的值均在0~n-1.
 * 试写一算法将向量A排序,结果输出到另一个向量B[0,...,n-1]中.
 */
void sort(int A[], int B[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        B[A[i]] = A[i];
    }
}

/*
 * 计数排序:这种算法对一个待排序表(A[])进行排序,排序结果存储在另一个新的表中(B[]),
 * 表中关键字为int类型.假设表中所有待排序的关键字互不相同,计数排毒算法对表中的每个关键字,
 * 扫描待排序表一遍,统计表中有多少个关键字比该关键字小.
 */
void countSort(int A[], int n, int B[]) {
    int i, sum, j;
    for (i = 0; i < n; ++i) {
        sum = 0;
        for (j = 0; j < n; ++j) {
            if (A[j] < A[i]) {
                ++sum;
            }
        }
        B[sum] = A[i];
    }
}

/*
 * 设计一个双向冒泡排序算法,在排序过程中交替改变扫描方向.
 */
void doubleBubble(int arr[], int n) {
    int i, j, l = 0, r = n - 1, temp, flag = true;
    while (flag) {
        flag = false;
        for (i = l; i < r; ++i) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = true;
            }
        }
        --r;
        for (j = r; j > l; --j) {
            if (arr[j] < arr[j - 1]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                flag = true;
            }
        }
        ++l;
    }
}

/*
 * 给定一组关键字,创建一个带头结点的链表,设计一个直接插入排序算法,对单链表进行非递减排序.
 */
void createLinkedList(LNode *&h, int arr[], int n) {
    LNode *p, *q;
    int i;
    h = (LNode *) malloc(sizeof(LNode));
    h->next = NULL;
    q = h;
    for (i = 0; i < n; ++i) {
        p = (LNode *) malloc(sizeof(LNode));
        p->data = arr[i];
        p->next = NULL;
        q->next = p;
        q = q->next;
    }
}

void linkedListInsertSort(LNode *A) {
    if (A->next != NULL) {
        LNode *p, *pl, *pre, *q;
        p = A->next->next;
        A->next->next = NULL;
        while (p != NULL) {
            pre = A;
            q = pre->next;
            while (q != NULL && q->data < p->data) {
                pre = q;
                q = q->next;
            }
            pl = p->next;
            p->next = pre->next;
            pre->next = p;
            p = pl;
        }
    }
}
