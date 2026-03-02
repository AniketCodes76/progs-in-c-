#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node * root = NULL;
struct node * createnode(int data)
{
    struct node* nn= (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->left = nn->right = NULL;
    return nn;
}
struct node* insert (struct node * root, int data)
{
    if(root == NULL)
    {
        root = createnode(data);
    }
    if(data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
void preorder(struct node * root)
{
    if( root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node * root)
{
    if( root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(struct node * root)
{
    if( root != NULL )
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);  
    }
}
int search(struct node * root, int key)
{
    if( root == NULL)
    {
        return 0;
    }
    if( root->data == key )
        return 1;
    else if( key < root->data)
        return search(root->left, key);
    else if( key > root->data)
        return search(root->right, key);
    else 
        return 0;
}
int main()
{

    int n,d,ch;
    printf("Enter the number of data you want:  ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("\nEnter the data:  ");
        scanf("%d", &d);
        root = insert(root, d);
    }
    do{
        printf("\n1. Preorder.\n2. Inorder\n3. Postorder\n4. Search an element\n5. Exit");
        printf("\nEnter your choice amongst the following:  ");
        scanf("%d", &ch);
        switch(ch)
        {
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
                printf("\nenter the element to search: ");
                int k;
                scanf("%d",&k);
                if(search(root,k))
                    printf("\nFound");
                else   
                    printf("\nNot Found");
                break;
            case 5:
                printf("EXITING THANKS 🙏🏻 ");
                break;
            default:
                printf("Invalid input");
                break;
        }
    } while (ch != 5);
    return 0;
}

