#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BASE 10

//pos = 1 is digit position 1
int findDigit(int num, int pos)
{
    return (int)(num/pow(10,pos-1)) % 10;
}

void enqueue(int buffer[], int value)
{
    int i=0;
    while (buffer[i] != 0)
        i++;
    buffer[i] = value;
}

int main()
{
    int i, n=20;
    srand((unsigned) time(NULL));
    int num[n];

    printf("Number before sorting\n");
    for (i=0; i<n; i++)
    {
        num[i] = rand()%32767 + 1;
        printf("%d ", num[i]);
    }

    //Sorting with Radix sort
    for (int digitpos=1; digitpos<=5; digitpos++)
    {
        int buffer[BASE][20] = {0};
        for (int i=0 ;i<n; i++)
        {
            int digit = findDigit(num[i], digitpos);
            enqueue(buffer[digit], num[i]);
        }

        //ReArray
        int k=0;
        for (int a=0; a<BASE; a++)
        {
            for (int b=0; b<n; b++)
            {
                if (buffer[a][b] == 0)
                    break;
                num[k++] = buffer[a][b];
            }
        }
    }

    printf("\nNumber after sorting\n");
    for (int i=0; i<n; i++)
        printf("%d ", num[i]);
    return 0;
}
