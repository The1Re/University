//นายคเณศ อรชุนเลิศไมตรี 6520503258
#include <stdio.h>

void factor(int x)
{
    int i=2;
    printf("%d=",x);

    while(x!=1)
    {
        if(x%i==0){
            printf("%d",i);
            x/=i;
            if(x!=1)
                printf("*");
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
    printf("%d=",x);

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
                    printf("*");
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
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    
    factor(n);
    factorinpower(n);

    return 0;
}