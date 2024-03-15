#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    int u, v;
}Edge;

typedef struct Graph
{
    int V, E;
    Edge *edge;
}Graph;

int main()
{
    const int n = 7;
    int graph[][n] = {
        {0, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 1, 1, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->V = 7;
    g->E = 7;
    g->edge = (Edge *)malloc(g->E * sizeof(Edge));

    g->edge[0].u = 0;
    g->edge[0].v = 1;
    return 0;
}