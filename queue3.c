#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int front=-1,rear=-1,*cq;
void enqueue(int x){
    if((front==0&&rear==SIZE-1)||(rear+1==front)){
        printf("Queue Full\n");
        return;
    }
    if(front==-1) front=0;
    rear=(rear+1)%SIZE;
    cq[rear]=x;
}
void dequeue(){
    if(front==-1){
        printf("Queue Empty\n");
        return;
    }
    printf("Deleted: %d\n",cq[front]);
    if(front==rear) front=rear=-1;
    else front=(front+1)%SIZE;
}
void traverse(){
    if(front==-1){
        printf("Queue Empty\n");
        return;
    }
    int i=front;
    while(1){
        printf("%d ",cq[i]);
        if(i==rear) break;
        i=(i+1)%SIZE;
    }
    printf("\n");
}
void isempty(){
    if(front==-1) printf("Empty\n");
    else printf("Not Empty\n");
}
void isfull(){
    if((front==0&&rear==SIZE-1)||(rear+1==front)) printf("Full\n");
    else printf("Not Full\n");
}
int main(){
    cq=(int*)malloc(SIZE*sizeof(int));
    int ch,x;
    while(1){
        printf("\n1.Enqueue 2.Dequeue 3.Traverse 4.IsEmpty 5.IsFull 6.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: scanf("%d",&x); enqueue(x); break;
            case 2: dequeue(); break;
            case 3: traverse(); break;
            case 4: isempty(); break;
            case 5: isfull(); break;
            case 6: exit(0);
        }
    }
}
