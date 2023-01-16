#include <stdio.h>
#include <string.h>

void convert(char *msg)
{
    char num[]="0123456789";
    int f,n,i=1;
    f = strlen(msg);
    while(f>0)
    {
        n = f%10;
        for(int j=0;j<strlen(num);j++)
        {
            if(n==j){
                msg[i++]=num[j];
                msg[i]='\0';
                break;
            }
        }
        f/=10;
    }

}

int main()
{
    char msg[100],*p,temp[100];
    int f;
    printf("Enter the word : ");
    scanf("%s",msg);
    printf("\noutput = ");
    p = msg;
    strcpy(temp,p);
    while(*(p+1))
    {
        if(*p!=*(p+1)){
            p++;
            strcpy(temp,p);
            strcpy(p,"");
            convert(msg);
            printf("%s",msg);
            strcpy(msg,temp);
            p = msg;
        }
        p++;
    }
    convert(temp);
    printf("%s",temp);
}