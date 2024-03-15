#include <stdio.h>
#include <stdlib.h>
#define INF 9999

int vertices;

void printSolution(int adj[][vertices])
{
    printf(
        "The following matrix shows the shortest distances"
        " between every pair of vertices \n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (adj[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", adj[i][j]);
        }
        printf("\n");
    }
}

void FloydWarshall(int adj[][vertices])
{
    for (int k=0; k<vertices; k++)
        for (int i=0; i<vertices; i++)
            for (int j=0; j<vertices; j++)
                if (adj[i][k] + adj[k][j] < adj[i][j])
                    adj[i][j] = adj[i][k] + adj[k][j];

    printSolution(adj);
}

void initArray(int adj[][vertices])
{
    for (int i=0; i<vertices; i++)
        for (int j=0; j<vertices; j++)
            adj[i][j] = INF;
}
void setGraph(int adj[][vertices])
{
    for (int i=0; i<vertices; i++)
        for (int j=0; j<vertices; j++)
            scanf("%d", &adj[i][j]);
}

int main(int argc, char const *argv[])
{
    printf("Enter no of vertices : ");
    scanf("%d", &vertices);

    int adj[vertices][vertices];
    initArray(adj);
    setGraph(adj);

    FloydWarshall(adj);

    return 0;
}