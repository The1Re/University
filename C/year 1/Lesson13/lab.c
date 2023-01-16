#include <stdio.h>

void Digit(int n,int *k)
{
    while(n>0)
    {
        k[n%10]++;
        n/=10;
    }
}

int main()
{
    int n,m,k[10]={0};
    printf("n=");scanf("%d",&n);
    printf("m=");scanf("%d",&m);
    while(n<=m)
        digit(n++,k);
    for(int i=0;i<=9;i++)
        printf("%d %d\n",i,k[i]);
}