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
                printf("x");
        }else{
            i++;
        }
    }
}

int main()
{
    int a;
    printf("Input a : ");
    scanf("%d",&a);
    factor(a);

    return 0;
}