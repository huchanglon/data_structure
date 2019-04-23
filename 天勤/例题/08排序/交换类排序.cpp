//
// Created by roguelxx on 19-4-23.
//

/*
 * 冒泡排序
 */
void bubbleSort(int arr[], int n) {
    int i, j, temp, flag;
    for (i = n - 1; i >= 1; --i) {
        flag = 0;
        for (j = 1; j < n; ++j) {
            if (arr[j] < arr[j - 1]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            return;
        }
    }
}

/*
 * 快速排序
 */
void quickSort(int arr[], int n, int low, int high) {
    int i = low, j = high, temp;
    if (low < high) {
        temp = arr[low];
        while (i < j) {
            while (j > i && arr[j] > temp) {
                --j;
            }
            if (j > i) {
                arr[i] = arr[j];
                ++i;
            }
            while (j > i && arr[i] < temp) {
                ++i;
            }
            if (j > i) {
                arr[j] = arr[i];
                --j;
            }
        }
        arr[i] = temp;
        quickSort(arr, n, low, i - 1);
        quickSort(arr, n, i + 1, high);
    }
}
