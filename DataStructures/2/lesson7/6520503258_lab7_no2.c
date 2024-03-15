//6520503258 Kanesh Orachunlertmitri 711
#include <stdio.h>
#include <stdlib.h>
#define MAX 7

int adj[MAX][MAX] = {
    {0, 1, 3, 0, 0, 0, 0},
    {1, 0, 0, 2, 4, 0, 0},
    {3, 0, 0, 2, 3, 0, 0},
    {0, 2, 2, 0, 7, 1, 0},
    {0, 4, 0, 7, 0, 5, 3},
    {0, 0, 3, 1, 5, 0, 2},
    {0, 0, 0, 0, 3, 2, 0}
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

void Prim(int graph[MAX][MAX], int source)
{
    int dist[MAX], parent[MAX], status[MAX] = {0}, mstCost = 0;
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
            if (graph[u][v] && status[v] == 0 && graph[u][v] < dist[v]){
                dist[v] = graph[u][v]; //Dijkstra dist[v] + graph
                parent[v] = u;
            }
        }

    }

    for (int i=1; i<MAX; i++)
    {
        if (i != source){
            printf("%d -> %d : distance = %d\n", parent[i]+1, i+1, dist[i]);
            mstCost += dist[i];
        }
    }
    printf("MST Cost = %d\n", mstCost);
}

int main(int argc, char const *argv[])
{
    int source;
    printf("Enter initial vertex : ");
    scanf("%d", &source);

    Prim(adj, source);

    return 0;
}