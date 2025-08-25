#include "merge.h"

void mergeHelper(int *arr1, int *arr2, int *retArr, int n) {
    int size1 = n / 2;
    int size2 = n / 2 + n % 2;

    int i = 0;
    int j = 0;
    int k = 0;
    while (j < size1 && k < size2) {
        if (arr1[j] <= arr2[k]) {
            retArr[i] = arr1[j++];
        } else {
            retArr[i] = arr2[k++];
        }
        i++;
    }
    while (j < size1) {
        retArr[i++] = arr1[j++];
    }
    while (k < size2) {
        retArr[i++] = arr2[k++];
    }
}

int *mergeSort(int *arr, int n) {

    int *sortedArr = (int *)malloc(sizeof(int) * n);
    if (n == 1) {
        sortedArr[0] = arr[0];
        return sortedArr;
    }
    int *sortedFirst = mergeSort(arr, n / 2);
    int *sortedSecond = mergeSort(&arr[n / 2], (n / 2 + n % 2));
    mergeHelper(sortedFirst, sortedSecond, sortedArr, n);
    free(sortedFirst);
    free(sortedSecond);
    return sortedArr;
}
