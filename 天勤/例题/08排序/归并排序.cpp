//
// Created by roguelxx on 19-4-23.
//

/*
 * 二路归并排序
 */
void merge(int arr[], int l, int r, int mid) {
    int i, j, k;
    int l1 = mid - l + 1;
    int l2 = r - mid;
    int L[l1], R[l2];
    for (i = 0; i < l1; ++i) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < l2; ++j) {
        R[i] = arr[mid + 1 + j];
    }
    i = 0, j = 0, k = l;
    while (i < l1 && j < l2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < l1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < l2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
};

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}

