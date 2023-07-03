#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool checkPrime(int n);
bool checkPalindrome(int n);

int main(void)
{
    int x;
    scanf("%d",&x);
    
    int adjust = 1, primeNumber = x;
    bool check = !(checkPrime(x) && checkPalindrome(x));
    while (check)
    {
        primeNumber = x - adjust;
        if (checkPrime(primeNumber) && checkPalindrome(primeNumber))
            break;
        primeNumber = x + adjust;
        if (checkPrime(primeNumber) && checkPalindrome(primeNumber))
            break;

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

bool checkPalindrome(int n)
{
    //Convert Number to String
    char msg[100];
    itoa(n, msg, 10);

    //check Palindrome
    int length = strlen(msg);
    for (int i=0; i<length/2; i++){
        if (msg[i] != msg[length-i-1])
            return false;
    }

    return true;
}