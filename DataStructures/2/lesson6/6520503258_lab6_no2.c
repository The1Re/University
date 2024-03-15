#include <stdio.h>
#define MAX 10

int n, adj[MAX][MAX], visited[MAX]; //visited 0 = white, 1 = gray, 2 = black

void setgraph()
{
    printf("Enter number of Vertices in Graph : ");
    scanf("%d", &n);
    printf("\nEnter the Adjacency Matrix\n");
    
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            scanf("%d", &adj[i][j]);
    for (int i=0; i<n; i++)
        visited[i] = 0;
}

void dfs(int source)
{
    int stack[MAX], top = -1;

    for (int i=0; i<MAX; i++)
        visited[i] = 0;

    source = source - 1; //convert number to index
    stack[++top] = source;
    visited[source] = 1;

    while (top != -1)
    {
        int index = stack[top]; top--;
        visited[index] = 2;

        printf("%d ", index + 1); //convert index to number

        for (int col=0; col<n; col++)
        {
            if (adj[index][col] && visited[col] == 0){
                stack[++top] = col;
                visited[col] = 1;
            }
        }

    }
    
}

int main()
{
    int source;
    setgraph();

    printf("\nEnter the Source : ");
    scanf("%d", &source);
    printf("The nodes visited in DFS order is : ");
    dfs(source);

    return 0;
}