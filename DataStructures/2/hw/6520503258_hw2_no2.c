//นายคเณศ อรชุนเลิศไมตรี 6520503258 หมู่ 711
#include <stdio.h>
#include <limits.h>

int MatrixChainOrder(int dims[], int n)
{
    int m[n][n];

    for (int i=1; i<n; i++)
        m[i][i] = 0;
    
    for (int len = 2; len<n; len++)
    {
        for (int i=1; i<n-len+1; i++)
        {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k=i; k<=j-1; k++)
            {
                int cost = m[i][k] + m[k+1][j] + dims[i-1]*dims[k]*dims[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j >= i)
                printf("%-8d", m[i][j]);
            else
                printf("\t");
        }
        printf("\n");
    }

    return m[1][n - 1];
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
    printf("Minimum number of multiplications = %d", MatrixChainOrder(d, n));
    return 0;
}