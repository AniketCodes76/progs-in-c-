#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtPosition(int value, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    if (pos == 1)
    {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        printf("%d inserted at position %d.\n", value, pos);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    newNode->prev = temp;

    printf("%d inserted at position %d.\n", value, pos);
}

void deleteAtPosition(int pos)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    if (pos == 1)
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        printf("%d deleted from position %d.\n", temp->data, pos);
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < pos; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("%d deleted from position %d.\n", temp->data, pos);
    free(temp);
}

void traverseForward()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Forward Traversal: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        if (temp->next == NULL)
            break;
        temp = temp->next;
    }
    printf("\n");
}

void traverseBackward()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Backward Traversal: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    int choice, value, pos;
    while (1)
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at specific position\n");
        printf("2. Delete from specific position\n");
        printf("3. Traverse forward\n");
        printf("4. Traverse backward\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPosition(value, pos);
            break;
        case 2:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        case 3:
            traverseForward();
            break;
        case 4:
            traverseBackward();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
