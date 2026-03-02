#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node * f= NULL;
struct node * r = NULL;
int isEmpty()
{
    if(f==NULL)
    {
        return 1;
    }
    else
        return 0;
}
void enqueue(int data)
{
    struct node * NN = (struct node *) malloc (sizeof(struct node));
    NN -> data = data;
    NN -> next = NULL;
    if(NN == NULL)
    {
        printf("memory allocation has failed, heap overflow\n");
    }
    if( f == NULL && r == NULL)
        f = r = NN;
    else
    {
        r -> next = NN;
        r = NN;
    }
    printf("the inserted element is %d. ", data);
}
void dequeue()
{
    if(isEmpty())
    {
        printf("the queue is empty");
    }
    struct node * temp = f;
    printf("The deleted item is %d   ", temp->data);
    f = f -> next;
    free(temp);
}
void display()
{
    if(isEmpty())
        printf("the queue is empty\n");
    else{
        struct node * temp = f;
        while(temp != NULL)
        {
            printf("%d -> ", temp-> data);
            temp = temp -> next;
        }
    }
    printf("\n THE QUEUE HAS BEEN DISPLAYED");
}
int main()
{
    int choice, x;
    do
    {
        printf("\nEnter 1 to enqueue an element.");
        printf("\nEnter 2 to dequeue an element.");
        printf("\nEnter 3 to check whether the queue is empty.");
        printf("\nEnter 4 to display the queue.");
        printf("\nEnter 5 to exit.");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                int n;
                printf("Enter the element to be enqueued:  ");
                scanf("%d", &n);
                enqueue(n);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                if(isEmpty())
                {
                    printf("the queue is empty\n");
                }
                else
                    printf("Not empty\n");
                break;
            case 4:
                display();
                break;
            default:
                printf("invalid input\n");
                break;
        }
    }while( choice != 5);
    return 0;
}