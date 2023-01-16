#include <stdio.h>
#include <string.h>

int chkAnagram(char a[],char b[])
{
    for(int i=0;i<strlen(a);i++)
    {
        for(int j=0;j<strlen(b);j++)
        {
            if(a[i]==b[j]) break;
            if(j==strlen(b)-1) return 0;
        } 
    }
    for(int i=0;i<strlen(b);i++)
    {
        for(int j=0;j<strlen(a);j++)
        {
            if(a[j]==b[i]) break;
            if(j==strlen(b)-1) return 0;
        }
    }
    return 1;
}

int main()
{
    char first[100],second[100];
    printf("Enter first string : "); scanf("%[^\n]s",first);
    fflush(stdin);
    printf("Enter second string : "); scanf("%[^\n]s",second);
    if(strlen(first)==strlen(second)){
        if(chkAnagram(first,second))
            printf("%s and %s is anagram",first,second);
        else    
            printf("%s and %s is not anagram",first,second);
    }else 
        printf("string length is not equal");

}