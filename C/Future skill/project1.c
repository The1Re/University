#include <stdio.h>

double power(int n,int p){
    if(p==0)
        return 1;
    return n*power(n,p-1);
}

int main(){
    int n;
    
    printf("Number to be calculated : ");
    scanf("%d",&n);

    printf("------------------------------\n");
    printf("-CLASS PROJECT EXAMPLE RESULT-\n");
    printf("------------------------------\n");
    for(int i=1;i<=10;i++)
        printf("%d ^ %d = %.0lf\n",n,i,power(n,i));

    return 0;
}