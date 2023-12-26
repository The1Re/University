#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX 10
int numCompare=0,numSwap=0;

// Display all element in array
void DisplayArray(int A[], int n)
{
    int i;

    for (i=0; i< n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int A[], int n)
{
    for (int i=0; i<=n-2; i++)
    {
        int min = i;
        for (int j=i+1; j<=n-1; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        swap(&A[i], &A[min]);
    }
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

void BubbleSort(int A[], int n)
{   
    bool flag = true;
    for (int i=0; i<=n-1 && flag;i++)
    {
        flag = false;
        for (int j=n-1; j>=i+1; j--)
        {
            if (A[j]<A[j-1]){
                swap(&A[j], &A[j-1]);
                flag = true;
            }
        }
    }
}


int main()
{
    int A[MAX];
    int i;

    srand((unsigned) time(NULL));
    for (i=0; i< MAX; i++)
      A[i] = rand()%30 +1;

    DisplayArray(A, MAX);
    //SelectionSort(A, MAX);              //Call Sorting Function
    //InsertionSort(A, MAX);
    BubbleSort(A, MAX);
    DisplayArray(A, MAX);
    //printf("Numcompare = %d\tNumswap = %d\n",numCompare,numSwap);
    return 0;
}