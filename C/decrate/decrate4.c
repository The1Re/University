#include <stdio.h>
#include <stdbool.h>

bool isprime(int x)
{
    for(int i=2;i<x;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

int sol1_gcd(int a,int b)       //use loop
{
    int i;
    for(i=a;a%i!=0 || b%i!=0;i--);
    return i;
}

int sol1_lcm(int a,int b)
{
    int i;
    for(i=b;i%b!=0 || i%a!=0;i++);
    return i;
}

int sol2_gcd(int a,int b)       //use short divide
{
    int sum=1,i=2;
    while(i<=a)
    {
        if(a%i==0 && b%i==0){
            a/=i;
            b/=i;
            sum*=i;
        }else{
            i++;
        }
    }
    return sum;
}

int sol2_lcm(int a,int b)
{
    int sum=1,i=2;
    while(i<=a)
    {
        if(a%i==0 && b%i==0){
            a/=i;
            b/=i;
            sum*=i;
        }else{
            i++;
        }
    }
    return sum*a*b;
}

int sol3_gcd(int a,int b)          //use Euclidan algorithm
{
    if(a==0) return b;
    else
        return sol3_gcd(b%a,a);
}

int sol3_lcm(int a,int b)
{
    return (a*b)/sol3_gcd(a,b);
}

void swap_min_to_max(int *a,int *b)
{
    int temp;
    if(b<a){
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main()
{
    int a,b;
    printf("Input a,b : "); //can solve a>b and b>a
    scanf("%d %d",&a,&b);

    swap_min_to_max(&a,&b);

    printf("\nuse loop :\n");
    printf("gcd sol1 = %d\n",sol1_gcd(a,b));
    printf("lcm sol1 = %d\n",sol1_lcm(a,b));
    printf("\nuse short divide :\n");
    printf("gcd sol2 = %d\n",sol2_gcd(a,b));
    printf("lcm sol2 = %d\n",sol2_lcm(a,b));
    printf("\nuse Euclidean algorithm :\n");
    printf("gcd sol3 = %d\n",sol3_gcd(a,b));
    printf("lcm sol3 = %d\n\n",sol3_lcm(a,b));

    return 0;
}