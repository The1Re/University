#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

int hash(char c)
{
    switch (c)
    {
        case 'I': return 0;
        case 'V': return 1;
        case 'X': return 2;
        case 'L': return 3;
        case 'C': return 4;
    }
    return -1;
}

int main(void)
{
    int n, hash_table[SIZE] = {0} ,data;
    int r[] = {100, 90, 50, 40, 10, 9, 5, 4, 1};
    char rm[][3] = {"C","XC","L","XL","X","IX","V","IV","I"};
    int length_r = sizeof(r)/sizeof(int);
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        data = i;
        for (int j=0; j<length_r && data != 0; j++)
        {
            if (j%2 != 0 && data == r[j]){
                for (int k=0; k<strlen(rm[j]); k++){
                    hash_table[hash(rm[j][k])]++;
                }
            }else{
                if (data >= r[j]){
                    hash_table[hash(rm[j][0])] += data/r[j];
                }
            }
            data %= r[j];
        }
    }
   for (int i=0; i<SIZE; i++)
   {
        printf("%d ", hash_table[i]);
   }
    return 0;
}
//r[]={100,50,10,5,4,1}
//rx[]={'C','L','X','V','IV','I'}