#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("%d inserted at beginning.\n", value);
}
void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head)
    {
        printf("%d deleted from end.\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *temp = head;
        struct Node *prev = NULL;
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        printf("%d deleted from end.\n", temp->data);
        free(temp);
    }
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
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
void reverseList()
{
    if (head == NULL || head->next == head)
    {
        return; 
    }

    struct Node *prev = NULL, *current = head, *nextNode = NULL;
    struct Node *last = head;
    while (last->next != head)
    {
        last = last->next;
    }

    do
    {
        nextNode = current->next; 
        current->next = prev;     
        prev = current;           
        current = nextNode;       
    } while (current != head);
    head->next = prev; 
    head = prev;     
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n--- Singly Circular Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Delete from end\n");
        printf("3. Traverse forward\n");
        printf("4. Traverse reverse\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        case 2:
            deleteFromEnd();
            break;
        case 3:
            traverseForward();
            break;
        case 4:
            if (head == NULL)
            {
                printf("List is empty.\n");
            }
            else
            {
                reverseList();
                printf("List reversed.\n");
                traverseForward();
            }
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
