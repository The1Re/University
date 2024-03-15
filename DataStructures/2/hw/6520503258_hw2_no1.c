#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define length(arr) sizeof(arr)/sizeof(arr[0])
const int W = 8;

typedef struct item{
    int id, val, wt;
}Item;

int max(int a, int b)
{
    return a > b ? a : b;
}

void Knapsack(Item items[], int n)
{
    int K[n+1][n+1];
    
    for (int i=0; i<=n; i++)
    {
        for (int w=0; w<=W; w++)
        {
            int j = i-1;
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (items[j].wt <= w)
                K[i][w] = max(items[j].val + K[j][w - items[j].wt], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
            printf("%3d ", K[i][w]);
        }
        printf("\n");
    }

    printf("\nknapsack contain items : ");
    int i=n, j=W, x[n], k;
    memset(x, 0, sizeof(x));
    while (i>0 && j>0)
    {
        if (K[i][j] == K[i-1][j]){
            i--;
            x[i] = 0;
        }else{
            i--;
            x[i] = 1;
            j -= items[i].wt;
        }
    }

    bool check = false;
    for (int i=0; i<n; i++)
    {
        if (x[i]) {
            if (!check)
                check = true;
            else
                printf(",");
            printf("%d",items[i].id);
        }
    }
    
    printf("\nMaximum value : %d", K[n][W]);
}

int main(void)
{
    Item items[] = {
        {1, 1, 2},
        {2, 2, 4},
        {3, 5, 3},
        {4, 6, 5}
    };

    Knapsack(items, length(items));

    return 0;
}