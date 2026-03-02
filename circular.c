#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void create(struct node **head, int value)
{
    struct node *NN = (struct node *)malloc(sizeof(struct node));
    NN->data = value;
    if (*head == NULL)
    {
        NN->next = NN;
        *head = NN;
        return;
    }
    struct node *temp = *head;
    while (temp != *head)
    {
        temp = temp->next;
    }
    temp->next = NN;
    NN->next = *head;
}
void display( struct node * head)
{
    if ( head == NULL)
    {
        printf("The list is empty");
        return;
    }
    struct node * temp = head;
    while ( temp != head)
    {
        printf("%d", temp -> data);
        temp = temp -> next;
    }
    printf("(Back to head)\n");
}
int main()
{
    int i,n;
    printf("Enter the number of nodes to enter:\t");
    scanf("%d", &n);
    for ( i = 0; i< n; i ++)
    {   
        struct node * NN = (struct node *)malloc ( sizeof(struct node));
        int k;
        printf("enter the value to insert;\t");
        scanf("%d", &k);
        create(&NN,k);
        free(NN);
    }
    
}