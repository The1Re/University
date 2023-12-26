#include <stdio.h>
#include <stdlib.h>

struct Treenode {
 char data;
 struct Treenode *leftChild;
 struct Treenode *rightChild;
};
struct Treenode *Root;

struct Treenode* createNode(char );
void SetLeft(struct Treenode* , char );
void SetRight(struct Treenode*, char );
void preorder(struct Treenode *);
void postorder(struct Treenode *);

int main()
{
   struct Treenode *pn,*tnode;

  //create Exptree for Lab8
  //create root node
  tnode=createNode('*');
  if(Root == NULL)
    Root=tnode;

  //create node level 1
    SetLeft(Root,'+');
    SetRight(Root,'-');

  //create node level 2
    pn = Root->leftChild;
    SetLeft(pn,'*');
    SetRight(pn,'/');

    pn = Root->rightChild;
    SetLeft(pn, 'E');
    SetRight(pn, 'F');

  //create node level 3
    pn = Root->leftChild->leftChild;
    SetLeft(pn,'A');
    SetRight(pn,'B');

    pn = Root->leftChild->rightChild;
    SetLeft(pn, 'C');
    SetRight(pn, 'D');


  //call preorder and postorder
    printf("Prefix : ");
    preorder(Root);
    printf("\nPostfix : ");
    postorder(Root);
    
   free(tnode);
   free(pn);

  return 0;
}

struct Treenode* createNode(char data)
{
    struct Treenode *new_node = malloc(sizeof(struct Treenode));
    new_node->data = data;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    return new_node;
}

void SetLeft(struct Treenode* parent, char data)
{
    parent->leftChild = createNode(data);
}

void SetRight(struct Treenode* parent, char data)
{
    parent->rightChild = createNode(data);
}

void preorder(struct Treenode *r)
{
    if (r == NULL)
        return ;
    printf("%c ", r->data);
    preorder(r->leftChild);
    preorder(r->rightChild);
}

void postorder(struct Treenode *r)
{
    if (r == NULL)
        return;
    postorder(r->leftChild);
    postorder(r->rightChild);
    printf("%c ", r->data);
}  