#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int start = 0,end = 32767,n=-1;
    srand(time(NULL));
    int ans = rand()%(end+1);
    while(n!=ans)
    {
        printf("Guesssing number between %d-%d : ",start,end);
        scanf("%d",&n);
        if(n<ans){
            printf("Too low, Tryagain\n");
            start = n;
        }
        else if(n>ans){
            printf("Too high, Tryagain\n");
            end = n;
        }
    }
    printf("Good, well done!");
}
