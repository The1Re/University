//6520503258 Kanesh Orachunlertmitri
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int vertices, edges;

void BellmanFord(int adj[vertices][vertices], int src)
{
    int d[vertices], p[vertices];
    for (int v=0; v<vertices; v++)
        d[v] = INT_MAX, p[vertices] = -1;

    src -= 1;
    d[src] = 0;
    for (int i=1; i<vertices; i++)
    {
        for (int u=0; u<vertices; u++)
            for (int v=0; v<vertices; v++)
                if (adj[u][v] && d[u] + adj[u][v] < d[v]){
                    d[v] = d[u] + adj[u][v];
                    p[v] = u;
                }
    }

    for (int u=0; u<vertices; u++)
        for (int v=0; v<vertices; v++)
            if (adj[u][v] && d[u] + adj[u][v] < d[v]){
                printf("Negative weight cycle detected!"); 
                return;
            }
    
    //print result
    for (int i=0; i<vertices; i++)
    {
        int j=i;
        if (i != src){
            int arr[vertices], k=0;
            arr[k++] = j+1;
            while (p[j] != src)
            {
                arr[k++] = p[j]+1;
                p[j] = p[p[j]];
            }
            arr[k++] = p[j]+1;

            printf("[");
            for (int l=k-1; l>=0; l--)
                printf("%d ", arr[l]);
            printf("\b]   \t\tdistance = %d\n", d[i]);
        }
    }
}
void initArray(int adj[vertices][vertices])
{
    for (int i=0; i<vertices; i++)
        for (int j=0; j<vertices; j++)
            adj[i][j] = 0;
}

void setGraph(int adj[vertices][vertices])
{
    int s, d, w;
    initArray(adj);
    printf("EDGE Cost\n");
    for (int i=0; i<edges; i++)
    {
        scanf("%d %d %d", &s, &d, &w);
        adj[s-1][d-1] = w;
    }
}

int main(int argc, char const *argv[])
{
    printf("Enter no of vertices : ");
    scanf("%d", &vertices);
    printf("Enter no of edges : ");
    scanf("%d", &edges);

    int adj[vertices][vertices];
    setGraph(adj);

    int initVertex;
    printf("Enter initial vertex : ");
    scanf("%d", &initVertex);

    BellmanFord(adj, initVertex);

    return 0;
}