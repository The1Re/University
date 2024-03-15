#include <stdio.h>

typedef struct item{
    int id, val, wt;
}Item;

int max(int a, int b)
{
    return a > b ? a : b;
}

int Knapsack(Item items[], int n, int W)
{
    int k[n+1][W+1];

    for (int i=0; i<=n; i++)
    {
        for (int w=0; w<=W; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            else if (w < items[i-1].wt)
                k[i][w] = k[i-1][w];
            else
                k[i][w] = max(items[i-1].val + k[i-1][w-items[i-1].wt], k[i-1][w]);
            printf("%3d  ", k[i][w]);
        }
        printf("\n");
    }

    printf("knapsack contain items : ");
    int i = n, j = W;
    while (i>0 && j>0)
    {
        if (k[i][j] == k[i-1][j]){
            //not selected
            i--;
        }else{
            i--;
            printf("%d,", items[i].id);
            j = j - items[i].wt;
        }
    }
    printf("\b\n");

    return k[n][W];
}

int main()
{
    int n, W;
    printf("Enter n, W : ");
    scanf("%d %d", &n, &W);
    Item items[n];
    for (int i=0; i<n; i++)
    {
        printf("Enter value & weight of item %d : ", items[i].id = i+1);
        scanf("%d %d", &items[i].val, &items[i].wt);
    }

    printf("Maximum value : %d", Knapsack(items, n, W));

    return 0;
}