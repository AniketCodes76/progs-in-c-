#include <stdio.h>
int main()
{
    int n, temp;
    printf("Enter the number of elements\t");
    scanf("%d", &n);
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter:   ");
        scanf("%d", &ar[i]);
    }
    printf("\nUnsorted is:  ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", ar[i]);
    }
    for (int i = 0; i < n - 1 ; i++)
    {
        for (int j = 0; j < n - i - 1 ; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
    printf("\nSorted List is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", ar[i]);
    }
    return 0;
}