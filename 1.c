#include<stdio.h>
int main()
{
    int a;
    int f=1;
    printf("enter a no");
    scanf("%d",&a);
    for(int i=1;i<=a;i++)
    {
        f=f*i;
    }
    printf("fact is %d", f);
    return 0;
}