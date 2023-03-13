//นายคเณศ อรชุนเลิศไมตรี 6520503258
#include <stdio.h>
#include <math.h>

int adding(int n,int m,int base)
{
    int sum=0,temp=0,i=0;
    while(!(n==0 && m==0 && temp==0))
    {   
        sum += (n%10+m%10+temp)%base*pow(10,i++);
        if((n%10+m%10+temp)>=base)
            temp = 1;
        else
            temp = 0;
        n/=10;
        m/=10;
    }
    return sum;
}

int main()
{
    int b,n,m;
    printf("Enter b [2-10] : ");
    scanf("%d",&b);
    printf("Enter n m : ");
    scanf("%d %d",&n,&m);

    printf("%d_%d + %d_%d = %d_%d",n,b,m,b,adding(n,m,b),b);

    return 0;
}