#include <stdio.h>
#include <stdlib.h>

typedef struct edge{
    int u, v, w;
}Edge;

typedef struct graph{
    int V, E;
    Edge *edge;
}Graph;

void BellmanFord(Graph *graph, int source)
{
    int d[graph->V], p[graph->V];
    for (int v=0; v<graph->V; v++)
        d[v] = INT_MAX, p[v] = -1;
    
    source -= 1;
    d[source] = 0;
    for (int i=0; i<graph->V; i++)
    {
        for (int e=0; e<graph->E; e++)
        {
            int u = graph->edge[e].u - 1, v = graph->edge[e].v - 1, w = graph->edge[e].w;
            if (d[u] + w < d[v])
                d[v] = d[u] + w, p[v] = u;
        }
    }

    for (int e=0; e<graph->E; e++)
    {
        int u = graph->edge[e].u - 1, v = graph->edge[e].v - 1, w = graph->edge[e].w;
        if (d[u] + w < d[v]){
            printf("Negative weight cycle detected!");
            return;
        }
    }

    for (int v=0; v<graph->V; v++)
    {
        int i = v;
        if (v != source)
        {
            int arr[graph->V], k=0;
            arr[k++] = i;
            while (p[i] != source)
            {
                arr[k++] = p[i];
                p[i] = p[p[i]];
            }
            arr[k++] = p[i];

            printf("[");
            for (int l=k-1; l>=0; l--)
                printf("%d ", arr[l] + 1);
            printf("\b]   \t\tdistance = %d\n", d[i]);
        }
    }
}

int main()
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    printf("enter no of vertices ");
    scanf("%d", &graph->V);
    printf("enter no of edges ");
    scanf("%d", &graph->E);
    graph->edge = (Edge *)malloc(graph->E * sizeof(Edge));

    printf("EDGE cost\n");
    for (int e=0; e<graph->E; e++)
        scanf("%d %d %d", &graph->edge[e].u, &graph->edge[e].v, &graph->edge[e].w);

    int source;
    printf("\nenter initial vertex : ");
    scanf("%d", &source);
    BellmanFord(graph, source);

    free(graph->edge);
    free(graph);

    return 0;
}