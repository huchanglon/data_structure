//
// Created by roguelxx on 19-3-29.
//
#include <iostream>
#include "结构体定义.h"
#define maxSize 5

using namespace std;

/*
 * 给定一个稀疏矩阵A(float型),其尺寸为m×n,
 * 建立其对应的三元组B存储,通过三元组打印输出矩阵A
 */
void createTrimat(float A[][4], int m, int n, float B[][3]) {
    int k = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] != 0) {
                cout << A[i][j] << "-";
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

void print(float B[][3]) {
    int k = 1;
    for (int i = 0; i < B[0][1]; ++i) {
        for (int j = 0; j < B[0][2]; ++j) {
            if (i == (int) B[k][1] && j == (int) B[k][2]) {
                cout << B[k][0] << " ";
                ++k;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void testCreateAndPrint() {
    float A[][4] = {{0, 0, 0, 1},
                    {0, 0, 3, 2},
                    {1, 0, 0, 0},
                    {0, 2, 0, 0}};
    float B[][3] = {};
    createTrimat(A, 5, 4, B);
    print(B);
}

/*
 * 给定一个稀疏矩阵A,尺寸为m×n,非零元素个数为k,
 * 建立其对应的十字链表存储结构.
 */
int createCrossListMat(float A[][4], int m, int n, int k, CrossList &M) {
}

int main() {
}
