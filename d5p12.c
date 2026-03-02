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
        *head = NN;
        NN->next = *head;
        return;
    }
    struct node *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = NN;
    NN->next = *head;
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    struct node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to head)\n");
}
void insert(struct node **head, int ele, int pos)
{
    struct node *NN = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head;
    NN->data = ele;
    NN->next = NULL;
    if (pos < 1)
    {
        printf("Invalid position\n");
        free(NN);
        return;
    }
    if (*head == NULL && pos == 1)
    {
        *head = NN;
        NN->next = *head;
        return;
    }
    else if (*head == NULL && pos != 1)
    {
        printf("Out of bound\n");
        free(NN);
        return;
    }
    if (pos == 1)
    {
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = NN;
        NN->next = *head;
        *head = NN;
        return;
    }
    int k = 1;
    while (temp->next != *head && k < pos - 1)
    {
        temp = temp->next;
        k++;
    }
    if (k != pos - 1)
    {
        printf("Out of bound\n");
        free(NN);
        return;
    }
    NN->next = temp->next;
    temp->next = NN;
}
void delete(struct node **head, int pos)
{   
    struct node *temp = *head;
    if (*head == NULL)
    {
        printf("The list is empty \n");
        return;
    }
    if (pos < 1)
    {
        printf("Invalid position \n");
        return;
    }
    else if( pos == 1)
    {
         while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp -> next = temp -> next -> next;
        *head = temp -> next;
        printf("The element %d has been deleted from the position 1", temp -> data);
        free(temp);
        return ;
    }
    int k=1;
    for ( k=1 ; temp -> next != * head && pos < k-1; k++) 
    {
        temp = temp -> next;
    }
    temp -> next = temp -> next -> next;
    printf("The element: %d has been deleted from the position: %d",temp -> next -> data, pos);
    free(temp);
}
//void reverse(struct node * head)
////{
//    struct node * temp = head;
//    if ( temp != head){
//        return;
//    }
//    reverse(temp);
//    printf("%d ->", temp -> data);
//}
int main()
{
    struct node *head = NULL;
    int n, k;
    printf("Enter the number of nodes to enter:\t");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value to insert:\t");
        scanf("%d", &k);
        create(&head, k);
    }
    display(head);
    int ele, pos;
    printf("Enter the element to insert: And in which position:\n");
    scanf("%d%d", &ele, &pos);
    insert(&head, ele, pos);
    display(head);
    //reverse(head);
    printf("To delete \t");
    delete(&head, pos);
    display(head);
    return 0;
}
