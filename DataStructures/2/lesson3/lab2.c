#include <stdio.h>
#include "./sort.h"

int binarySearch(int arr[], int min, int max, int key)
{
    if (max < min)
        return -1;
    else{
        int mid = (min + max) / 2;
        if (key > arr[mid])
            return binarySearch(arr, mid + 1, max, key);
        else if (key < arr[mid])
            return binarySearch(arr, min, mid - 1, key);
        else
            return mid;
    }
}

int main(void)
{
    int n, arr[] = { 5, 2, 7, 9, 3, 2 };
    printf("Enter n: ");
    scanf("%d", &n);

    int size = sizeof(arr)/sizeof(int);
    mergeSort(arr, 0, size-1);
    printf((binarySearch(arr, 0, size-1, n) != -1) ? "Found" : "Not Found");

    return 0;
}