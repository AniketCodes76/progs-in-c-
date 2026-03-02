#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data){
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = data;
    nn->left = nn->right = NULL;
    return nn;
}

struct node* insert(struct node* root, int data){
    if(root == NULL)
        return createnode(data);
    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void preorder(struct node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int search(struct node* root, int key){
    if(root == NULL)
        return 0;
    if(root->data == key)
        return 1;
    else if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int largest(struct node* root){
    if(root == NULL)
        return 0;
    while(root->right != NULL)
        root = root->right;
    return root->data;
}

int smallest(struct node* root){
    if(root == NULL)
        return 0;
    while(root->left != NULL)
        root = root->left;
    return root->data;
}

int countleaf(struct node* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return countleaf(root->left) + countleaf(root->right);
}

int height(struct node* root){
    if(root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int main(){
    struct node* root = NULL;
    int n, d, ch, k;

    printf("Enter the number of data you want: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter the data: ");
        scanf("%d", &d);
        root = insert(root, d);
    }

    do{
        printf("\n\n--- MENU ---");
        printf("\n1. Preorder");
        printf("\n2. Inorder");
        printf("\n3. Postorder");
        printf("\n4. Search an element");
        printf("\n5. Largest element");
        printf("\n6. Smallest element");
        printf("\n7. Count leaf nodes");
        printf("\n8. Height of tree");
        printf("\n9. Insert new element");
        printf("\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                preorder(root);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                postorder(root);
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &k);
                if(search(root, k))
                    printf("Element found.");
                else
                    printf("Element not found.");
                break;
            case 5:
                printf("Largest element: %d", largest(root));
                break;
            case 6:
                printf("Smallest element: %d", smallest(root));
                break;
            case 7:
                printf("Number of leaf nodes: %d", countleaf(root));
                break;
            case 8:
                printf("Height of tree: %d", height(root));
                break;
            case 9:
                printf("Enter element to insert: ");
                scanf("%d", &d);
                root = insert(root, d);
                printf("Element inserted.");
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }while(ch != 10);
}
