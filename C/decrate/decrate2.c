#include <stdio.h>

void factor(int x)
{
    int i=2;
    while(x!=1)
    {
        if(x%i==0){
            printf("%d",i);
            x/=i;
            if(x!=1)
                printf(" x ");
        }else{
            i++;
        }
    }
    printf("\n");
}

void factorinpower(int x)
{
    int i=2;
    int powcount=0;

    while(x!=1)
    {
        if(x%i==0){
            if(powcount == 0)
                printf("%d^",i);
            powcount++;
            x/=i;
            if(x%i!=0){
                printf("%d",powcount);
                if(x!=1)
                    printf(" x ");
            }
        }else{
            powcount=0;
            i++;
        }
    }

    printf("\n");
}

int main()
{
    int a;
    printf("Input a : ");
    scanf("%d",&a);
    
    factor(a);
    factorinpower(a);

    return 0;
}