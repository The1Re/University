#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct contact
{
    char name[6];
    char phone[11];
    struct contact *next;
};

struct contact* createNode(char name[], char number[])
{
    struct contact *new_node;
    new_node = (struct contact*) malloc(sizeof(struct contact));
    //assign value for newnode
    strcpy(new_node->name, name);
    strcpy(new_node->phone, number);
    new_node->next = NULL;
    return new_node;
}

int hash2(char key[], int n)
{
    int i,j=0;
    long long int hashVal = 0;
    for (i=strlen(key)-1; i>=0; i--)
    {
        hashVal += key[i] *pow(32.0,j);
        j++;
    }
    return hashVal%n;
}


void searchList(struct contact* head, char name[])
{
    //fill-in your code for searching value in hash table
    struct contact *ptr = head;
    while (ptr != NULL)
    {
        if (!strcmp(ptr->name, name)){
            printf("%s 's number is %s\n", name, ptr->phone);
            return ;
        }
        ptr = ptr->next;
    }
    printf("Not found %s in the contact list\n", name);
    return ;
}

int main()
{
    int i,n,m=13,k;
    struct contact *hash_table[m];
    struct contact *new_node;

    struct contact *ptr=NULL,*preptr=NULL;

    char name[6];
    char number[11];

    //initialize a chained hash table
    for(i=0;i<m;i++)
        hash_table[i]=NULL;

    do
    {
        printf("=== Contact List ===\n");
        printf("1. Add new contact\n");
        printf("2. Remove contact\n");
        printf("3. Search contact\n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&n);

        if(n==1)
        {
            printf("Enter name:");
            scanf("%s",name);
            printf("Enter phone number:");
            scanf("%s",number);

            //call hash function for string
            k = hash2(name, m);

            printf("key:%s has hashkey=%d\n",name,k);

            //insert node into Linkedlist at head
            struct contact *new_node = createNode(name, number);
            new_node->next = hash_table[k];
            hash_table[k] = new_node;


        }
        else if(n==2)
        {
            printf("Enter name:");
            scanf("%s",name);

            //fill-in your code for deleting node with the specific name
            k = hash2(name, m);
            if (!strcmp(hash_table[k]->name, name)){
                hash_table[k] = hash_table[k]->next;
                free(ptr);
            }else{
                struct contact *preptr = hash_table[k];
                struct contact *ptr = hash_table[k]->next;
                while (ptr->next != NULL)
                {
                    if (!strcmp(ptr->name, name))
                        break;
                    preptr = ptr;
                    ptr = ptr->next;
                }
                preptr->next = ptr->next;
                free(ptr);
            }

        }
        else if(n==3)  //search
        {
            printf("Enter name:");
            scanf("%s",name);

            //call hash function for string
            k = hash2(name, m);

            searchList(hash_table[k],name);

        }

    }while(n!=4);



    //free memory


    return 0;
}
