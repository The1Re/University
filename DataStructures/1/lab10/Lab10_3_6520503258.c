#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Treenode {
    int data, ht;
    struct Treenode *leftChild, *rightChild, *mother;
};
struct Treenode *Root;
struct Treenode *stack[10];
int top = -1;
bool isAVL = true;

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


int getBf(struct Treenode *t)
{
    return height(t->leftChild) - height(t->rightChild);
}

void inorder(struct Treenode *r)
{
    if (r == NULL)
        return;
    inorder(r->leftChild);
    printf("%d(Bf=%d)", r->data, getBf(r));
    inorder(r->rightChild);
}

struct Treenode *leftRotate(struct Treenode *x)
{
    struct Treenode *y = x->rightChild;
    struct Treenode *z = y->leftChild;
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

struct Treenode *rightRotate(struct Treenode *x)
{
    struct Treenode *y = x->leftChild;
    struct Treenode *z = y->rightChild;
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

void Rotate(struct Treenode *criticalNode, int bf)
{
    int bf_child;
    struct Treenode *child = NULL;
    struct Treenode *parent = criticalNode->mother;
    if (bf >= 2){
        child = (criticalNode)->leftChild;
        bf_child = getBf(child);
        
        if (bf_child < 0){
            printf("Left-Right Double Rotate\n");
            printf("Left Rotate at Node : %d\n", child->data);
            (criticalNode)->leftChild = leftRotate(child);
        }

        printf("Right Rotate at Node : %d\n", (criticalNode)->data);
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
            printf("Right-Left Double Rotate\n");
            printf("Right Rotate at Node : %d\n", child->data);
            (criticalNode)->rightChild = rightRotate(child);
        }

        printf("Left Rotate at Node : %d\n", (criticalNode)->data);
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

        int bf = getBf(ptr);
        if (bf >= 2 || bf <= -2){
            Rotate(ptr, bf);
        }
        
    }


        
}

int main(void)
{
    int num;
    do {
        printf("insert node : ");
        scanf("%d", &num);
        if (num >= 0)
            Tree_insert(num);
    }while (num >= 0);
    inorder(Root);
    return 0;
}