//6520503258 คเณศ อรชุนเลิศไมตรี หมู่ 711
#include <stdio.h>
#include <stdbool.h>
#define MAX 8

int adj[MAX][MAX] = {
	{0, 1, 0, 1, 1, 1, 0, 0},
	{1, 0, 0, 0, 0, 0, 1, 1},
	{0, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0}
};
int temp[MAX];

void dfs(int const adj[MAX][MAX], int source)
{
	int stack[MAX] = {0}, top = -1, visited[MAX] = {0}, k=0;

	stack[++top] = source;
	visited[source] = 1;

	while (top != -1)
	{
		int index = stack[top--];
		temp[k++] = index;
		visited[index] = 3;

		for (int col=0; col<MAX; col++)
		{
			if (adj[index][col] && visited[col] == 0){
				stack[++top] = col;
				visited[col] = 1;
			}
		}
	}
}

void reverse(int adj[MAX][MAX])
{
	for (int i=0; i<MAX; i++)
		for (int j=0; j<MAX; j++)
			adj[i][j] = adj[j][i];
}

void printArr(int arr[MAX][MAX])
{
	printf("Array is : \n");
	for (int i=0; i<MAX; i++){
		for (int j=0; j<MAX; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}

void strongConnected(int adj[MAX][MAX])
{
	dfs(adj, 0);
	reverse(adj);
	
	int stack[MAX] = {0}, top = -1, visited[MAX] = {0}, k=MAX, j=1, source;

	source = 0;
	while (k >= 0){
		if (visited[source] == 0){
			visited[source] = 1;
			stack[++top] = source;

			printf("C%d = { ", j);
			while (top != -1)
			{
				int index = stack[top--];
				printf("%d ", index);
				visited[index] = 3;

				for (int col=0; col<MAX; col++)
				{
					if (adj[index][col] && visited[col] == 0){
						stack[++top] = col;
						visited[col] = 1;
					}
				}
			}
			printf("}\n");
			j++;
		}
		source = temp[--k];
	}
}


int main(int argc, char const *argv[])
{
	strongConnected(adj);
	return 0;
}