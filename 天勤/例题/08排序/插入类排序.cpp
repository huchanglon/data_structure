//
// Created by roguelxx on 19-4-23.
//

#include "stdio.h"

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*
 * 直接插入排序
 */
void insertSort(int arr[], int n) {
    int i, j, temp;
    for (i = 1; i < n; ++i) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
    }
}

/*
 * 折半插入排序
 */
int binarySearch(int arr[], int item, int low, int high) {
    if (high <= low) {
        return item > arr[low] ? low + 1 : low;
    }
    int mid = (low + high) / 2;
    if (item == arr[mid]) {
        return mid + 1;
    } else if (item > arr[mid]) {
        return binarySearch(arr, item, mid + 1, high);
    } else if (item < arr[mid]) {
        return binarySearch(arr, item, low, mid - 1);
    }
}

void binarySort(int arr[], int n) {
    int i, j, idx, temp;
    for (i = 1; i < n; ++i) {
        temp = arr[i];
        j = i - 1;
        idx = binarySearch(arr, temp, 0, n);
        while (j >= idx) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
    }
}

/*
 * 希尔排序
 */
void shellSort(int arr[], int n) {
    int i, j, gap, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; ++i) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
