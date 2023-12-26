#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

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

void DisplayAddressLL()
{
  struct node *ptr;
  ptr = head;
  while(ptr != NULL)
  {
     printf("Node val=%d,add=%X\t ", ptr -> data,ptr);
     printf("Next node add=%X\n",ptr->next);

     ptr = ptr -> next;
  }
}

int main(void)
{
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    srand((unsigned) time(NULL));
    for (int i=0; i<n; i++)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = rand()%100+1;
        new_node->next = head;
        head = new_node;
    }
    DisplayLL();
    DisplayAddressLL();
    return 0;
}