#include <stdio.h>
#include <string.h>

void LCS_BottomUp(char *X, char *Y, int lenX, int lenY)
{ 
    int c[lenX][lenY], k[lenX][lenY];

    for (int i=0; i<lenX; i++)
    {
        for (int j=0; j<lenY; j++)
        {
            if (i==0 || j==0)
                c[i][j] = k[i][j] = 0;
            else if (X[i] == Y[j]){
                c[i][j] = 1 + c[i-1][j-1];
                k[i][j] = 3;
            }else{
                int a = c[i-1][j];
                int b = c[i][j-1];
                if ( a > b ){
                    c[i][j] = a;
                    k[i][j] = 1;
                }else{
                    c[i][j] = b;
                    k[i][j] = 2;
                }
            }
        }
    }

    int i = lenX - 1, j = lenY - 1;
    printf("Length of LCS is %d = ", c[i][j]);
    while (i > 0 && j > 0)
    {
        switch (k[i][j])
        {
            case 1 : i--; break;
            case 2 : j--; break;
            case 3 : 
                printf("%c ", X[i]);
                i--;
                j--;
        }
    }

}

int main()
{
    char X[] = " AGGTAB", Y[] = " GXTXAYB";
    int lenX = strlen(X), lenY = strlen(Y);

    
    LCS_BottomUp(X, Y, lenX, lenY);
    

    
    return 0;
}