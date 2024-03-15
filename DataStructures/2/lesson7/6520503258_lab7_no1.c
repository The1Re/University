//6520503258 Kanesh Orachunlertmitri 711
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int adj[MAX][MAX] = {
    {0, 10, 0, 5, 0},
    {0, 0, 1, 2, 0},
    {0, 0, 0, 0, 4},
    {0, 3, 9, 0, 2},
    {7, 0, 6, 0, 0}
};

int minDistance(int dist[], int status[])
{
    int min = INT_MAX, min_index;

    for (int v=0; v<MAX; v++)
    {
        if (status[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    }

    return min_index;
}

void Dijkstra(int graph[MAX][MAX], int source)
{
    int dist[MAX], parent[MAX], status[MAX] = {0};
    for (int v=0; v<MAX; v++)
        dist[v] = INT_MAX, parent[v] = 0; 

    source -= 1;
    dist[source] = 0;

    for (int count=0; count<MAX; count++)
    {
        int u = minDistance(dist, status);
        status[u] = 1;

        for (int v=0; v<MAX; v++)
        {
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }

    }

    for (int i=0; i<MAX; i++)
    {
        if (i != source)
            printf("%d -> %d : distance = %d\n", parent[i]+1, i+1, dist[i]);
    }
}

int main(int argc, char const *argv[])
{
    int source;
    printf("Enter initial vertex : ");
    scanf("%d", &source);

    Dijkstra(adj, source);

    return 0;
}