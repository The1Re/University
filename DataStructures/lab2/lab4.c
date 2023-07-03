#include <stdio.h>

void countDigit(int *count, int num);

int main(void)
{
    int n ,count = 0;
    scanf("%d",&n);
    for (int i=1; i<=n; i++){
        countDigit(&count, i);
    }
    printf("%d",count);
    return 0;
}

void countDigit(int *count, int num)
{
    while (num > 0)
    {
        *count += 1;
        num /= 10;
    }
}