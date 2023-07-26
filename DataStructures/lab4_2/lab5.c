#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node *next;
    struct node *prev;
}Node;
Node *head = NULL;
Node *tail = NULL;

Node *CreateNode(char data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
void New_linkedlist(char data)
{
    Node *new_node = CreateNode(data);
    new_node->next = head;
    tail = new_node;
    head = new_node;
}
void Add_head(char data)
{
    Node *new_node = CreateNode(data);
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
}
void Add_tail(char data)
{
    Node *new_node = CreateNode(data);
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;
}
void Insert_node(int ref, char data)
{
    Node *new_node = CreateNode(data);
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
    new_node->prev = preptr;
    new_node->next = ptr;
    if (ptr == NULL){
        tail = new_node;
    }else{
        ptr->prev = new_node;
    }
}
void remove_head()
{
    Node *ptr = head;
    head->next->prev = NULL;
    head = head->next;
    free(ptr);
}
void remove_tail()
{
    Node *ptr = tail;
    tail->prev->next = NULL;
    tail = tail->prev;
    free(ptr);
}
void remove_atindex(int ref)
{
    int index = 1, check = 0;
    Node *ptr = head;
    Node *preptr = NULL;
    while(ptr != NULL)
    {
        if (ref == index){
            check++;
            break;
        }
        index++;
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ref == 1){
        remove_head();
    }else if(check && ptr->next == NULL){
        remove_tail();
    }else if(check){
        preptr->next = ptr->next;
        ptr->next->prev = preptr;
        free(ptr);
    }
}
void Show_attail()
{
    Node *ptr = tail;
    while (ptr != NULL)
    {
        printf("%c", ptr->data);
        ptr = ptr->prev;
    }
}
void Show_athead()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%c", ptr->data);
        ptr = ptr->next;
    }
}
int Search_item(char ref)
{
    int index = 1;
    Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == ref)
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
            New_linkedlist(msg[++i]);
        }else if (msg[i] == 'I'){
            i++;
            if (msg[i] == 'F'){
                Add_head(msg[++i]);
            }else if (msg[i] == 'L'){
                Add_tail(msg[++i]);
            }else{
                int ref = msg[++i] - '0';
                Insert_node(ref, msg[++i]);
            }
        }else if (msg[i] == 'D'){
            i++;
            if (msg[i] == 'F'){
                remove_head();
            }else if (msg[i] == 'L'){
                remove_tail();
            }else{
                int ref = msg[++i] - '0';
                remove_atindex(ref);
            }
        }else if (msg[i] == 'P'){
            Show_athead();
        }else if (msg[i] == 'R'){
            Show_attail();
        }else{
            printf("%d", Search_item(msg[++i]));
        }
    }
    return 0;
}