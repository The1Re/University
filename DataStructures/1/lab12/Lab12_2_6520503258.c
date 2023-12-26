#include <stdio.h>
#include <stdlib.h>
int n;

typedef struct Gnode{
    char data;
    int id;
    struct Gnode *next;
}Gnode;

Gnode *createNode(char data, int index)
{
    Gnode *new_node = malloc(sizeof(Gnode));
    new_node->data = data;
    new_node->id  = index;
    new_node->next = NULL;
    return new_node;
}
void addHead(Gnode **sub_root, char data, int index)
{
    Gnode *new_node = createNode(data, index);
    new_node->next = *sub_root;
    *sub_root = new_node;
}

void setNULL(Gnode *root[])
{
    for (int i=0; i<n; i++)
        root[i] = NULL;
}
void createGraph(Gnode *root[], char *V, int G[][n])
{
    for (int i=0; i<n; i++)
    {
        root[i] = createNode(V[i], i);
        for (int j=0; j<n; j++)
            if (G[i][j])
                addHead(&root[i]->next, V[j], j);
    }
}
void display(Gnode *root[])
{
    for (int i=0; i<n; i++)
    {
        printf("[%c]", root[i]->data);
        if (root[i]->next == NULL)
            printf(" -> NULL");
        else{
            Gnode *ptr = root[i]->next;
            while (ptr != NULL)
            {
                printf(" -> %c", ptr->data);
                ptr = ptr->next;
            }
        }
        printf("\n");
    }
}

void setStatus(int status[])
{
    for (int i=0; i<n; i++)
        status[i] = 1;
}

void DFT(Gnode *root[])
{
    int status[n];
    setStatus(status);
    int stack[n]; 
    int top = -1;

    stack[++top] = root[0]->id; //push start node
    status[root[0]->id] = 2;

    while (top != -1)
    {
        int node_index = stack[top--]; //pop to process
        printf("%c ", root[node_index]->data);
        status[node_index] = 3;

        Gnode *ptr = root[node_index]->next;
        while (ptr != NULL)
        {
            if (status[ptr->id] == 1){
                stack[++top] = ptr->id;
                status[ptr->id] = 2;
            }
            ptr = ptr->next;
        }
    } 
}

void BFT(Gnode *root[])
{
    int status[n];
    setStatus(status);
    int queue[n];
    int head = 0, tail = 0;

    queue[tail] = root[0]->id; //enqueue start node
    status[root[0]->id] = 2;

    while (head <= tail)
    {
        int node_index = queue[head]; head++; //dequeue to process
        printf("%c ", root[node_index]->data);
        status[node_index] = 3;

        Gnode *ptr = root[node_index]->next;
        while (ptr != NULL)
        {
            if (status[ptr->id] == 1){
                queue[++tail] = ptr->id;
                status[ptr->id] = 2;
            }
            ptr = ptr->next;
        }
    }
}

int main()
{
    int i, j;
    printf("Enter number of vertices : ");
    scanf("%d", &n);

    int status[n];
    int G[n][n];
    char V[n+1];
    Gnode *root[n];
    setNULL(root);

    printf("Enter node's name : ");
    scanf("%s", V);

    printf("Enter the adjaceny matrix : \n");
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%d", &G[i][j]);

    createGraph(root, V, G);
    display(root);

    printf("DFS Traversal: ");
    DFT(root);

    printf("\nBFS Traversal : ");
    BFT(root);

    return 0;
}