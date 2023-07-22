#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *newNode(int v)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = v;
    new_node->next = NULL;
     
    return new_node;
}

void DisplayLL(node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

bool isCircular(node *h)
{
    node *ptr = h;
    while (ptr != NULL)
    {
        if (ptr->next == h)
            return true;
        ptr = ptr->next;
    }
    return false;
}

int main(void)
{
    node *head = NULL;
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    //head->next->next->next->next = head;

    DisplayLL(head);
    if (!isCircular(head))
    {
        node *ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = head;

        //after change
        if (isCircular(head))
            printf("Is circular");
        else
            printf("Not circular");
    }
    return 0;
}