#include <stdio.h>

int main()
{
    char pattern[5][5]=
    {
        {'o',' ','x',' ','o'},
        {' ','x',' ','x',' '},
        {'o',' ','x',' ','o'},
        {'o',' ','x',' ','o'}
    };

    for(int i=0;i<5;i++)
    {
        printf("%c\n",pattern[i][(i+2)%4]);
    }
}