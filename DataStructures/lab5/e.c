#include <stdio.h>
#include <string.h>
#define SIZE 5
typedef struct roman
{
    int num;
    char cha[3];
}RM;

int hash(char c)
{
    switch (c)
    {
        case 'I' : return 0;
        case 'V' : return 1;
        case 'X' : return 2;
        case 'L' : return 3;
        case 'C' : return 4;
    }
    return -1;
}

int main(void)
{
    int hash_table[SIZE] = {0};
    RM rm[] = {{100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    int n, length = sizeof(rm)/sizeof(RM), num;
    scanf("%d", &n);
    for (int data=1; data<=n && n<400; data++)
    {
        num = data;
        while (num!=0)
        {
            for (int i=0; i<length; i++)
            {
                if (num >= rm[i].num){
                    for (int j=0; j<strlen(rm[i].cha); j++)
                    {
                        hash_table[hash(rm[i].cha[j])] += num/rm[i].num;
                    }
                    num %= rm[i].num;
                    break;
                }
            }
            
        }
    }
    for (int i=0; i<SIZE; i++)
    {
        printf("%d ", hash_table[i]);
    }
    return 0;
}