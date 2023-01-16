#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char Hex[]="0123456789ABCDEF";

int power(int n,int s)
{
    int sum=1;
    for(int i=1;i<=s;i++)
        sum*=n;
    return sum;
}

bool isHexa(char *word)
{
    for(int i=0;i<strlen(word);i++)
    {
        for(int j=0;j<strlen(Hex);j++)
        {
            if(toupper(word[i])==Hex[j]) break;
            if(j==strlen(Hex)-1) return false;
        }
    }
    return true;
}

int Hex2Dec(char *word)
{
    int sum=0;
    for(int i=0;i<strlen(word);i++)
    {
        for(int j=0;j<strlen(Hex);j++)
        {
            if(toupper(word[i])==Hex[j])
                sum+=j*power(16,strlen(word)-i-1);
        }
    }
    return sum;
}

int main()
{
    char word[8];
    printf("Enter word : ");
    scanf("%s",word);
    if(isHexa(word))
        printf("%d",Hex2Dec(word));
    else   
        printf("Not a Hexa number");
    return 0;
}