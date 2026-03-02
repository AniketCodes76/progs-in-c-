#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of elements.\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements.\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Ascending order : ");
    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[smallest] > arr[j])
            {
                smallest = j;
            }
        }
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Descending order : ");
    for (int i = 0; i < n - 1; i++)
    {
        int largest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[largest] < arr[j])
            {
                largest = j;
            }
        }
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}