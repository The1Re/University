#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void maxdiff1(int x[], int n);
void maxdiff2(int x[], int n);

int main(void)
{
    int n=3200;
    double start_time, end_time;

    printf("Algorithm 1 :\n");
    while (n < 250000)
    {
        //init array
        int arr[n];
        for (int i=0; i<n; i++){
            arr[i] = rand();
        }

        //start test function
        printf("n = %d\n",n);
        start_time = clock();
        maxdiff1(arr,n);
        end_time = clock();
        printf("\t=> %lf s\n\n",(end_time - start_time)/CLOCKS_PER_SEC);

        n *= 2;
    }

    n = 3200;
    printf("Algorithm 2 :\n");
    while (n < 250000)
    {
        //init array
        int arr[n];
        for (int i=0; i<n; i++){
            arr[i] = rand();
        }

        //start test function
        printf("n = %d\n",n);
        start_time = clock();
        maxdiff2(arr,n);
        end_time = clock();
        printf("\t=> %lf s\n\n",(end_time - start_time)/CLOCKS_PER_SEC);

        n *= 2;
    }
    printf("End Program...");
    return 0;
}

void maxdiff1(int x[], int n)
{
    int i, j, diff, max=0;

    for (i=0; i<n-1; i++){
        for (j=i+1; j<n; j++){
            diff = abs(x[i]-x[j]);
            if (diff > max){
                max = diff;
            }
        }
    }
}

void maxdiff2(int x[], int n)
{
    int i, max, min, maxdiff;
    max = x[0];
    min = x[0];

    for (i=1; i<n; i++){
        if (x[i] > max) max = x[i];
        if (x[i] < min) min = x[i];
    }
    maxdiff = max-min;
}