#include <stdio.h>

void num1();
void num2();
void num3();
void num4();

int main()
{
    //num1();
    // num2();
    // num3();
    num4();
}

void num1()
{
    int n,max=0;
    do{
        printf("Enter n : ");
        scanf("%d",&n);
        if(n<=0)break;
        if (n>max) max = n;
    }while(n>0);
    if(max>0)
        printf("Max = %d",max);
    else
        printf("No max positive integer found");
}

void num2()
{
    int n;
    do{
        printf("Enter n : ");
        scanf("%d",&n);
        if(n<0){
            printf("End of program");
            break;
        }
        printf("%d\n",n%10);
    }while(n>=0);
}

void num3()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=1;j--)
        {
            if(i>=j) printf("%d",j);
            else printf(" ");
        }
        printf("\n");
    }
}

void num4()
{
    int n,j;
    printf("Enter number n : ");
    scanf("%d",&n);
    for(int i=2;i<=5;i++)
    {
        for(int j=1;i*j<=n;j++)
        {
            printf("%d ",i*j);
        }
        printf("\n");
    }
}