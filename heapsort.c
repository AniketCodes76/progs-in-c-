#include <stdio.h>
void heapify(int a[], int n, int i)
{
    int large = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[large])
        large = l;
    if (r < n && a[r] > a[large])
        large = r;
    if (large != i)
    {
        int temp = a[i];
        a[i] = a[large];
        a[large] = temp;
        heapify(a, n, large);
    }
}
void heapsort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}
int main()
{
    int n, i;
    printf("\nEnter the number of elements:  ");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    heapsort(a, n);
    printf("\nSorted Array is :");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
    return 0;
}