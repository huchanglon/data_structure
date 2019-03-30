//
// Created by roguelxx on 19-3-29.
//

#include <stdio.h>
#include <iostream>
#include "结构体定义.h"

using namespace std;

/*
 * 设数组A[0,1,...,n-1]的n个元素中有多个非零元素,
 * 设计一个算法,将A中所有的非零元素依次移动到A数组前端.
 */
void moveElement(int A[], int n) {
    int i = -1, j, temp;
    for (j = 0; j < n; ++j) {
        if (A[j] != 0) {
            A[++i] = A[j];
            A[j] = 0;
        }
    }
}

/*
 * 关于浮点型数组A[0,...,n-1],设计实现下列运算的递归算法.
 */
float findMax(float A[], int i,int j) {
    float max;
    if (i == j) {
        return A[i];
    } else {
        max = findMax(A, i + 1, j);
        if (A[i] > max) {
            return A[i];
        } else {
            return max;
        }
    }
}

float getSum(float A[], int i, int j) {
    if (i == j) {
        return A[i];
    } else {
        return A[i] + getSum(A, i + 1, j);
    }
};

float getAvg(float A[], int i, int j) {
    if (i == j) {
        return A[i];
    } else {
        return (A[i] + (j - i) * getAvg(A, i + 1, j)) / (j - i + 1);
    }
};

/*
 * 设计一个算法,将数组A[0,...,n-1]中所有奇数移到偶数之前.
 * 要求不另增加存储空间,且时间复杂度为O(n)
 */
void moveOddBeforeEven2(int A[], int n) {
    int i = 0, j = n - 1, temp;
    while (i < j) {
        while (A[i] % 2 == 1) {
            ++i;
        }
        while (A[j] % 2 == 0) {
            --j;
        }
        if (i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            ++i;
            --j;
        }
    }
}

void moveOddBeforeEven(int A[], int n) {
    int num = 0, i, temp;
    for (i = 0; i < n; ++i) {
        if (A[i] % 2 == 1) {
            temp = A[i];
            A[i] = A[i-num];
            A[i - num] = temp;
        } else {
            ++num;
        }
    }
}

/*
 * 设有一个元素为整数的线性表L,存放在一位数组A[0,...,n-1]中,
 * 设计一个算法,以A[n-1]为参考量,将该数组分为左右两个部分,
 * 其中左半部分的元素值小于等于A[n-1],右半部分大于A[n-1],
 * A[n-1]位于两部分中间.结果仍存放在数组A中.
 */

void divide(int A[], int n) {
    int temp, i = 0, j = n - 1;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    temp = A[i];
    while (i != j) {
        while (i < j && A[j] > temp) {
            --j;
        }
        if (i < j) {
            A[i] = A[j];
            ++i;
        }
        while (i < j && A[i] < temp) {
            ++i;
        }
        if (i < j) {
            A[j] = A[i];
            --j;
        }
    }
    A[i] = temp;
}

/*
 * 设计一个算法,对给定的一个整型m×n矩阵A,统计矩阵中具备下列特征的元素个数,
 * 并输出它们的坐标及数值:①既是所在行的最小值,又是所在列的最小值;
 * ②既是所在行中的最大值,又是所在列的最大值.假设矩阵中元素各不相同,要求结果打印在控制台.
 */

void findMinMatrix(int A[][4], int m, int n) {
    int i, j, mini, minj, k;
    bool flag;
    for (i = 0; i < m; ++i) {
        mini = A[i][0];
        minj = 0;
        for (j = 0; j < n; ++j) {
            if (A[i][j] < mini) {
                mini = A[i][j];
                minj = j;
            }
        }
        flag = true;
        for (k = 0; k < m; ++k) {
            if (A[k][minj] < mini) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << mini << ",[" << i << ", " << minj << "]" << " ";
        }
        cout << endl;
    }
}

void findMaxMatrix(int A[][4], int m, int n) {
    int i, j, maxi, maxj, k;
    bool flag;
    for (i = 0; i < m; ++i) {
        maxi = A[i][0];
        maxj = 0;
        for (j = 1; j < n; ++j) {
            if (A[i][j] > maxi) {
                maxi = A[i][j];
                maxj = j;
            }
        }
        flag = true;
        for (k = 0; k < m; ++k) {
            if (A[j][maxj] > maxi) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << maxi << ",[" << i << ", " << maxj << "]" << " ";
        }
        cout << endl;
    }
}

/*
 * 简要介绍稀疏矩阵的三元组存储结构特点,并实现稀疏矩阵的基本操作.
 * 1.给定稀疏矩阵A(int型),创建其三元组存储结构B
 * 2.查找给定元素x是否在矩阵中
 */

void createTrimat(int A[][4], int m, int n, int B[][3]) {
    int i, j, k = 1;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            if (A[i][j] != 0) {
                B[k][0] = A[i][j];
                B[k][1] = i;
                B[k][2] = j;
                ++k;
            }
        }
    }
    B[0][0] = k - 1;
    B[0][1] = m;
    B[0][2] = n;
}

