#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InsertionSort(int A[], int n)
{
    for (int i=1; i<=n-1; i++)
    {
        int j = i;
        while (j>0 && A[j]<A[j-1])
        {
            swap(&A[j], &A[j-1]);
            j--;
        }
    }
}

int main(void)
{
    int n, max_weight, weight=0, count = 0;
    scanf("%d %d", &n, &max_weight);
    int arr[n];
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    InsertionSort(arr, n);

    for (int i=0; i<n && weight+arr[i] <= max_weight; i++)
    {
        weight += arr[i];
        count++;
    }

    printf("%d",count);
    return 0;
}