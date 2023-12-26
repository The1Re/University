#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;
Node *head = NULL;

Node *createNode(int value)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void addHead(int value)
{
    Node *new_node = createNode(value);
    new_node->next = head;
    head = new_node;
}

void addLast(int value)
{
    Node *new_node = createNode(value);
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
}

void deleteHead()
{
    Node *ptr = head;
    head = head->next;
    free(ptr);
}

void deleteLast()
{
    Node *preptr = NULL;
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
}

void display()
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
    addHead(2);
    addHead(1);
    addLast(4);
    deleteLast();
    display();
    return 0;
}