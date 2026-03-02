#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * left;
    struct node * right;
};
struct node * create(int value)
{
    struct node * nn = (struct node *)malloc((sizeof(struct node));
    nn->data= value;
    nn->left=nn->right=NULL;
}