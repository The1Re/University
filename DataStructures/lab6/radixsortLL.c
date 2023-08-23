#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BASE 10

typedef struct node{
    int data;
    struct node *next;
}Node;
Node *buffer[BASE];

//pos = 1 is digit position 1
int findDigit(int num, int pos)
{
    return (int)(num/pow(10,pos-1)) % 10;
}

Node *createNode(int value)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void enqueue(Node **head, int value)
{
    Node *new_node = createNode(value);
    if (*head == NULL)
        *head = new_node;
    else{
        Node *ptr = *head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
    }
}

int dequeue(Node **head)
{
    int value;
    if (*head == NULL)
        return -1;
    else{
        Node *ptr = *head;
        *head = (*head)->next;
        value = ptr->data;
        free(ptr);
        return value;
    }
}

void resetNode()
{
    for (int i=0; i<BASE; i++)
        buffer[i] = NULL;
}

int main()
{
    int i, n=20;
    srand((unsigned) time(NULL));
    int num[n];

    printf("Number before sorting\n");
    for (i=0; i<n; i++)
    {
        num[i] = rand()%32767 + 1;
        printf("%d ", num[i]);
    }

    //Sorting with Radixsort
    for (int digitpos=1; digitpos<=5; digitpos++)
    {
        resetNode();
        for (int i=0; i<n; i++)
        {
            int digit = findDigit(num[i], digitpos);
            enqueue(&buffer[digit], num[i]);
        }

        //Queue to array
        int k=0;
        for (int i=0; i<BASE; i++)
        {
            while (1)
            {
                int temp = dequeue(&buffer[i]);
                if (temp == -1)
                    break;
                num[k++] = temp;
            }
        }
    }

    printf("\nNumber before sorting\n");
    for (i=0; i<n; i++)
        printf("%d ", num[i]);
    return 0;
}