int search(int B[][3], int x) {
    int k = B[0][0];
    int i;
    for (i = 1; i <= k; ++i) {
        if (B[i][0] == x) {
            return 1;
        }
    }
    return 0;
}

/*
 * 假设稀疏矩阵A采用三元组表示,编写一个函数,计算其转置矩阵B,
 * 要求B也采用三元组表示.
 */
void reverseTrimat(int A[][3], int B[][3]) {
    int p, q, col;
    B[0][0] = A[0][0];
    B[0][1] = A[0][1];
    B[0][2] = A[0][2];
    if (B[0][0] > 0) {
        q = 1;
        for (col = 0; col < B[0][1]; ++col) {
            for (p = 1; p <= B[0][0]; ++p) {
                if (A[p][2] == col) {
                    B[q][0] = A[p][0];
                    B[q][1] = A[p][2];
                    B[q][2] = A[p][1];
                    ++q;
                }
            }
        }
    }
}

/*
 * 假设稀疏矩阵A和B(两矩阵行列数对应相等)都采用三元组表示,
 * 编写一个函数,计算C=A+B,要求C也采用三元组表示,所有矩阵均为int型
 */
void addTrimat(int A[][3], int B[][3], int C[][3]) {
    int i = 1, j = 1, k = 1;
    while (i <= A[0][0] && j <= B[0][0]) {
        if (A[i][1] == B[j][1]) {
            if (A[i][2] < B[j][2]) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = A[i][2];
                ++k;
                ++i;
            } else if (A[i][2] < B[j][2]) {
                C[k][0] = B[j][0];
                C[k][1] = B[j][1];
                C[k][2] = B[j][2];
                ++k;
                ++j;
            } else if (A[i][2] == B[i][2]) {
                C[k][0] = A[i][0] + B[j][0];
                C[k][1] = B[j][1];
                C[k][2] = B[j][2];
                ++k;
                ++i;
                ++j;
            }
        } else if (A[i][1] < B[j][1]) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            ++k;
            ++i;
        } else if (A[i][1] > B[j][1]) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            ++k;
            ++j;
        }
    }
    while (i <= A[0][0]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        ++k;
        ++i;
    }
    while (j <= B[0][0]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        ++k;
        ++j;
    }
    C[0][0] = k - 1;
    C[0][1] = A[0][1] > B[0][1] ? A[0][1] : B[0][1];
    C[0][2] = A[0][2] > B[0][2] ? A[0][2] : B[0][2];
}

/*
 * 假设稀疏矩阵A和B(分别为m×n和n×k矩阵)采用三元组表示,
 * 表写一个函数,计算C=A×B,要求C也采用三元组表示的稀疏矩阵.
 */
int getValue(int D[][3], int i, int j) {
    int k = 1;
    while (k <= D[0][0] && D[k][1] == i && D[k][2] == j) {
        ++k;
    }
    if (k <= D[0][0]) {
        return D[k][0];
    } else {
        return 0;
    }
}

void multipleTrimat(int A[][3], int B[][3], int C[][3], int m, int n, int k) {
    int i, j, l, p = 1, s;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < k; ++j) {
            s=0;
            for (l = 0; l < n; ++l) {
                s += getValue(A, i, l) + getValue(B, l, j);
            }
            if (s != 0) {
                C[p][0] = s;
                C[p][1] = i;
                C[p][2] = j;
                ++p;
            }
        }
    }
    C[0][0] = p - 1;
    C[0][1] = m;
    C[0][2] = k;
}

void testFindMaxMatrix() {
    int A[][4] = {{0, 0, 0, 1},
                  {0, 0, 3, 2},
                  {1, 0, 0, 0},
                  {0, 2, 0, 0}};
    findMinMatrix(A, 4, 4);
}


void testDivide() {
    int a[] = {0, 0, 1, 2, 3, 4, 7, 5, 10};
    int length = sizeof(a) / sizeof(float);
    divide(a, length);
    for (int i = 0; i < length; ++i) {
        printf("%d ", a[i]);
    }
}

void testMoveOdd() {
    int a[] = {0, 0, 1, 2, 3, 4, 7, 5, 3};
    int length = sizeof(a) / sizeof(float);
    moveOddBeforeEven2(a, length);
    for (int i = 0; i < length; ++i) {
        printf("%d", a[i]);
    }
}

void testExercise2() {
    float a[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(a) / sizeof(float);
    printf("最大值为:%f \n", findMax(a, 0, length - 1));
    printf("总和为:%f \n", getSum(a, 0, length - 1));
    printf("平均数为:%f \n", getAvg(a, 0, length - 1));
}

void testMoveElement() {
    int a[] = {0, 0, 1, 2, 3, -1, 0, 1, 2, 0};
    int length = sizeof(a) / sizeof(int);
    moveElement(a, length);
    for (int i = 0; i < length; ++i) {
        printf("%d", a[i]);
    }
}

int main() {
//    testMoveElement();
//    testExercise2();
//    testMoveOdd();
//    testDivide();
    testFindMaxMatrix();
}
