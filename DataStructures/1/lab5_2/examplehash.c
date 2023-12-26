#include <stdio.h>
#define MAX 13

int arr[MAX];

int hash(int key)
{
    return key%MAX;
}

void insert(int value)
{
    int hashkey = hash(value);
    for (int i=0; i<MAX; i++)
    {
        int index = (hashkey + i)%MAX;
        if (arr[index] == -1){
            arr[index] = value;
            return ;
        }
    }
}

void find(int value)
{
    int hashkey = hash(value), count = 0, index;
    for (int i=0; i<MAX; i++)
    {
        index = (hashkey + i)%MAX;
        if (arr[index] == value){
            printf("find %d => %d\n", value, index);
            return ;
        }
        count++;
    }
    printf("\tfind %d => not found! %d\n", value,count);
    printf("\tlast index : %d index : %d\n", index, hashkey);
    return;
}

void delete(int value)
{
    int hashkey = hash(value);
    for (int i=0; i<MAX; i++)
    {
        int index = (hashkey + i)%MAX;
        if (arr[index] == value){
            arr[index] = 0;
            return ;
        }
    }
}

void printArr()
{
    for (int i=0; i<MAX; i++)
    {
        printf("arr[%d] : %d\n", i, arr[i]);
    }
}

int main(void)
{
    for (int i=0; i<MAX; i++)
        arr[i] = -1;

    
    insert(18);
    insert(26);
    insert(35);
    insert(9);
    find(15);
    find(48);
    delete(35);
    delete(40);
    find(9);
    insert(64);
    insert(47);
    find(35);
    printf("=====================\n");
    printArr();
    return 0;
}