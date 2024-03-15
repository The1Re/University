//6520503258 คเณศ อรชุนเลิศไมตรี หมู่ 711
#include <stdio.h>
#define MAX 7

int graph[MAX][MAX] = {
    {0, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 0, 1, 1, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}
};

void approx_vertex_cover(int G[MAX][MAX])
{
    int size = 0;
    int visited[MAX] = {0};
    for (int i=0; i<MAX; i++)
    {
        if (!visited[i]){
            for (int j=0; j<MAX; j++)
            {
                if (graph[i][j] && !visited[j]){
                    visited[i] = visited[j] = 1;
                    size += 2;
                    break;
                }
            }
        }
    }

    for (int i=0; i<MAX; i++)
    {
        if (visited[i])
            printf("%d ", i);
    }
    printf("\nsize = %d", size);
}

int main()
{
    approx_vertex_cover(graph);
    
    return 0;
}