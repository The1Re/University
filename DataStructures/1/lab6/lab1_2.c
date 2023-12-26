#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *head = NULL, *tail = NULL;
int size = 0;

Node *createNode(int value)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void enqueue(int value)
{
    Node *new_node = createNode(value);
    if (size == 0){
        head = new_node;
        tail = new_node;
    }else{
        tail->next = new_node;
        tail = tail->next;
    }
    size++;
}

int dequeue()
{
    int data;
    if (size == 0){
        printf("Queue is Empty\n");
        return -1;
    }else{
        Node *ptr = head;
        data = ptr->data;
        head = head->next;
        free(ptr);
        size--;
        return data;
    }
}

void display()
{
    if (size == 0)
        printf("Queue is Empty\n");
    else{
        Node *ptr = head;
        printf("front[ ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("]rear\n");
    }
}

int main(void)
{
    int i,n;
    for (i=1; i<1000; i*=2)
        enqueue(i);
    display();

    scanf("%d", &n);
    for (i=1; i<=n; i++)
        dequeue();
    display();

    for (i=10; i>=1; i/=2)
        enqueue(i);
    display();
    return 0;
}