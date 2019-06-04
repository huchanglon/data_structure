//
// Created by roguelxx on 19-5-31.
//

/*
 * 在顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值.
 * 空出的位置由最后一个元素填补,若顺序表为空则显示出错信息并退出运行.
 */
bool deleteMin(SqList &L, ElemTyle &value) {
    if (L.length == 0) {
        return false;
    }
    value = L.data[0];
    int i;
    int pos = 0;
    for (i = 1; i < L.length; ++i) {
        if (L.data[i] < value) {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    --L.length;
    return true;
}

/*
 * 设计一个高效算法,将顺序表L的所有元素逆置,要求算法的空间复杂度为O(1).
 */
void reverse(SqList &L) {
    ElemType temp;
    int i;
    int j;
    for (i = 0, j = L.length - 1; i < j; ++i, --j) {
        temp = L.data[j];
        L.data[j] = L.data[i];
        L.data[i] = temp;
    }
    /*
    for (i = 0; i < L.length / 2; ++i) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
    */
}

/*
 * 对长度为n的顺序表L,编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法,
 * 该算法删除线性表中所有值为x的数据元素.
 */
void deleteBySameValue1(SqList &L, int x) {
    int i, k = 0;
    while (i < L.length) {
        if (L.data[i] == x) {
            ++k;
        } else {
            L.data[i - k] = L.data[i];
        }
        ++i;
    }
    L.length -= k;
}

void deleteBySameValue2(SqList &L, int x) {
    int i, k = 0;
    for (i = 0; i < L.length; ++i) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            ++k;
        }
    }
    L.length = k;
}

/*
 * 从有序顺序表中删除其值在给定值s与t之间(要求s<t)的所有元素,
 * 若s或者t不合理或顺序表为空,则显示错误信息并退出运行.
 */
bool deleteValueBetween(SqList &L, int s, int t) {
    if (L.length == 0 || s >= t) {
        return false;
    }
    int i, k = 0, is, it;
    for (i = 0; i < L.length && L.data[i] < s; ++i) {
    }
    if (i >= L.length) {
        return false;
    }
    for (j = i; j < L.length && L.data[j] <= t; ++j) {
    }
    for (; j < L.length; ++i, ++j) {
        L.data[i] = L.data[j];
    }
    L.length = i;
    return true;
}

/*
 * 从顺序表中删除其值在给定值s与t之间(要求s<t, 包含s和t)的所有元素,
 * 若s或者t不合理或顺序表为空,则显示错误信息并退出运行.
 */
bool deleteValueBetween(SqList &L, int s, int t) {
    if (L.length == 0 || s >= t) {
        return false;
    }
    int i, k = 0;
    for (i = 0; i < L.length; ++i) {
        if (L.data[i] >= s && L.data[i] <= t) {
            ++k;
        } else {
            L.data[i - k] = L.data[i];
        }
    }
    L.length -= k;
    return true;
}

/*
 * 从有序顺序表中删除所有其值重复的元素,使表中所有元素的值均不同.
 */
bool deleteDuplicate(SqList &L) {
    if (L.length == 0) {
        return false;
    }
    int i, j;
    for (i = 0, j = 1; j < L.length; ++j) {
        if (L.data[i] != L.data[j]) {
            L.data[++i] = L.data[j];
        }
    }
    L.length = i + 1;
    return true;
}

/*
 * 将两个有序顺序表合并为一个新的有序顺序表,并由函数返回结果顺序表.
 */
bool mergeList(SqList L1, SqList L2, SqList &L) {
    if (L1.length+L2.length>L.maxSize) {
        return false;
    }
    int i = 0, j = 0, k = 0;
    while (i < L1.length && j < L2.length) {
        if (L1.data[i] <= L2.data[j]) {
            L.data[k++] = L1.data[i++];
        } else {
            L.data[k++] = L2.data[j++];
        }
    }
    while (i < L1.length) {
        L.data[k++] = L.data[i++];
    }
    while (j < L2.length) {
        L.data[k++] = L.data[j++];
    }
    L.length = k;
    return true;
}

/*
 * 已知在一位数组A[m+n]中依次存放两个线性表(a1,a2,a3,a4,...,am)和
 * (b1,b2,b3,...,bn).编写一个函数,将数组中两个顺序表的位置互换,
 * 即将(b1,b2,b3,...,bn)放在(a1,a2,a3,...,am)前面.
 */
void reverseArr(int arr[], int a, int b) {
    int temp;
    while (a < b) {
        temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
        ++a;
        --b;
    }
}

void exchangePosition(int A[], int m, int n) {
    reverseArr(A, 0, m-1);
    reverseArr(A, m, m + n - 1);
    reverseArr(A, 0, m + n - 1);
}

/*
 * 线性表(a1,a2,a3,...,an)中的元素递增有序且按顺序存储于计算机内.
 * 设计一算法,用最少时间在表中查找数值为x的元素,若找到则将其与后继元素交换位置,
 * 若找不到则将其插入表中并使表中元素仍递增有序.
 */
void insertInOrder(ElemType A[], ElemType x) {
    int l = 0, h = n - 1, m, t, i;
    while (l <= h) {
        m = (h + l) / 2;
        if (A[mid] == x) {
            break;
        } else if (A[mid] < x) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    if (A[mid] == x && mid != n - 1) {
        t = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = t;
    }
    if (l > h) {
        for (i = n - 1; i > h; --i) {
            A[i + 1] = A[i];
        }
        A[i + 1] = x;
    }
}

/*
 * 设将n(n>1)个整数存放到一位数组R中.设计一个在时间和空间两方面都高效的算法.
 * 将R中保存的序列循环左移p(0<p<n)个位置.
 * 空间复杂度:O(1), 时间复杂度:O(n)
 */
void reverseArray(ElemType elemType[], int l, int h) {
    ElemType temp;
    while (l < h) {
        temp = elemType[l];
        elemType[l] = elemType[h];
        elemType[h] = temp;
        ++l;
        --h;
    }
}
void leftShift(ElemType elemType[], int p) {
    reverseArray(elemType, 0, p - 1);
    reverseArray(elemType, p, n - 1);
    reverseArray(elemType, 0, n - 1);
}

/*
 * 一个长度为L(L>=1)的升序序列S,处在第L/2(向上取整)个位置的数称为S的中位数.
 * 现有两个等长升序序列A和B,设计一个高效算法,找出序列A和B的中位数.
 */
int findMedian(int A[], int B[], int n) {
    int s1 = 0, t1 = n - 1, s2 = 0, t2 = n - 1, m1, m2;
    while (s1 != t1 || s2 != t2) {
        m1 = (s1 + t1) / 2;
        m2 = (s2 + t2) / 2;
        if (A[m1] == B[m2]) {
            return A[m1];
        }
        if (A[m1] < B[m2]) {
            if ((s1 + d1) % 2 == 0) {
                s1=m1;
                d2=m2;
            } else {
                s1 = m1 + 1;
                d2 = m2;
            }
        }
        if (A[m1] > B[m2]) {
            if ((s2 + d2) % 2 == 0) {
                d1=m1;
                s2=m2;
            } else {
                d1=m2;
                s2=m2+1;
            }
        }
    }
    return A[s1] < B[s2] ? A[s1] : B[s2];
}
