#include <stdio.h>
#define N 10
int s1[N];
int s2[N];
int top1 = -1, top2 = -1;
void push1(int a)
{
    if (top1 == (N - 1))
    {
        printf("overflow \n");
    }
    else
    {
        top1++;
        s1[top1] = a;
    }
}
void push2(int a)
{
    if(top2==(N-1)){
        printf("Overflow\n");
    }
    else 
    {
        top2++;
        s2[top2];
    }
}
int pop1()
{
    if(top1 ==-1)
    {
        printf("underflow");
        return -1;
    }
    else
    {
        return s1[top1--];
    }
}
int pop2()
{
    if(top2 ==-1)
    {
        printf("underflow");
        return -1;
    }
    else
    {
        return s2[top2--];
    }
}
void enqueue(int data){
    push1(data);
}
int dequeue()
{
    if( top1 == -1 && top2 == -1)
    {
        printf("Empty\n");
        return -1;
    }
    if(top2==-1)
    {
        while(top2 != -1)
        {
            push2(pop1());
        }
    }
    return (pop2());
}
void display()
{
    if(top1 == -1 && top2 == -1)
    {
        printf("Both are empty");
    }
    for (int i = top2 ; i>= 0; i--)
    {
        printf("%d", s2[i]);
    }
    for(int j = 0; j<= top1; j++)
    {
        printf("%d", s1[j]);
    }
}
void main()
{
    int x;
    int choice;
    printf("Enter your choice;\t")
}