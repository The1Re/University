#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTACK 10

struct Treenode {
 int data;
 struct Treenode *leftChild;
 struct Treenode *rightChild;
};
struct Treenode *Root = NULL;

struct Treenode* createNode(int data)
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

struct Treenode *postfixToTree(char prefix[])
{
    int num = 0;
    for (int i=0; i<strlen(prefix); i++)
    {
        if (prefix[i] == ' '){
            if (num != 0)
                push(createNode(num));
            num = 0;
        }else if (isdigit(prefix[i])){
            num = num*10 + (prefix[i] - '0');
        }else{
            Root = createNode(prefix[i]);
            Root->rightChild = pop();
            Root->leftChild = pop();
            push(Root);
        }
    }
    return pop();
}

void infix(struct Treenode *r)
{
    char opt[] = "+-*/";
    if (r == NULL)
        return;
    else{
        if (r->data > 255 || !strchr(opt, (char)(r->data)))
            printf("%d", r->data);
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
        return r->data;
    int x = eval(r->leftChild);
    int y = eval(r->rightChild);
    return operation(r->data, x, y);
}

int main(void)
{
    char postfix[101];
    scanf("%[^\n]s", postfix);
    Root = postfixToTree(postfix);
    infix(Root);
    printf("=%d", eval(Root));

    return 0;
}