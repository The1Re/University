#include <stdio.h>

void swapnum(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *num,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
            if(num[i]>num[j])
                swapnum(&num[i],&num[j]);
    }
}

int gcd(int a,int b)            //  a < b
{
    if(a==0) return b;
    return gcd(b%a,a);
}

int gcd_more2(int *num,int size)
{
    int buffer = num[0];
    for(int i=1;i<size;i++)
    {
        buffer = gcd(buffer,num[i]);
    }
    return buffer;
}

int lcm(int a,int b)
{
    return (a*b)/gcd(a,b);
}

int lcm_more2(int *num,int size)
{
    int buffer = 1;
    for(int i=0;i<size;i++)
    {
        buffer = lcm(buffer,num[i]);
    }
    return buffer;
}

int main()
{
    int n;
    printf("Enter n : ");
    scanf("%d",&n);

    int num[n];
    printf("Enter num : ");
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);

    sort(num,n);
    printf("Gcd = %d\n",gcd_more2(num,n));
    printf("Lcm = %d\n",lcm_more2(num,n));

    return 0;
}