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
}