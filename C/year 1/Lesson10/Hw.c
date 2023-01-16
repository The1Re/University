#include <stdio.h>
#include <string.h>

int main()
{
    char Shelf[3][5][30];
    FILE *data;
    data = fopen("book.txt","r");
    printf("=====List of Books in Library=====\n");
    for(int i=0;i<3;i++)
    {
        printf("Shelf's floor %d\n",i+1);
        for(int j=0;j<5;j++)
        {
            while(fgets(Shelf[i][j],20,data)!=NULL)
                printf("%s\t| ",Shelf[i][j]);
        }
        printf("\n");
    }
    fclose(data);
    return 0;
}