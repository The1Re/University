#include <stdio.h>
int n;

void setStatus(int status[])
{
    for (int i=0; i<n; i++)
        status[i] = 1;
}

void DFT(char *V, int G[][n], int status[])
{
    int stack[n]; 
    int top = -1;
    setStatus(status);

    stack[++top] = 0; //push start node
    status[0] = 2;

    while (top != -1)
    {
        int node_index = stack[top--]; //pop to process
        printf("%c ", V[node_index]);
        status[node_index] = 3;

        for (int col=0; col<n; col++)
        {
            if (G[node_index][col] && (status[col] == 1)){
                stack[++top] = col;
                status[col] = 2;
            }
        }
    } 
}

void BFT(char *V, int G[][n], int status[])
{
    int queue[n];
    int head = 0, tail = 0;
    setStatus(status);

    queue[tail] = 0; //enqueue start node
    status[0] = 2;

    while (head <= tail)
    {
        int node_index = queue[head]; head++; //dequeue to process
        printf("%c ", V[node_index]);
        status[node_index] = 3;

        for (int col=0; col<n; col++)
        {
            if (G[node_index][col] && (status[col] == 1)){
                queue[++tail] = col;
                status[col] = 2;
            }
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

    printf("Enter node's name : ");
    scanf("%s", V);

    printf("Enter the adjaceny matrix : \n");
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%d", &G[i][j]);

    printf("DFS Traversal: ");
    DFT(V, G, status);

    printf("\nBFS Traversal : ");
    BFT(V, G, status);

    return 0;
}