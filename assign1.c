#include<stdio.h>
void comp(int *a, int *b)
{
    if(*a>*b)
        printf("the first no is greater %d",*a);
    else if(*a<*b)
        printf("the second no is greater %d",*b);
    else 
        printf("both are same");
}
int main()
{
    int m,n;
    printf("enter the first number and the second number");
    scanf("%d %d",&m,&n);
    //printf("enter the other number");
    //scanf("%d",&n);
    comp(&m,&n);
}
