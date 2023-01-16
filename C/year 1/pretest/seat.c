#include <stdio.h>

int main()
{
    int choice,row,col;
    char seat[3][5];

    for(int i=0;i<3;i++)
        for(int j=0;j<5;j++)
            seat[i][j]='-';

    do{
        printf("Main Menu\n1.Reserve seat\n2.Show all seats\n3.Exit\n");
        printf("Input 1 or 2 or 3 : "); scanf("%d",&choice);
        if(choice==3)break;
        else if(choice==1){
            while(1)
            {
                printf("\tSelect row : "); scanf("%d",&row);
                printf("\tSelect seat number : "); scanf("%d",&col);
                if(col<1||col>5||seat[row-1][col-1]=='*'){
                    printf("\tInvalid seat!Select again\n");
                    continue;
                }
                seat[row-1][col-1] = '*';
                printf("\tReservation OK\n");
                break;
            }
        }else if(choice==2){
            for(int i=0;i<3;i++)
            {
                printf(" ");
                for(int j=0;j<5;j++)
                    printf("%c ",seat[i][j]);
                printf("\n");
            }
        }else  
            printf("Invaild input!\n");
    }while(1);
    printf("Good bye!!");
}