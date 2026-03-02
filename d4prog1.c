#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void LLtraverse(struct node *head)
{
    printf("The Traversed Linked List is: \n");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void LLreverse(struct node *head)
{
    if (head == NULL)
        return;
    LLreverse(head->next);
    printf("%d -> ", head->data);
}
int LLinsert(struct node **head, int pos, int value)
{
    struct node *NN = (struct node *)malloc(sizeof(struct node));
    NN->data = value;
    NN->next = NULL;

    if (pos < 1)
    {
        printf("Invalid Position \n");
        free(NN);
        return 0;
    }
    if (pos == 1)
    {
        NN->next = *head;
        *head = NN;
        return 1;
    }
    struct node *temp = *head;
    int k = 1;

    while (temp != NULL && k < pos - 1)
    {
        temp = temp->next;
        k++;
    }
    if (temp == NULL)
    {
        printf("Position Not Present\n");
        free(NN);
        return 0;
    }
    NN->next = temp->next;
    temp->next = NN;
    return 1;
}
void count(struct node *head)
{
    int c = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    printf("The number of nodes are: %d\n", c);
}
void search(struct node *head, int ele)
{
    int k = 1, found = 0;
    while (head != NULL)
    {
        if (head->data == ele)
        {
            printf("The element %d has been found at position %d\n", ele, k);
            found = 1;
        }
        k++;
        head = head->next;
    }
    if (found == 0)
        printf("Element %d not found in the list.\n", ele);
}
void delete(struct node **head, int pos)
{
    if (*head == NULL)
    {
        printf("The list is empty \n");
        return;
    }
    if (pos < 1)
    {
        printf("Invalid position \n");
        return;
    }
    struct node *temp = *head;
    {
        if (pos == 1)
        {
            *head = temp->next;
            printf("The element %d was deleted from the position %d", temp->data, pos);
            free(temp);
            return;
        }
        int i;
        for (i = 1; temp->next != NULL && pos < i - 1; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL)
        {
            printf("Position out of bound \n");
            return;
        }
        struct node *del = temp->next;
        temp->next = del->next;
        printf("The element %d is deleted from the position %d ", del->data, pos);
        free(del);
    }
}
void sorting(struct node *head)
{
    struct node *i;
    struct node *j;
    int temp;
    if (head == NULL)
    {
        printf("The list is empty \n");
        return;
    }
    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node *temp;
    struct node *head = NULL;
    char ch;
    printf("Enter the choice y/n to create the list: ");
    scanf(" %c", &ch);
    while (ch == 'y')
    {
        struct node *NN = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &NN->data);
        NN->next = NULL;

        if (head == NULL)
        {
            head = temp = NN;
        }
        else
        {
            temp->next = NN;
            temp = NN;
        }

        printf("Do you want to add more y/n? ");
        scanf(" %c", &ch);
    }
    int choice;
    do
    {
        printf("\n***** MENU *****\n");
        printf("1. Traverse the list\n");
        printf("2. Reverse the list\n");
        printf("3. Insert in list\n");
        printf("4. Count the elements in the list\n");
        printf("5. Search for an element\n");
        printf("6. Delete from a given position\n");
        printf("7. Sort the list\n");
        printf("8. Exit \n");
        printf("Enter your choice: \t");
        scanf("%d", &choice);
        int pos, val, ele;
        switch (choice)
        {
        case 1:
            LLtraverse(head);
            break;
        case 2:
            printf("The reversed list is:\n");
            LLreverse(head);
            printf("NULL\n");
            break;
        case 3:
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            printf("Enter value to insert: ");
            scanf("%d", &val);
            LLinsert(&head, pos, val);
            break;
        case 4:
            count(head);
            break;
        case 5:
            printf("Enter element to search: ");
            scanf("%d", &ele);
            search(head, ele);
            break;
        case 6:
            printf("Enter the position to delete; \t");
            scanf("%d", &pos);
            delete(&head, pos);
            break;
        case 7:
            sorting(head);
            break;
        case 8:
            printf("You're EXITING  ");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 8);
    return 0;
}