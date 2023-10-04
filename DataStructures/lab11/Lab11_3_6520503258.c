#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 26
#define HEAPSIZE 20

typedef struct node{
    char data;
    int frequency;
}Map;

Map H[HEAPSIZE];
int current_index=-1;
int hash[HASHSIZE] = {0};

int hashKey(char c)
{
    return c - 'a';
}

void frequency(char input[])
{
    for (int i=0; i<strlen(input); i++)
    {
        hash[hashKey(input[i])]++;
    }
}

void swap(Map *a, Map *b)
{
    Map temp = *a;
    *a = *b;
    *b = temp;
}

void insertHeap(char key, int value)
{
    int index = ++current_index;
    H[index].data = key;
    H[index].frequency = value;
    while (index > 0)
    {
        int parent = (index-1)/2;
        if (H[index].frequency > H[parent].frequency){
            swap(&H[index], &H[parent]);
            index = parent;
        }else
            break;
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
        if (H[index].frequency >= H[leftChild(index)].frequency && (rightChild(index) >= n || H[index].frequency >= H[rightChild(index)].frequency))
            return;
        if (H[leftChild(index)].frequency > H[rightChild(index)].frequency || rightChild(index) >= n){
            swap(&H[index], &H[leftChild(index)]);
            index = leftChild(index);
        }else{
            swap(&H[index], &H[rightChild(index)]);
            index = rightChild(index);
        }
    }
}

Map *removeHeap()
{
    int index = 0;
    Map *temp = malloc(sizeof(Map));
    temp->data = H[index].data;
    temp->frequency = H[index].frequency;

    H[index] = H[current_index];
    heapify(index, current_index+1);
    current_index--;

    return temp;
}

int main(void)
{
    char input[50];
    scanf("%s", input);
    frequency(input);
    //insert
    for (int i=0; i<26; i++)
    {
        if (hash[i] != 0)
            insertHeap(i+'a', hash[i]);
    }

    //show
    while (current_index != -1)
    {
        Map *temp = removeHeap();
        for(int j=0; j<temp->frequency; j++)
            printf("%c", temp->data);
    }

    return 0;
}