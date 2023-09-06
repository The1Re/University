#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void push(int data)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void resetNode()
{
    head = NULL;
}

bool isPalindrome(char msg[],int start, int end)
{
    resetNode();
    int i, length = (start+end)/2;
    for (i=start; i<length; i++)
        push(msg[i]);
    if ((end-start)%2) i++;
    while (i < end)
    {
        if (msg[i] != pop())
            return false;
        i++;
    }
    return true;
}

int main(void)
{
    int half, start = 0, end;
    char msg[100];
    scanf("%s", msg);

    //Convert to Upper case
    for (int i=0; i<strlen(msg); i++)
        msg[i] = toupper(msg[i]);
    
    //Find mid string
    end = strlen(msg);
    half = end/2;
    
    if (isPalindrome(msg, start, end)){
        if (isPalindrome(msg, start, half) && isPalindrome(msg, strlen(msg)%2 ? ++half : half, end)){
            printf("Double Palindrome");
        }else{
            printf("Palindrome");
        }
    }else{
        printf("No");
    }

    return 0;
}