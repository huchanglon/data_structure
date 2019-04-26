//
// Created by roguelxx on 19-4-25.
//

/*
 * 一、顺序查找法
 * 数组a[]中有n个整数,没有次序,数组从下标1开始存储,
 * 请写出查找任一元素k的算法,若查找成功,则返回元素在数组中的位置;
 * 若不成功,则返回0.计算其平均查找长度以及算法的时间复杂度.
 */
int sequenceSearch(int a[], int k, int n) {
    int i;
    for (i = 1; i <= n; ++i) {
        if (a[i] == k) {
            return i;
        }
    }
    return 0;
}

/*
 * 二、折半查找法
 */
int binarySearch1(int a[], int k, int low, int high) {
    if (low >= high) {
        return 0;
    }
    if (low < high) {
        int mid = (low + high) / 2;
        if (a[mid] == k) {
            return mid;
        } else if (a[mid] > k) {
            return binarySearch(a, k, low, mid - 1);
        } else if (a[mid] < k) {
            return binarySearch(a, k, mid + 1, high);
        }
    }
}

int binarySearch2(int a[], int k, int low, int high) {
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == k) {
            return mid;
        } else if (k < a[mid]) {
            high = mid - 1;
        } else if (k > a[mid]) {
            low = mid + 1;
        }
    }
    return 0;
}

/*
 * 三、分块查找
 */
typedef struct {
    int key;
    int low, high;
} indexItem;                    // 索引项结构体
indexItem index[maxSize];       // 索引表
