#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Treenode{
    char data;
    struct Treenode *leftChild, *rightChild, *mother;
}Tree;
Tree *Root = NULL;

Tree* createNode(char data)
{
    Tree *new_node = (Tree *)malloc(sizeof(Tree));
    new_node->data =data;
    new_node->leftChild =NULL;
    new_node->rightChild=NULL;
    new_node->mother=NULL;
    return new_node;
}

void insertNode(char data)
{
    Tree *y = NULL, *x = createNode(data), *t = Root;
    while (t != NULL)
    {
        y = t;
        if (data == t->data)
            return;
        if (data < t->data)
            t = t->leftChild;
        else
            t = t->rightChild;
    }
    if (y == NULL)
        Root = x;
    else{
        if (x->data < y->data)
            y->leftChild = x;
        else
            y->rightChild = x;
        x->mother = y;
    }

}

int find(Tree *t, char key)
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

Tree *FindMin(Tree *t)
{
    while (t->leftChild != NULL)
        t = t->leftChild;
    return t;
}

Tree *FindMax(Tree *t)
{
    while (t->rightChild != NULL)
        t = t->rightChild;
    return t;
}

Tree *Tree_Find(Tree *t, char key)
{
    while (t != NULL)
    {
        if (t->data == key)
            return t;   
        if (t->data < key)
            t = t->rightChild;
        else
            t = t->leftChild;
    }
    return NULL;
}

void Tree_delete(Tree *t, char data)
{
    Tree *x = Tree_Find(t, data);
    if (x == NULL)
        printf("-1");
    else{
        if (x->leftChild != NULL && x->rightChild != NULL){
            // Tree *y = FindMax(x->leftChild);
            Tree *y = FindMin(x->rightChild);
            x->data = y->data;
            Tree_delete(x->rightChild, y->data);
        }else{
            Tree *parent = x->mother;
            if (x->leftChild == NULL && x->rightChild == NULL){
                if (parent->leftChild == x)
                    parent->leftChild = NULL;
                else
                    parent->rightChild = NULL;
                free(x);
            }else{
                if (x->leftChild != NULL){
                    parent->leftChild = x->leftChild;
                    free(x);
                }else{
                    parent->rightChild = x->rightChild;
                    free(x);
                }
            }
        }
    }
}

void preorder(Tree *t)
{
    if (t == NULL)
        return;
    printf("%c", t->data);
    preorder(t->leftChild);
    preorder(t->rightChild);
}

void inorder(Tree *t)
{
    if (t == NULL)
        return;
    inorder(t->leftChild);
    printf("%c", t->data);
    inorder(t->rightChild);
}

void postorder(Tree *t)
{
    if (t == NULL)
        return;
    postorder(t->leftChild);
    postorder(t->rightChild);
    printf("%c", t->data);
}

int main(void)
{
    char input[30];
    scanf("%s", input);
    for (int i=0; i<strlen(input); i++)
    {
        if (isalpha(input[i])){
            insertNode(input[i]);
        }else if(input[i] == '0'){
            Tree_delete(Root, input[++i]);
        }else if(input[i] == '1'){
            printf("%d", find(Root, input[++i]));
        }else if(input[i] == '2')
            preorder(Root);
        else if(input[i] == '3')
            inorder(Root);
        else if(input[i] == '4')
            postorder(Root);
        else if(input[i] == '5'){
            printf("%c%c", FindMin(Root)->data, FindMax(Root)->data);
        }else
            printf("Error !\n");
    }

    return 0;
}