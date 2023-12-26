#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

int H[SIZE], current_index = -1;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int leftChild(int k)
{
    return 2*k+1;
}
int rightChild(int k)
{
    return 2*k+2;
}

void insertAscending(int newval)
{
    int index = ++current_index;
    H[index] = newval;
    while (index > 0)
    {
        int parent = (index-1)/2;
        if (H[index] > H[parent]){
            swap(&H[index], &H[parent]);
            index = parent;
        }else
            break;
    }
}

void insertDescending(int newval)
{
    int index = ++current_index;
    H[index] = newval;
    while (index > 0)
    {
        int parent = (index-1)/2;
        if (H[index] < H[parent]){
            swap(&H[index], &H[parent]);
            index = parent;
        }else
            break;
    }
}

void heapifyAscending(int index, int n)
{
    while (leftChild(index) < n)
    {
        if (H[index] >= H[leftChild(index)] && (rightChild(index) >= n || H[index] >= H[rightChild(index)]))
            return;
        if (H[leftChild(index)] > H[rightChild(index)] || rightChild(index) >= n){
            swap(&H[index], &H[leftChild(index)]);
            index = leftChild(index);
        }else{
            swap(&H[index], &H[rightChild(index)]);
            index = rightChild(index);
        }
    }
}
void heapifyDescending(int index, int n)
{
    while (leftChild(index) < n)
    {
        if (H[index] <= H[leftChild(index)] && (rightChild(index) >= n || H[index] <= H[rightChild(index)]))
            return;
        if (H[leftChild(index)] < H[rightChild(index)] || rightChild(index) >= n){
            swap(&H[index], &H[leftChild(index)]);
            index = leftChild(index);
        }else{
            swap(&H[index], &H[rightChild(index)]);
            index = rightChild(index);
        }
    }
}

int removeHeap(char choice)
{
    int index = 0;
    int temp = H[index];
    H[index] = H[current_index];
    if (choice == 'A')
        heapifyAscending(index, current_index+1);
    else
        heapifyDescending(index, current_index+1);
    current_index--;
    return temp;
}

int main()
{
    int i,n=20;
    char choice;
    srand((unsigned) time(NULL)); //Initializes random number generator
    int num[n];
    printf("Number before sorting\n");
    for(i=0;i<n;i++)
    {
        num[i]=rand()%100+1; //random number between 0-100
        printf("%d ",num[i]);;
    }

    printf("\nSorting (A)scending order");
    printf("\nSorting (D)escending order");
    printf("\nSelect choice : ");
    scanf("%c", &choice);
    printf("\nNumber after sorting: ");
    if (choice == 'A'){
        printf("Ascending order\n");
        for (int i=0; i<n; i++)
            insertAscending(num[i]);
    }else{
        printf("Descending order\n");
        for (int i=0; i<n; i++)
            insertDescending(num[i]);
    }

    //Display after Sorting
    for (int i=0; i<n; i++)
        printf("%d ", removeHeap(choice));

// Fill your code here for sorting number using Heap sort
}