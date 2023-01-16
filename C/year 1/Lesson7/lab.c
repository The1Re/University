#include <stdio.h>

void num1()
{
    int n,i=2;
    printf("Enter number : ");
    scanf("%d",&n);
    while(n!=1)
    {
        if(n%i==0){
            if(n/i==1)break;
            printf("%d * ",i);
            n/=i;
        }
        else 
            i++;
    }
    printf("%d",i);
}

void num2()
{
    int n,sum=0;
    printf("Enter number : ");
    scanf("%d",&n);
    while(n>0)
    {
        printf("%d",n%10);
        sum+=n%10;
        if(n/10>0)
            printf(" + ");
        n/=10;
    }
    printf(" = %d",sum);
}

void num3()
{
    int n,sum=0;
    do{
        printf("Enter number : ");
        scanf("%d",&n);
        if(n<0)break;
        sum=0;
        while(n>0)
        {
            printf("%d",n%10);
            sum+=n%10;
            if(n/10>0)
                printf(" + ");
            n/=10;
        }
        printf(" = %d\n",sum);
    }while(1);
    printf("End of program");
}

void num4()
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=5;j++)
        {
            printf("%d",i);
        }
        printf("\n");
    }
}

void num5()
{
    for(int i=1;i<=4;i++)
    {
        for(int j=i;j>=1;j--)
            printf("%d",j);
        printf("\n");
    }
}

void num6()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n*2-1;j++)
        {
            if(j>n-i&&j<n+i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void num7()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
            printf(" ");
        for(int j=1;j<=i;j++)
            printf("%d",j);
        for(int j=1;j<i;j++)
            printf("%d",j);
        printf("\n");
    }
}

void num8()
{
    int start;
    printf("Enter started day : ");
    scanf("%d",&start);
    printf("\n\n");
    printf("Su\tMo\tTu\tWe\tTh\tFr\tSa\n");
    
    for(int i=1;i<start;i++)
        printf("\t");

    for(int i=1;i<=31;i++)
    {
        printf("%2d\t",i);
        if((i+start-1)%7==0)
            printf("\n");
    }
}

int main()
{
    //num1();
    //num2();
    // num3();
    // num4();
    // num5();
    //num6();
    // num7();
    num8();
}

