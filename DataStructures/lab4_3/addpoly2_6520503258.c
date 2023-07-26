#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
struct polynode
{
	int coef;
	int exp;
	struct polynode *next;
};
struct polynode *head1 = NULL, *head2 = NULL, *head3 = NULL;


void displayPoly(struct polynode *head)
{
    int count = 0;
    struct polynode *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->coef != 0){
            if (count != 0 && ptr->coef >= 0){
                printf("+");
            }
            printf("%d", ptr->coef);
            if (ptr->exp != 0){
                printf("x");
                if (ptr->exp != 1){
                    printf("^%d", ptr->exp);
                }
            }
            count++;
        }
        ptr = ptr->next;
    }
    printf("\n");
}

int compareExp(int e1,int e2)
{
    if (e1 == e2)
        return 0;
    else if (e1 > e2)
        return 1;
    else
        return -1;
}

struct polynode* createNode(int e, int c)
{
    struct polynode *new_node;
    new_node= (struct polynode*) malloc(sizeof(struct polynode));
    new_node->exp =e;
    new_node->coef = c;
    new_node->next=NULL;
    return new_node;
}

void InsertNode(int exp, struct polynode **head, struct polynode *new_node)
{
    if (*head == NULL || exp > (*head)->exp){
        new_node->next = *head;
        *head = new_node;
    }else{
        struct polynode *ptr = *head;
        struct polynode *preptr = NULL;
        while (ptr != NULL)
        {
            if (exp > ptr->exp)
                break;
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = new_node;
        new_node->next = ptr;
    }
}

int main()
{
    struct polynode *p1 = NULL, *p2 = NULL, *p3 = NULL;
    struct polynode *new_node;

    int n=5,i,exp;
    const char LINE[] = "=====";
    srand((unsigned) time(NULL));

    printf("%sCreate 1st Polynomial%s\n", LINE, LINE);
    while(true)
    {
        printf("Enter exponential : ");
        scanf("%d", &exp);
        if (exp < 0)
            break;
        new_node = createNode(exp, rand()%30+1);
        InsertNode(exp, &head1, new_node);
    }
    printf("1st Polynomial: ");
    displayPoly(head1);

    printf("\n%sCreate 2nd Polynomial%s\n", LINE, LINE);
    while (true)
    {
        printf("Enter exponential : ");
        scanf("%d", &exp);
        if (exp < 0)
            break;
        new_node = createNode(exp, rand()%30+1);
        InsertNode(exp, &head2, new_node);
    }
    printf("2nd Polynomial: ");
    displayPoly(head2);

    p1=head1;
    p2=head2;
    p3=head3;

    while(p1!=NULL && p2!=NULL)
    {
        switch (compareExp(p1->exp,p2->exp))
        {
            case 0:
                if (head3 == NULL){
                    head3 = createNode(p1->exp, p1->coef + p2->coef);
                    p3 = head3;
                }
                else
                    p3->next = createNode(p1->exp, p1->coef + p2->coef);

                p1 = p1->next;
                p2 = p2->next;
                break;
            case 1:
                if (head3 == NULL){
                    head3 = createNode(p1->exp, p1->coef);
                    p3 = head3;
                }
                else
                    p3->next = createNode(p1->exp, p1->coef);

                p1 = p1->next;
                break;
            case -1:
                if (head3 == NULL){
                    head3 = createNode(p2->exp, p2->coef);
                    p3 = head3;
                }
                else
                    p3->next = createNode(p2->exp, p2->coef);

                p2 = p2->next;
                break;
        }
        if (p3->next != NULL)
            p3 = p3->next;
    }

    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
    }

    printf("\nAdded polynomial: ");
    displayPoly(head3);
    return 0;
}