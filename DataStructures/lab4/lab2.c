#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

int search_item(int x)
{
    struct node *ptr = head;
    int pos = 1;
    while (ptr != NULL)
    {
        if (ptr->data == x){
            return pos;
        }
        pos++;
        ptr = ptr->next;
    }
    return -1;
}

int main(void)
{
    int arr[] = {10,2,33,-3,65,67};
    int length = sizeof(arr)/sizeof(int);
    for (int i=0; i<length; i++)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = arr[length-i-1];
        new_node->next = head;
        head = new_node;
    }
    printf("%d\n", search_item(65));
    printf("%d\n", search_item(50));
    return 0;
}