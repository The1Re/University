#include <stdio.h>

int main(void)
{
    int found = 0, row, col, n, item;
    int mat[100][100];

    scanf("%d",&item);

    for (row=0;row<n;row++){
        for (col=0;col<n;col++){
            if (mat[row][col] == item)
                found = 1;
        }
    }

    if (found)
        printf("item found\n");
    else
        printf("item not found\n");
    return 0;
}