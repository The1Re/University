#include <stdio.h>
#define SIZE 5

int H[SIZE], current_index = -1, total = 0;

int merge();
void swap(int *, int *);
void insertHeap(int);
void heapify(int, int);
int leftChild(int);
int rightChild(int);
int removeHeap();

int main()
{
    int data[] = { 5, 10, 20, 30, 30 };
    
    for (int i=0; i<SIZE; i++)
        insertHeap(data[i]);

    int arr = merge();
    printf("total = %d\n", total);
    return 0;
}

int merge()
{
    while (current_index > 0)
    {
        int sum = removeHeap() + removeHeap();
        total += sum;
        insertHeap(sum);
    }
    return H[current_index];
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertHeap(int newVal)
{
    int index = ++current_index;
    H[index] = newVal;
    while (index > 0)
    {
        int parent = (index-1)/2;
        if (H[index] < H[parent])
        {
            swap(&H[index], &H[parent]);
            index = parent;
        }else
            break;
    }
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
int leftChild(int k)
{
    return 2*k + 1;
}
int rightChild(int k)
{
    return 2*k + 2;
}
int removeHeap()
{
    int index = 0;
    int temp = H[index];
    H[index] = H[current_index];
    heapify(index, current_index+1);
    current_index--;

    return temp;
}