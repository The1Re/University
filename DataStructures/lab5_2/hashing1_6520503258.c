#include <stdio.h>
#include <stdbool.h>
#define HTsize 10

int hashArray[HTsize] = {0};

int hash(int k)
{
    return k%HTsize;
}

bool isArrayEmpty(int key)
{
    return (hashArray[key] == 0) ? true : false;
}

void setHash(int n, int key)
{
    hashArray[key] = n;
}

int main(void)
{
    int n, hash_key, i, old_key;
    do{
        printf("Enter number : ");
        scanf("%d", &n);

        if (n >= 1){
            old_key = hash_key = hash(n);
            printf("%d mod %d = %d\n", n, HTsize, hash_key);
            i = 0;
            while (true)
            {
                if (isArrayEmpty(hash_key)){
                    setHash(n, hash_key);
                    printf("  Put %d in H[%d]\n", n, hash_key);
                    break;
                }
                i++;
                hash_key = hash(old_key + i);
                printf("(%d+%d) mod %d = %d\n", old_key, i, HTsize, hash_key);
            }
        }

    }while(n>=1);
    
    for(i=0; i<HTsize; i++)
        printf("%d [%d]\n", i,hashArray[i]);
    return 0;
}