#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;
void insert_end(int val){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL){
        head=newnode;
        head->next=head;
        head->prev=head;
    }else{
        struct node *last=head->prev;
        last->next=newnode;
        newnode->prev=last;
        newnode->next=head;
        head->prev=newnode;
    }
}
void traverse(){
    if(head==NULL){
        printf("List empty\n");
        return;
    }
    struct node *temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}
void delete_begin(){
    if(head==NULL){
        printf("List empty\n");
        return;
    }
    if(head->next==head){
        free(head);
        head=NULL;
    }else{
        struct node *last=head->prev;
        struct node *temp=head;
        head=head->next;
        head->prev=last;
        last->next=head;
        free(temp);
    }
}
int main(){
    int ch,val;
    while(1){
        printf("1.Insert at end\n2.Traverse\n3.Delete from beginning\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter value: "); scanf("%d",&val); insert_end(val); break;
            case 2: traverse(); break;
            case 3: delete_begin(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
