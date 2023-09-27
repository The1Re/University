#include <stdio.h>
#include <stdlib.h>

struct Treenode {
    int data, ht;
    struct Treenode *leftChild, *rightChild, *mother;
};
struct Treenode *Root;
struct Treenode *stack[10];
int top = -1;

void push(struct Treenode *node)
{
    stack[++top] = node;
}

struct Treenode *pop()
{
    if (top == -1)
        return NULL;
    return stack[top--];
}

struct Treenode *peek()
{
    if (top == -1)
        return NULL;
    return stack[top];
}

struct Treenode *createNode(int data)
{
    struct Treenode *new_node = malloc(sizeof(struct Treenode));
    new_node->data = data;
    new_node->ht = 1;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    new_node->mother = NULL;
    return new_node;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int height(struct Treenode *t)
{
    if (t == NULL)
        return 0;
    return t->ht;
}


int getBf(int left, int right)
{
    return left - right;
}

void inorder(struct Treenode *r)
{
    if (r == NULL)
        return;
    inorder(r->leftChild);
    printf("%d(Bf=%d)", r->data, getBf(height(r->leftChild), height(r->rightChild)));
    inorder(r->rightChild);
}

void Tree_insert(int data)
{
    struct Treenode *ptr = Root, *preptr = NULL, *new_node = createNode(data);
    while (ptr != NULL)
    {
        preptr = ptr;
        push(preptr);
        if (data < ptr->data)
            ptr = ptr->leftChild;
        else
            ptr = ptr->rightChild;
    }
    if (preptr == NULL)
        Root = new_node;
    else{
        if (new_node->data < preptr->data)
            preptr->leftChild = new_node;
        else
            preptr->rightChild = new_node;
        new_node->mother = preptr;
    }

    while (peek())
    {
        ptr = pop();
        ptr->ht = 1 + max(height(ptr->leftChild), height(ptr->rightChild));
    }
}



int main(void)
{
    int a[] = {17, 3, 19, 1, 6, 18, 22, 4, 25};
    int i,size;
    size = sizeof(a)/sizeof(int);
    for (int i=0; i<size; i++)
        Tree_insert(a[i]);
    inorder(Root);
    return 0;
}