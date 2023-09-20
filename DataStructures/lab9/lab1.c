#include <stdio.h>
#include <stdlib.h>

struct Treenode {
 int data;
 struct Treenode *leftChild,*rightChild;
 struct Treenode *mother;
};
struct Treenode *Root;

struct Treenode* createNode(int data)
{
    struct Treenode *new_node;
    new_node= (struct Treenode*) malloc(sizeof(struct Treenode));
    new_node->data =data;
    new_node->leftChild =NULL;
    new_node->rightChild=NULL;
    new_node->mother=NULL;
    return new_node;
}

void insertNode(int data)
{
    struct Treenode *y = NULL, *x = createNode(data), *t = Root;
    while (t != NULL)
    {
        y = t;
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

void Inorder(struct Treenode *t)
{
    if (t == NULL)
        return;
    Inorder(t->leftChild);
    printf("%d ", t->data);
    Inorder(t->rightChild);
}

struct Treenode *Tree_Find(struct Treenode *t, int key)
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

struct Treenode *FindMin(struct Treenode *t)
{
    while (t->leftChild != NULL)
        t = t->leftChild;
    return t;
}

struct Treenode *FindMax(struct Treenode *t)
{
    while (t->rightChild != NULL)
        t = t->rightChild;
    return t;
}

void Tree_delete(struct Treenode *t, int data)
{
    struct Treenode *x = Tree_Find(t, data);
    if (x == NULL)
        printf("Not found\n");
    else{
        if (x->leftChild != NULL && x->rightChild != NULL){
            struct Treenode *y = FindMax(x->leftChild);
            x->data = y->data;
            Tree_delete(x->leftChild, y->data);
        }else{
            struct Treenode *parent = x->mother;
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



int main()
{
  int a[]={56,26,200,18,28,190,213,12,24,27};
  int i,size;
  size=sizeof(a)/sizeof(a[0]);

  for(i=0;i<size;i++)
        insertNode(a[i]);
   printf("Min=%d\n",FindMin(Root)->data);
   printf("Max=%d\n",FindMax(Root)->data);

   struct Treenode *p;
   p=Tree_Find(Root,190);

  if(p!=NULL)
    printf("Found\n");
  else
    printf("Not found\n");

   Tree_delete(Root,190);
   Tree_delete(Root,26);

   Inorder(Root);
}

