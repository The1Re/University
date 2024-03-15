#include <stdio.h>
#include <limits.h>

int MatrixChainMultiplication(int d[], int n)
{
    int C[n][n], K[n][n];

    for (int i=1; i<n; i++)
        C[i][i] = 0, K[i][i] = 0;

    for (int len=2; len<n; len++)
    {
        for (int i=1; i<n-len+1; i++)
        {
            int j = i + len - 1;
            C[i][j] = INT_MAX;
            for (int k=i; k<=j-1; k++)
            {
                int cost = C[i][k] + C[k+1][j] + d[i-1]*d[k]*d[j];
                if (cost < C[i][j]){
                    C[i][j] = cost;
                    K[i][j] = k;
                }
            }
        }
    }

    printf("This is C matrix : \n");
    for (int i=1; i<n; i++)
    {
        for (int j=1; j<n; j++)
        {
            if (j >= i)
                printf("%-8d", C[i][j]);
            else
                printf("\t");
        }
        printf("\n");
    }

    return C[1][n-1];
}

int main()
{
    int n;
    printf("Please input number of d : ");
    scanf("%d", &n);
    int d[n];
    for (int i=0; i<n; i++)
    {
        printf("Enter d%d : ", i);
        scanf("%d", &d[i]);
    }

    printf("Minimum number of multiplications = %d", MatrixChainMultiplication(d, n));
    return 0;
}