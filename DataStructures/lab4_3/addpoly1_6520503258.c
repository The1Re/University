#include <stdio.h>
#include<stdlib.h>
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
// Compare degree of exponential, return values are 0,1,-1
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

int main()
{
    struct polynode *p1 = NULL, *p2 = NULL, *p3 = NULL;
    struct polynode *new_node;

    int n=5,i;
    int a1[] ={6,2,3,8,0};
    int a2[] ={-3,18,0,0,23};
    int ex,co;

    //create list in decreasing order add at the head
    //similar to practice
    for(i=0;i<n;i++)
    {
        new_node = createNode(i, a1[i]);
        new_node->next = head1;
        head1 = new_node;
    }
    printf("1st Polynomial: ");
    displayPoly(head1);

    for(i=0;i<n;i++)
    {
        new_node = createNode(i, a2[i]);
        new_node->next = head2;
        head2 = new_node;
    }
    printf("2nd Polynomial: ");
    displayPoly(head2);

    //add poly
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
        }//end switch
        if (p3->next != NULL)
            p3 = p3->next;
        //create new node and add it in the resulted polynomial

    }//end while

    //check whether p1 is not null, Loop for creating new node and add it in the resulted polynomial
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
    }
    

   //check whether p2 is not null, Loop for creating new node and add it in the resulted polynomial
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
    }

    // Display resultant List
    printf("\nAdded polynomial: ");
    displayPoly(head3);

    //free memory
    return 0;
}//end main