#include <stdio.h>
#include <math.h>

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
    int n, mid;
    float result;
    scanf("%d",&n);

    int arr[n];
    for (int i=0; i<n; i++)
        scanf("%d",&arr[i]);

    InsertionSort(arr, n);
    for (int i=0; i<n; i++)
        printf("%d ",arr[i]);

    mid = n/2;
    if (n%2 == 0)
        result = (arr[mid]+arr[mid-1]) / 2.0;
    else
        result = arr[mid];
        
    printf("\nMedian = %.1f\n", result);
    return 0;
}