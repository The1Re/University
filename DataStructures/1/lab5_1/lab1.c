#include<stdio.h>
#include<stdlib.h>
#define Size 7

struct node
{
    int data;
    struct node *next;
};
struct node *hash_table[Size];   //array of pointer

void insertChain(int value)
{
    struct node *new_node;
    new_node= (struct node*) malloc(sizeof(struct node));
    //assign value to the new_node
    new_node->data = value;
    new_node->next = hash_table[value%Size];
    hash_table[value%Size] = new_node;

}

void printChain()
{
    for (int i=0; i<Size; i++)
    {
        printf("Chain[%d]", i);
        struct node *ptr = hash_table[i];
        while(ptr != NULL)
        {
            printf("-->%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("-->NULL\n");
    }
}

int search_item(int x)
{
    int count = 1;
    struct node *ptr = hash_table[x%Size];
    while (ptr != NULL)
    {
        if (ptr->data == x)
            return count;
        count++;
        ptr = ptr->next;
    }
    return -1;
}

int main()
{
    int i;

    for(i=0;i<Size;i++)     //initialize a chained hash table
        hash_table[i]=NULL;

    insertChain(15);
    insertChain(22);
    insertChain(95);
    insertChain(56);
    insertChain(12);
    insertChain(27);
    insertChain(63);
    printChain();

    printf("%d\n", search_item(15));
    printf("%d\n", search_item(50));


    return 0;
}
