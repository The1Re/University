#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convert_inttostr(char *str,int n)
{
    char num[]="0123456789",chartemp;
    int temp;
    while(n>0)
    {
        temp = n%10;
        for(int i=0;i<strlen(num);i++)
        {
            if(temp == i){
                chartemp = num[i];
                strcat(str,&chartemp);
                break;
            }
        }
        n/=10;
    }
}

void factor(int x)
{
    int i=2;
    while(x!=1)
    {
        if(x%i==0){
            printf("%d",i);
            x/=i;
            if(x!=1)
                printf("x");
        }else{
            i++;
        }
    }
    printf("\n");
}

void factorinpower(int x)
{
    int i=2;
    char ans[20]="\0";
    while(x!=1)
    {
        if(x%i==0){
            convert_inttostr(ans,i);
            x/=i;
            if(x!=1)
                strcat(ans,".");
        }else{
            i++;
        }
    }
    printf("%s",ans);
    printf("\n");
}

int main()
{
    int a;
    printf("Input a : ");
    scanf("%d",&a);
    factor(a);
    factorinpower(a);

    return 0;
}