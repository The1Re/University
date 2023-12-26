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
        preptr = ptr;
        ptr = ptr->next;
    }
    tail = preptr;
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
Node *CreateNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

int main(void)
{
    int n;
    printf("Enter n : ");
    scanf("%d", &n);

    //create singly linked list
    for (int i=0; i<n; i++)
    {
        Node *new_node = CreateNode(n-i);
        new_node->next = head;
        head = new_node; 
    }
    doublyMarker();
    show_attail();

    return 0;
}