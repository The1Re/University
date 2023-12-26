#include <stdio.h>

int GCD(int a,int b)
{
    if (a==0)
        return b;
    return (a<b) ? GCD(b%a,a) : GCD(a%b,b);
} 

int main(void)
{
    int n,gcd,x;
    scanf("%d",&n);
    for (int i=0;i<n-1;i++)
    {
        scanf("%d",&x);
        if (i==0)
            scanf("%d",&gcd);
        gcd = GCD(x,gcd);
    }
    printf("%d",gcd);
    return 0;
}