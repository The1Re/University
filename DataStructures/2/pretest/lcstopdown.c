#include <stdio.h>
#include <string.h>

const char X[] = "AGGTAB", Y[] = "GXTXAYB";
// const char X[] = "akfdcmejf", Y[] = "sfkpdcnmej";
int k[6][7], c[6][7];


int LCS_TOPDOWN(int i, int j)
{
    if (X[i] == '\0' || Y[j] == '\0')
        return 0;
    else if (X[i] == Y[j]){
        int temp = 1 + LCS_TOPDOWN(i+1, j+1);
        k[i][j] = 3;
        c[i][j] = temp;
        return temp;
    }else{
        int a = LCS_TOPDOWN(i+1, j);
        int b = LCS_TOPDOWN(i, j+1);
        if ( a > b ){
            k[i][j] = 1;
            c[i][j] = a;
            return a;
        }else{
            k[i][j] = 2;
            c[i][j] = b;
            return b;
        }
    }
}

int main()
{
    int i=0, j=0;
    printf("Length of LCS is %d = ", LCS_TOPDOWN(i, j));
    while (i < strlen(X) && j < strlen(Y))
    {
        switch (k[i][j])
        {
            case 1:
                i++;
                break;
            case 2:
                j++;
                break;
            case 3:
                printf("%c ", X[i]);
                i++;
                j++;
                break;
        }
    }



    return 0;
}