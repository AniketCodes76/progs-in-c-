#include <stdio.h>
#define N 5
int stack[N];
int top = -1;
void push(int x)
{
    if (top == (N - 1))
        printf("Stack overflow.\n");
    else
    {
        stack[++top] = x;
        printf("%d pusdhes to stack.\n", x);
    }
}
void pop()
{
    if (top == -1)
        printf("Stack underflow.\n");
    else
    {
        printf("%d popped from stack.\n", stack[top--]);
    }
}
void isempty()
{
    if (top == -1)
        printf("\nStack is empty");
    else
        printf("\nStack is not empty.");
}
void isfull()
{
    if (top == (N - 1))
        printf("\nStack is full.");
    else
        printf("\nStack is not full.");
}
void display()
{
    if (top == -1)
        printf("\nStack is empty");
    else
    {
        for (int i = top; i >= 0; i--)
            printf("%d\t", stack[i]);
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
        printf("\nEnter 4 to check whether the stack is full.");
        printf("\nEnter 5 to display the stack.");
        printf("\nEnter 6 to exit.");
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
            isempty();
            break;
        case 4:
            isfull();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("\nExiting.");
            break;
        default:
            printf("\nInvalid input.");
        }
    } while (choice != 6);
    return 0;
}