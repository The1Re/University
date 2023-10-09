#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAXSTACK 10

typedef struct AVLTree{
    char data;
    int ht;
    struct AVLTree *rightChild, *leftChild, *mother;
}AVL;
AVL *Root = NULL;
AVL *stack[MAXSTACK];
int top = -1;

AVL *createNode(char data)
{
    AVL *new_node = malloc(sizeof(AVL));
    new_node->data = data;
    new_node->ht = 1;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    new_node->mother = NULL;
    return new_node;
}

void push(AVL *t)
{
    stack[++top] = t;
}
AVL *pop()
{
    if (top == -1)
        return NULL;
    return stack[top--];
}
AVL *peek()
{
    if (top == -1)
        return NULL;
    return stack[top];
}

int max(int x, int y)
{
    return x > y ? x : y;
}
int height(AVL *t)
{
    if (t == NULL)
        return 0;
    return t->ht;
}
int getBf(AVL *current)
{
    return height(current->leftChild) - height(current->rightChild);
}

AVL *leftRotate(AVL *x)
{
    AVL *y = x->rightChild;
    AVL *z = y->leftChild;
    y->leftChild = x;
    x->rightChild = z;

    y->mother = x->mother;
    x->mother = y;
    if (z != NULL)
        z->mother = x;

    x->ht = 1 + max(height(x->leftChild), height(x->rightChild));
    y->ht = 1 + max(height(y->leftChild), height(y->rightChild));
    return y;
}
AVL *rightRotate(AVL *x)
{
    AVL *y = x->leftChild;
    AVL *z = y->rightChild;
    y->rightChild = x;
    x->leftChild = z;

    y->mother = x->mother;
    x->mother = y;
    if (z != NULL)
        z->mother = x;

    x->ht = 1 + max(height(x->leftChild), height(x->rightChild));
    y->ht = 1 + max(height(y->leftChild), height(y->rightChild));
    return y;
}
void Rotate(AVL *criticalNode, int bf)
{
    int bf_child;
    AVL *child = NULL;
    AVL *parent = criticalNode->mother;
    if (bf >= 2){
        child = (criticalNode)->leftChild;
        bf_child = getBf(child);
        
        if (bf_child < 0){
            (criticalNode)->leftChild = leftRotate(child);
        }

        if (criticalNode == Root)
            Root = rightRotate(criticalNode);
        else{
            if (parent->leftChild == criticalNode)
                parent->leftChild = rightRotate(criticalNode);
            else
                parent->rightChild = rightRotate(criticalNode);
        }
       
    }else if (bf <= -2){
        child = (criticalNode)->rightChild;
        bf_child = getBf(child);

        if (bf_child > 0){
            (criticalNode)->rightChild = rightRotate(child);
        }

        if (criticalNode == Root)
            Root = leftRotate(criticalNode);
        else{
            if (parent->leftChild == criticalNode)
                parent->leftChild = leftRotate(criticalNode);
            else
                parent->rightChild = leftRotate(criticalNode);
        }
    }
}

void Tree_insert(char data)
{
    AVL *ptr = Root, *preptr = NULL, *new_node = createNode(data);
    while (ptr != NULL)
    {
        if (ptr->data == data)
            return;
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

        int bf = getBf(ptr);
        if (bf >= 2 || bf <= -2){
            Rotate(ptr, bf);
        }
        
    }    
}

void inorder(AVL *t)
{
    if (t == NULL)
        return;
    inorder(t->leftChild);
    printf("%c", t->data, getBf(t));
    inorder(t->rightChild);
}
void preorder(AVL *t)
{
    if (t == NULL)
        return;
    printf("%c", t->data);
    preorder(t->leftChild);
    preorder(t->rightChild);
}
void postorder(AVL *t)
{
    if (t == NULL)
        return;
    postorder(t->leftChild);
    postorder(t->rightChild);
    printf("%c", t->data);
}
int find(AVL *t, char key)
{
    int level = 0;
    while (t != NULL)
    {
        if (t->data == key)
            return level;   
        if (t->data < key)
            t = t->rightChild;
        else
            t = t->leftChild;
        level++;
    }
    return -1;
}

int main(void)
{
    char input[30];
    scanf("%s", input);
    for (int i=0; i<strlen(input); i++)
    {
        if (isalpha(input[i]))
            Tree_insert(input[i]);
        else if (input[i] == '1')
            printf("%d", find(Root, input[++i]));
        else if (input[i] == '2')
            preorder(Root);
        else if (input[i] == '3')
            inorder(Root);
        else
            postorder(Root);
    }
    return 0;
}