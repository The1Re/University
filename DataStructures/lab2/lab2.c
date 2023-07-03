#include <stdio.h>
#include <stdbool.h>

bool checkPrime(int n);

int main(void)
{
    int x;
    scanf("%d",&x);
    
    int adjust = 1, primeNumber = x;
    while (!checkPrime(x))
    {
        primeNumber = x - adjust;
        if (checkPrime(primeNumber)) break;

        primeNumber = x + adjust;
        if (checkPrime(primeNumber)) break;

        adjust++;
    }

    printf("%d",primeNumber);
    return 0;
}

bool checkPrime(int n)
{
    bool prime = true;
    if (n%2==0 && n!=2)
        prime = false;
    else{
        for (int i=3; i<n; i+=2){
            if (n%i==0){
                prime = false;
                break;
            }
        }
    }
    return prime;
}