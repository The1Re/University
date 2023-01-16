#include <stdio.h>
#include <string.h>

void num7();

int main()
{
    char months[12][10] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int n;
    while(1)
    {
        printf("Enter number of month (1-12) ; ");
        scanf("%d",&n);
        if(n<1||n>12) break;
        printf("%s has %d days\n",months[n-1],days[n-1]);
    }
    printf("Invalid month number");
}   

void num7()
{
    char password[2][10]={"HQ1O","vX39"};
    char input[100];
    int j;
    for(int i=0;i<2;i++)
    {
        for(j=1;j<=3;j++)
        {
            printf("Enter PIN %d : ",i+1);
            scanf("%s",input);
            if(strcmp(input,password[i])){
                printf("Invalid PIN!\n");
                if(j==3){
                    printf("Too many attemps.\n");
                    j++;
                }
            }else{
                printf("PIN %d unlocked...\n",i+1);
                break;
            }
        }
        if(j>3) break;
        if(i==1) printf("Safe opened");
    }
}