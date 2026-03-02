#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void insertFront(int x) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = front;

    if (front == NULL) {
        front = rear = newnode;
    } else {
        front->prev = newnode;
        front = newnode;
    }
}

void insertRear(int x) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = rear;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

int deleteFront() {
    if (front == NULL) return -1;

    struct node *temp = front;
    int val = temp->data;

    front = front->next;
    if (front == NULL) {
        rear = NULL;
    } else {
        front->prev = NULL;
    }

    free(temp);
    return val;
}

void display() {
    struct node *temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value, d;

    while (1) {
        printf("\n1.Insert at front\n2.Insert at rear\n3.Delete from front\n4.Display\n5.Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%d", &value);
            insertFront(value);
        } else if (choice == 2) {
            scanf("%d", &value);
            insertRear(value);
        } else if (choice == 3) {
            d = deleteFront();
            if (d == -1) printf("Deque empty\n");
            else printf("Deleted from front: %d\n", d);
        } else if (choice == 4) {
            display();
        } else {
            break;
        }
    }

    return 0;
}
