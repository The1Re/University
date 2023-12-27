#include <stdio.h>

typedef struct Activity{
    int id, s, f;
}Activity;

void merge(Activity arr[], int leftArr, int mid, int rightArr)
{
     int i, j, k;
    int n1 = mid - leftArr + 1;
    int n2 = rightArr - mid;
 
    // Create temp arrays
    Activity L[n1], R[n2];
 
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
        if (L[i].f <= R[j].f) {
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
void mergeSort(Activity arr[], int leftArr, int rightArr)
{
    if (leftArr < rightArr){
        int mid = (leftArr + rightArr) / 2;
        mergeSort(arr, leftArr, mid);
        mergeSort(arr, mid+1, rightArr);
        merge(arr, leftArr, mid, rightArr);
    }
}

void ActivitySelection(Activity A[], int size)
{
    mergeSort(A, 0, size-1);

    int i = 0;
    printf("Activities are selected n : %d ", A[i].id);

    for (int j=1; j<size; j++)
    {
        if (A[j].s >= A[i].f){
            printf("%d ", A[j].id);
            i = j;
        }
    }
}

int main(void)
{
    int n;
    printf("Input number of Activity (n) = ");
    scanf("%d", &n);

    Activity A[n];
    for (int i=0; i<n; i++)
    {
        A[i].id = i+1;
        printf("Input Enter S and F of Activity %d = ", A[i].id);
        scanf("%d %d", &A[i].s, &A[i].f);
    }

    ActivitySelection(A, n);

    return 0;
}