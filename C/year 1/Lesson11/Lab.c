#include <stdio.h>

int Fact(int n)
{
    int sum=1;
    for(int i=1;i<=n;i++){
        sum*=i;
    }
    return sum;
}

int main()
{
    char select;
    int n,r;
    do{
        printf("======= Menu =======\n");
        printf("p or P : Permutation\n");
        printf("c or C : Combination\n");
        printf("q or Q : Exit program\n");
        printf("Select choice : "); scanf("%c",&select);
        if(select=='q'||select=='Q') 
            break;
        printf("\tEnter n : "); scanf("%d",&n);
        printf("\tEnter r : "); scanf("%d",&r);
        if(select=='p'||select=='P')
            printf("\tP(%d,%d) = %d\n",n,r,Fact(n)/Fact(n-r));
        else   
            printf("\tC(%d,%d) = %d\n",n,r,Fact(n)/Fact(n-r)/Fact(r));
        fflush(stdin);
    }while(1);
    return 0;
}