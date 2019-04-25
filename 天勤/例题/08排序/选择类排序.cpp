//
// Created by roguelxx on 19-4-23.
//

/*
 * 简单选择排序
 */
void selectionSort(int arr[], int n) {
    int i, j, temp, k;
    for (i = 0; i < n; ++i) {
        k = i;
        for (j = i + 1; j < n; ++j) {
            if (arr[j] < arr[k]) {
                k = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

/*
 * 堆排序
 */
void sift(int arr[], int low, int high) {
    int i = low, j = 2 * i, temp = arr[i];
    while (j <= high) {
        if (j < high && arr[j] < arr[j + 1]) {
            ++j;
        }
        if (temp < arr[j]) {
            arr[i] = arr[j];
            i=j;
            j = 2 * i;
        } else {
            break;
        }
    }
    arr[i] = temp;
}

void heapSort(int arr[], int n) {
    int i, temp;
    for (i = n / 2; i >= 1; --i) {
        sift(arr, i, n);
    }
    for (i = n; i >= 2; --i) {
        temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        sift(arr, 1, i - 1);
    }
};
