#include <stdio.h>
#define MAX_SIZE 6

typedef struct Node{
    float x, w, v;
}Node;

void merge(Node arr[], int leftArr, int mid, int rightArr)
{
     int i, j, k;
    int n1 = mid - leftArr + 1;
    int n2 = rightArr - mid;
 
    // Create temp arrays
    Node L[n1], R[n2];
 
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
        if (L[i].v/L[i].w >= R[j].v/R[j].w) {
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
void mergeSort(Node arr[], int leftArr, int rightArr)
{
    if (leftArr < rightArr){
        int mid = (leftArr + rightArr) / 2;
        mergeSort(arr, leftArr, mid);
        mergeSort(arr, mid+1, rightArr);
        merge(arr, leftArr, mid, rightArr);
    }
}

Node *FactionalKnapsack(Node A[], int arrSize, int W)
{
    mergeSort(A, 0, arrSize-1);

    int sumW = 0;
    for (int i=0; i <= arrSize && sumW < W; i++)
    {
        if (sumW + A[i].w <= W)
            A[i].x = 1;
        else
            A[i].x = (W - sumW) / A[i].w;
        sumW += A[i].x * A[i].w;
    }
    return A;
}

int main(void)
{
    Node A[] = {
        {0, 1, 5},
        {0, 2, 4},
        {0, 4, 8},
        {0, 5, 6}
    };

    Node *ptr = FactionalKnapsack(A, 4, MAX_SIZE);
    for (int i=0; i<4; i++)
        printf("w = %.0f v = %.0f select = %.2f\n", (ptr + i)->w, (ptr + i)->v, (ptr + i)->x);

    return 0;
}