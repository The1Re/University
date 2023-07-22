#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}Node;
Node *head = NULL;
Node *tail = NULL;

void doublyMarker()
{
    Node *ptr = head;
    Node *preptr = NULL;
    while (ptr != NULL)
    {
        ptr->prev = preptr;
        tail = ptr;
        preptr = ptr;
        ptr = ptr->next;
    }
    //ptr->prev = preptr;
    
}

void show_attail()
{
    Node *ptr = tail;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}
void show_athead()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


int main(void)
{
    int n;
    printf("Enter n : ");
    scanf("%d", &n);

    //create singly linked list
    for (int i=0; i<n; i++)
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = n-i;
        new_node->next = head;
        new_node->prev = NULL;
        head = new_node; 
    }
    doublyMarker();
    show_attail();

    return 0;
}