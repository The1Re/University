#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define SIZE 20

int H[SIZE], current_index=-1;
bool isMinHeap = true;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int newval)
{
    int index = ++current_index;
    H[index] = newval;
    if (index > 0){
        int parent = (index-1)/2;
        if (H[index] < H[parent])
            isMinHeap = false;
    }
}

int leftChild(int k)
{
    return 2*k+1;
}
int rightChild(int k)
{
    return 2*k+2;
}

void heapify(int index, int n)
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

void Heap_BottomUp(int n)
{
    int index = (current_index-1) / 2; //last parent
    while (index >= 0)
    {
        heapify(index, n);
        index--;
    }
}

void showHeap(int n)
{
    int index = 0;
    for (int level=1; level<=floor(log2(n)) + 1; level++)
    {
        for (int col=1; col<=pow(2,level-1) && index < n; col++)
            printf("%d ", H[index++]);
        printf("\n");
    }
}

int main(void)
{
    int n, num;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &num);
        insert(num);
    }
    if (isMinHeap){
        printf("a Min-Heap\n");
    }else{
        printf("Not a Min-Heap\n");
        Heap_BottomUp(n);
        showHeap(n);
    }
    
    return 0;
}