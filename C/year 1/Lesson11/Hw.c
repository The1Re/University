#include <stdio.h>

int GCD(int a,int b)
{
    int i,sum=1;
    for(i=2;i<=a&&i<=b;i++)
    {
        if(a%i==0&&b%i==0){
            sum*=i;
            a/=i;
            b/=i;
            i--;
        }
    }
    return sum;
}

int LCM(int a,int b)
{
     return (a*b)/GCD(a,b);
}

int main()
{
    int n;
    int G=1,L=1;
    printf("Enter n : ");
    scanf("%d",&n);
    int num[n];
    printf("List of number\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        if(i>=1){
            G = GCD(num[i],G);
            L = LCM(num[i],L);
        }else{
            G = num[0];
            L = num[0];
        }
    }
    printf("GCD = %d\n",G);
    printf("LCM = %d\n",L);
    return 0;
}