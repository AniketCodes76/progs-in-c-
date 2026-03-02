#include <stdio.h>
void traverse(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int insert(int arr[], int n, int elem, int pos) {
    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return n;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = elem;
    return n + 1; 
}
int delete(int arr[], int n, int pos) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return n;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1; 
}
void linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at position %d.\n", key, i);
            return;
        }
    }
    printf("Element %d not found in the array.\n", key);
}

int main() {
    int arr[100], n, choice, elem, pos, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &elem);
                printf("Enter position (0-based index): ");
                scanf("%d", &pos);
                n = insert(arr, n, elem, pos);
                break;

            case 2:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &pos);
                n = delete(arr, n, pos);
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &key);
                linearSearch(arr, n, key);
                break;

            case 4:
                traverse(arr, n);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
