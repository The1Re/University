#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next;
}Node;
Node *head = NULL;
int count = 0;

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
        count--;
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
    count++;
}

char convert(char c)
{
    switch(c)
    {
        case ')':
            return '(';
        case '}':
            return '{';
        case ']':
            return '[';
        default:
            return '!';
    }
}

int main(void)
{
    char msg[100];
    scanf("%s", msg);
    for (int i=0; i<strlen(msg); i++)
    {
        if (msg[i] == '(' || msg[i] == '{' || msg[i] == '['){
            push(msg[i]);
        }else if(msg[i] == ')' || msg[i] == '}' || msg[i] == ']'){
            if (convert(msg[i]) == peek()){
                pop();
            }else{
               count = -1;
               break;
            }
        }
    }
    if (count == -1){
        printf("-1");
    }else{
        printf("%d", count);
    }
    return 0;
}