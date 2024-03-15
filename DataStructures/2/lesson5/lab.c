#include <stdio.h>
#include "../lesson3/sort.h"
#define length(arr) sizeof(arr)/sizeof(*arr)

int main()
{
    int data[] = { 5, 10, 20, 30, 30 }, last_index = length(data) - 1, index = 0, cost = 0;
    
    while (index < last_index)
    {
        mergeSort(data, index, last_index);
        int sum = data[index] + data[index + 1];
        data[index + 1] = sum;
        cost += sum;

        index++;
    }
    printf("cost = %d\n", cost);

    return 0;
}


