#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTACK 10

struct Treenode {
 char data;
 struct Treenode *leftChild;
 struct Treenode *rightChild;
};
struct Treenode *Root = NULL;

struct Treenode* createNode(char data)
{
    struct Treenode *new_node = malloc(sizeof(struct Treenode));
    new_node->data = data;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    return new_node;
}

struct Treenode *Stack[MAXSTACK];
int top = -1;

void push(struct Treenode *node)
{
    if (top == MAXSTACK-1)
        printf("Stack is Max!\n");
    else
        Stack[++top] = node;
}

struct Treenode *pop()
{
    if (top == -1)
        return NULL;
    else
        return Stack[top--];
}

int operation(char opt, int x, int y)
{
    switch(opt)
    {
        case '+':return x+y;
        case '-':return x-y;
        case '*':return x*y;
        case '/':return x/y;
        // case '^':return pow(x,y);
        default:
            return -1;
    }
}

struct Treenode *prefixToTree(char prefix[])
{
    for (int i=strlen(prefix)-1; i>=0; i--)
    {
        if (isdigit(prefix[i])){
            push(createNode(prefix[i]));
        }else{
            Root = createNode(prefix[i]);
            Root->leftChild = pop();
            Root->rightChild = pop();
            push(Root);
        }
    }
    return pop();
}

void infix(struct Treenode *r)
{
    if (r == NULL)
        return;
    else{
        if (isdigit(r->data))
            printf("%c", r->data);
        else{
            printf("(");
            infix(r->leftChild);
            printf("%c", r->data);
            infix(r->rightChild);
            printf(")");
        }
    }
}

int eval(struct Treenode *r)
{
    if (r == NULL)
        return 0;
    if (r->leftChild == NULL && r->leftChild == NULL)
        return r->data - '0';
    int x = eval(r->leftChild);
    int y = eval(r->rightChild);
    return operation(r->data, x, y);
}

int main(void)
{
    char prefix[51];
    scanf("%s", prefix);

    Root = prefixToTree(prefix);
    infix(Root);
    printf("=%d", eval(Root));

    return 0;
}