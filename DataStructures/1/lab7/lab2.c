#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;
Node *head = NULL;

bool isEmpty()
{
    if (head == NULL)
        return true;
    return false;
}

int pop()
{
    if (isEmpty())
        return -1;
    else{
        int data = head->data;
        Node *ptr = head;
        head = head->next;
        ptr->next = NULL;
        free(ptr);
        return data;
    }
}

int peek()
{
    if (isEmpty())
        return -1;
    else{
        return head->data;
    }
}

void push(int data)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void display()
{
    if (isEmpty())
        printf("Stack is Empty\n");
    else{
        Node *ptr = head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
   push(16);
   push(12);
   push(20);
   int x = pop();
   push(7);
   push(11);
   push(4);
   int y = pop();
   int z = pop();
   printf("%d %d %d\n", x,y, z);
   push(peek()+z);
   display();
  return 0;
}