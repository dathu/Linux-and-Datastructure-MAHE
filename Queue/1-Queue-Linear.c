#include<stdio.h>
#define MAX 10

int queues[MAX];
int front,rear=-1;

void enqueue(int ele){
if(front==-1){
    queues[++rear]=ele;
    ++front;
}
else if(rear==(MAX-1)){
    printf("queue overflow\n");
}
else{
    queues[++rear]=ele;
}
}

int dequeue(){
int c=999;
if(front==-1 || front>rear){
    printf("queue underflow\n");
}
else{
    c=queues[front++];
}
printf("front is %d and rear is %d\n",front,rear);
return c;
}

void display(){
if(front==-1 || front>rear){
    printf("queue is empty\n");
}
else{
    for(int i=front;i<=rear;i++){
        printf(" %d ",queues[i]);
    }
    printf("\n");
}
}

void main(){
while(1){
    printf("Enter 1 to enqueue\n");
    printf("Enter 2 to dequeue\n");
    printf("Enter 3 to display\n");
    printf("Enter 4 to exit\n");

    int choice;
    scanf("%d",&choice);
    switch(choice){
case 1:
    printf("Enter element:\n");
    int ele;
    scanf("%d",&ele);
    enqueue(ele);
    break;
case 2:
    dequeue();
    break;
case 3:
    display();
    break;
case 4:
    exit(1);


    }
}


}
