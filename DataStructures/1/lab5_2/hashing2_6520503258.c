#include <stdio.h>
#include <stdbool.h>
#define HTsize 10

int hashArray[HTsize] = {0};

int hash(int k)
{
    return k%HTsize;
}

// 1=>Empty  -1=>Duplicate  0=>Not Empty 
int ArrayStatus(int n, int key)
{
    if (hashArray[key] == 0)
        return 1;
    else if (hashArray[key] == n)
        return -1;
    else
        return 0;
}

void setHash(int n, int key)
{
    hashArray[key] = n;
}

int main(void)
{
    int n, i, hash_key, old_key, countHT = 0;
    bool status;
    do{
        printf("Enter number : ");
        scanf("%d", &n);

        if (countHT == HTsize){
            printf("Hash Table is full!\n");
            break;
        }

        if (n >= 1){
            old_key = hash_key = hash(n);
            printf("%d mod %d = %d\n", n, HTsize, hash_key);
            i = 0; status = false;
            while (true)
            {
                switch (ArrayStatus(n, hash_key))
                {
                    case 1 : //Empty
                        setHash(n, hash_key);
                        printf("  Put %d in H[%d]\n", n, hash_key);
                        countHT++;
                        status = true;
                        break;
                    case -1 : //Duplicate number
                        printf("Duplicate number!\n");
                        status = true;
                        break;
                    case 0 : //Not Empty
                        i++;
                        hash_key = hash(old_key + i*i);
                        printf("(%d+%d) mod %d = %d\n", old_key, i*i, HTsize, hash_key);
                        break;
                }

                if (status)
                    break;
            }
        }

    }while(n>=1);
    
    for(i=0; i<HTsize; i++)
        printf("%d [%d]\n", i,hashArray[i]);
    return 0;
}