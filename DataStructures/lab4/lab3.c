#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;
Node *head = NULL;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void InsertionSort(int A[], int n)
{
    for (int i=1; i<=n-1; i++)
    {
        int j = i;
        while (j>0 && A[j]<A[j-1])
        {
            swap(&A[j], &A[j-1]);
            j--;
        }
    }
}
void DisplayArray(int A[], int n)
{
    int i;

    for (i=0; i< n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void DisplayLL()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void Insert_LL(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (data < head->data){
        new_node->next = head;
        head = new_node;
    }else{
        Node *ptr = head;
        Node *preptr = NULL;
        while (ptr != NULL)
        {
            if (data < ptr->data)
                break;
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = new_node;
        new_node->next = ptr;
    }
}

int main(void)
{
    int n;
    printf("Enter n : ");
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    InsertionSort(arr, n);

    for (int i=0; i<n; i++)
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = arr[n-i-1];
        new_node->next = head;
        head = new_node;
    }
    DisplayLL();

    int newnode;
    printf("Enter new node : ");
    scanf("%d", &newnode);
    Insert_LL(newnode);
    DisplayLL();

    return 0;
}