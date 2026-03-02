#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node * temp;
    struct node * head= NULL;
    printf("enter the choice y/n\n");
    char ch;
    scanf("%s",&ch);
    while(ch == 'y')
    {
        struct node * NN= (struct node *) malloc (sizeof(struct node));
        printf("Enter the data ");
        scanf("%d",& NN -> data);
        if(head == 0)
        {
            head=temp=NN;
        }
        else{
            temp -> next = NN;
            temp= NN;
        }
        printf("Do you want to add more y/n \n");
        scanf("%s",&ch);
    } 
    temp=head;
    while (temp != NULL)
    {
        printf("%d", temp -> data );
        temp = temp -> next;
    }  
    return 0;
}