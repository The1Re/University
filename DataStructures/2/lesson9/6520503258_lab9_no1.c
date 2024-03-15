//นายคเณศ อรชุนเลิศไมตรี 6520503258 หมู่ 711
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct item{
    int id, value, weight;
}Item;

int max(int a, int b)
{
    return a > b ? a : b;
}

void Knapsack(Item item[], int n, int W)
{
    int K[n+1][W+1];
    printf("\n");

    for (int i=0; i<=n; i++)
    {
        for (int w=0; w<=W; w++)
        {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (item[i-1].weight <= w)
                K[i][w] = max(item[i-1].value + K[i-1][w - item[i-1].weight], K[i-1][w]);
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
            j -= item[i].weight;
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
            printf("%d",item[i].id);
        }
    }
    
    printf("\nMaximum value : %d", K[n][W]);
}

int main()
{
    int n, W;
    printf("Enter n, W : ");
    scanf("%d %d", &n, &W);

    Item item[n];

    for (int i=0; i<n; i++)
    {
        item[i].id = i+1;
        printf("Enter value & weight of item %d : ", i+1);
        scanf("%d %d", &item[i].value, &item[i].weight);
    }

    Knapsack(item, n, W);

    return 0;
}