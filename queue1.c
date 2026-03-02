#include<stdio.h>
#define N 5
int q[N];
int f=-1,r=-1;
int isFull()
{
    if(r == N-1)
    {
        //printf("the queue is full \n");
        return 1;
    }
    else
    {
        //printf("the queue is not full\n");
        return 0;
    }
}
int isEmpty()
{
    if(f == -1)
        return 1;
    else
        return 0;
}
void enqueue(int data)
{
    if(isFull() == 1)
    {
        printf("the queue is full");
    }
    else
    {
        if(f==-1)
            f=0;
        r++;
        q[r]=data;
        printf("Inserted data is %d\t at pos%d\t",data,r);
    }
}
void dequeue()
{
    if(isEmpty()==1)
    {
        printf("queue is empty, nothing to delete from \n");
    }
    else
    {
        printf("the deleted item is %d",q[f]);
        f++;
        if(f>r)
            f=r=-1;
    }
}
void display()
{
    if(isEmpty())
    {
        printf("there is nothing to print\n");
    }
    else
    {
        for(int i = f; i <= r ; i++)
        {
            printf("%d\t", q[i]);
        }
    }
}
int main()
{
   int choice, x;
    do
    {
        printf("\nEnter 1 to enqueue an element.");
        printf("\nEnter 2 to dequeue an element.");
        printf("\nEnter 3 to check whether the queue is empty.");
        printf("\nEnter 4 to check whether the queue is full.");
        printf("\nEnter 5 to display the queue.");
        printf("\nEnter 6 to exit.");
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
                if (isEmpty())
                    printf("queue is empty");
                else
                    printf("the queue is not empty");
                break;
            case 4:
                if (isFull())
                    printf("queue is full");
                else
                    printf("the queue is not full");
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\nExiting");
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }while ( choice != 6);
    return 0;
}