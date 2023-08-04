#include <stdio.h>
#define HTsize 10

int hashArray[HTsize] = {0};

int h(int k)
{
    return k%HTsize;
}

void setHash(int n)
{
    int index;
    index = h(n);
    if (hashArray[index] == 0){
        hashArray[index] = n;
    }else{
        printf("Cannot insert, H[%d] is not empty\n", index);
    }
}

int main(void)
{
    int n,h;
    do{
        printf("Enter number : ");
        scanf("%d", &n);

        if (n >= 1)
            setHash(n);
    }while(n>=1);
    
    for(h=0; h<HTsize; h++)
        printf("%d [%d]\n", h,hashArray[h]);
    return 0;
}