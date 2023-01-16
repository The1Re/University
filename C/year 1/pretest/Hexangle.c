#include <stdio.h>

int main()
{
    int n;
    char c;
    printf("Enter base : ");
    scanf("%d",&n);
    fflush(stdin);
    printf("Enter char : ");
    scanf("%c",&c);
    for(int i=1;i<=2*n-3;i++)
    {
        if(i<=n-1){
            for(int j=i;j<n-1;j++)
                printf(" ");
            if(i==1){
                for(int j=1;j<=n;j++)
                    printf("o");
            }else{
                for(int j=1;j<=n+2*(i-1);j++)
                {
                    if(j==1||j==n+2*(i-1))
                        printf("o");
                    else{
                        printf("%c",c);
                    }
                }
            }
        }else{
            for(int j=1;j<=i-n+1;j++)
                printf(" ");
            if(i==2*n-3){
                for(int j=1;j<=n;j++)
                    printf("o");
            }else{
                for(int j=n+2*(n-2)-2*(i-n+1);j>=1;j--)
                {
                    if(j==1||j==n+2*(n-2)-2*(i-n+1))
                        printf("o");
                    else{
                        printf("%c",c);
                    }
                }
            }
        }
        printf("\n");
    }
}