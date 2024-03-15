//คเณศ อรชุนเลิศไมตรี 6520503258
#include <stdio.h>
#include <string.h>

const char Y[] = " akfdcmejf", X[] = " sfkpdcnmej";

void LCS(const char *X,const char *Y)
{
    int m = strlen(X);
    int n = strlen(Y);

    int k[m][n], c[m][n];

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i == 0 || j == 0){
                c[i][j] = 0;
                k[i][j] = 0;
            }else if (X[i] == Y[j]){
                c[i][j] = 1 + c[i-1][j-1];
                k[i][j] = 3;
            }else if (c[i-1][j] > c[i][j-1]){
                c[i][j] = c[i-1][j];
                k[i][j] = 1;
            }else{
                c[i][j] = c[i][j-1];
                k[i][j] = 2;
            }
        }
    }

    int i=strlen(X) - 1, j=strlen(Y) - 1;
    printf("Length of LCS is %d = (Reverse) ", c[m-1][n-1]);

    while (i >= 1 && j >= 1)
    {
        switch(k[i][j]){
            case 1: i--; break;
            case 2: j--; break;
            case 3:
                printf("%c ", X[i]);
                i--;
                j--;
                break;
        }
    }

    printf("\nArray c is\n");
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }

    printf("\nArray k is\n");
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            printf("%d ", k[i][j]);
        printf("\n");
    }
}

int main()
{
    LCS(X, Y);
    return 0;
}