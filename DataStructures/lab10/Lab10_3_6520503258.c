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

struct Treenode *leftRotate(struct Treenode *x)
{
    struct Treenode *y = x->rightChild;
    struct Treenode *z = y->leftChild;
    y->leftChild = x;
    x->rightChild = z;
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
    x->ht = 1 + max(height(x->leftChild), height(x->rightChild));
    y->ht = 1 + max(height(y->leftChild), height(y->rightChild));
    return y;
}

void Rotate(struct Treenode *criticalNode, int bf)
{
    int bf_child;
    struct Treenode *child = NULL;
    if (bf >= 2){
        child = criticalNode->leftChild;
        bf_child = getBf(height(child->leftChild), height(child->rightChild));
        
        if (bf_child >= 0){
            printf("Right Rotate at Node : %d\n", criticalNode->data);
            if (criticalNode == Root)
                Root = rightRotate(criticalNode);
            else
                criticalNode = rightRotate(criticalNode);
        }else{
            printf("Left-Right Double Rotate\n");
            printf("Left Rotate at Node : %d\n", child->data);
            printf("Right Rotate at Node : %d\n", criticalNode->data);
            criticalNode->leftChild = leftRotate(child);
            if (criticalNode == Root)
                Root = rightRotate(criticalNode);
            else
                criticalNode = rightRotate(criticalNode);
        }
       
    }else if (bf <= -2){
        child = criticalNode->rightChild;
        bf_child = getBf(height(child->leftChild), height(child->rightChild));

        if (bf_child <= 0){
            printf("Left Rotate at Node : %d\n", criticalNode->data);
            if (criticalNode == Root)
                Root = leftRotate(criticalNode);
            else
                criticalNode = leftRotate(criticalNode);
        }else{
            printf("Right-Left Double Rotate\n");
            printf("Right Rotate at Node : %d\n", child->data);
            printf("Left Rotate at Node : %d\n", criticalNode->data);
            criticalNode->rightChild = rightRotate(child);
            if (criticalNode == Root)
                Root = leftRotate(criticalNode);
            else
                criticalNode = leftRotate(criticalNode);
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

        int bf = getBf(height(ptr->leftChild), height(ptr->rightChild));
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