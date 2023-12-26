#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomInteger(int start, int end)
{
    return (rand() % end) + start;
}
void printArr(int arr[], int size)
{
    for (int i=0; i<size; i++)
        printf("%d\n", arr[i]);
}
void merge(int arr[], int leftArr, int mid, int rightArr)
{
     int i, j, k;
    int n1 = mid - leftArr + 1;
    int n2 = rightArr - mid;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[leftArr + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
 
    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = leftArr;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int leftArr, int rightArr)
{
    if (leftArr < rightArr){
        int mid = (leftArr + rightArr) / 2;
        mergeSort(arr, leftArr, mid);
        mergeSort(arr, mid+1, rightArr);
        merge(arr, leftArr, mid, rightArr);
    }
}

int main()
{
    int n;
    srand((unsigned)time(0));
    printf("Enter n : ");
    scanf("%d", &n);
    
    int arr[n];
    for (int i=0; i<n; i++)
        arr[i] = randomInteger(1, 100);
    
    printArr(arr, n);
    mergeSort(arr, 0, n-1);
    printf("==== %d ====\n", arr[0]);
    return 0;
}