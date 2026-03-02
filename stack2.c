#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void push( int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    if (nn == NULL)
    {
        printf("Heap Overflow");
    }
    if (top == NULL)
    {
        top = nn;
    }
    else{
        nn-> next = top;
        top = nn;
    }
}
void pop()
{
    if (top == NULL)
    {
        printf("\nstack underflow");
    }
    struct node *temp = top;
    printf("%d is the popped element \n", temp->data);
    top = temp->next;
    free(temp);
    //return top;
}
void isEmpty()
{
    if (top == NULL)
    {
        printf("\nstack is empty");
    }
    else
    {
        printf("\nNot empty");
    }
}
void display()
{
    if (top == NULL)
        printf("Stack is empty.\n");
    else
    {
        struct node *temp = top;
        while (temp != NULL)
        {
            printf("%d \t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int choice, x;
    do
    {
        printf("\nEnter 1 to push an element.");
        printf("\nEnter 2 to pop an element.");
        printf("\nEnter 3 to check whether the stack is empty.");
        printf("\nEnter 4 to display the stack.");
        printf("\nEnter 5 to exit.");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element to be pushed.");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\nExiting.");
            break;
        default:
            printf("\nInvalid input.");
        }
    } while (choice != 5);
    return 0;
}
