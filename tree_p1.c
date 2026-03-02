#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int search(struct node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    struct node* root = NULL;
    int n, i, data, ch, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    do {
        printf("\n1.Preorder\n2.Inorder\n3.Postorder\n4.Search\n5.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: preorder(root); break;
            case 2: inorder(root); break;
            case 3: postorder(root); break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Found\n");
                else
                    printf("Not Found\n");
                break;
        }
    } while (ch != 5);
    return 0;
}
