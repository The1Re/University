#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node *next;
}Node;
Node *head = NULL;

void Add_head(char data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}
void Insert_node(int ref, char data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    Node *preptr = head;
    Node *ptr = head->next;
    int index = 1;
    while (ptr != NULL)
    {
        if (ref == index)
            break;
        index++;
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
}
void Add_tail(char data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    Node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
}
void ShowLL()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%c", ptr->data);
        ptr = ptr->next;
    }
}
int Search_LL(char ref)
{
    int index = 1;
    Node *ptr = head;
    while (ptr != NULL)
    {
        if (ref == ptr->data)
            return index;
        index++;
        ptr = ptr->next;
    }
    return -1;
}

int main(void)
{
    char msg[31];
    scanf("%s", msg);
    for (int i=0; i<strlen(msg); i++)
    {
        if (msg[i] == 'N'){
            Add_head(msg[++i]);
        }else if (msg[i] == 'I'){
            i++;
            if (msg[i] == 'F')
                Add_head(msg[++i]);
            else if (msg[i] == 'L')
                Add_tail(msg[++i]);
            else{
                int pos = msg[++i] - '0';
                Insert_node(pos, msg[++i]);
            }
        }else if (msg[i] == 'P'){
            ShowLL();
        }else{
            printf("%d", Search_LL(msg[++i]));
        }
    }
    return 0;
}