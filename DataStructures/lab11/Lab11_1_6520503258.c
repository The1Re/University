#include <stdio.h>
#include <math.h>
#define SIZE 10

int H[SIZE], current_index=-1;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertHeap(int newval)
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
        insertHeap(num);
    }
    showHeap(n);
    
    return 0;
}