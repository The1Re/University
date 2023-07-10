#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n;
    bool prime = true;
    scanf("%d",&n);

    if (n%2==0 && n!=2)
        prime = false;
    else{
        for (int i=3; i<n; i+=2){
            if (n%i == 0){
                prime = false;
                break;
            }
        }
    }

    if (prime)
        printf("Yes");
    else
        printf("No");
    return 0;
}