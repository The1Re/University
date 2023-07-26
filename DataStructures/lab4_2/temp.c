#include <stdio.h>
#include <stdlib.h>

typedef struct Dnode
{
    char ch;
    struct Dnode *next;
    struct Dnode *prev;
}Dnode;

Dnode *newNode(char v)
{
    Dnode *new_node = (Dnode *)malloc(sizeof(Dnode));
    new_node->ch = v;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

int main(void)
{
    Dnode *n1 = newNode('c');
    Dnode *n2 = newNode('a');
    Dnode *n3 = newNode('t');
    n1->next = n2;
    n2->next = n3;
    n3->prev = n2;
    n2->prev = n1;
    Dnode *n = n1;
    Dnode *p = n2;
    printf("%c", n->next->next->ch);
    return 0;
}