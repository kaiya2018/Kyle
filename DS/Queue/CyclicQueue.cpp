#include<iostream>
#include<malloc.h>
using namespace std;

#define QueueMAXSIZE 6

typedef struct CyclicQueue
{
    int *base;
    int front;
    int rear;
}CyclicQueue;

bool InitCyclicQueue(CyclicQueue &Q);

bool EnQueue(CyclicQueue &Q,int e);

bool DeQueue(CyclicQueue &Q,int &e);

int QueueLength(CyclicQueue Q);

void display(CyclicQueue Q);

int main(){
    printf("\n");
    CyclicQueue Q1;
    InitCyclicQueue(Q1); 
    int x;
    printf("enter the value(one for enqueue,two for dequeue,9999 for exit)\n");
    scanf("%d",&x);
    int s;
    while (x!=9999)
    {
        if (x==1)
        {
            printf("enter the value\n");
            scanf("%d",&s);
            EnQueue(Q1,s);
        }
        else if(x==2){
            DeQueue(Q1,s);
        }
        display(Q1);
        printf("enter the value(one for enqueue,two for dequeue,9999 for exit)\n");
        scanf("%d",&x);
    }
    return 0;
}

bool InitCyclicQueue(CyclicQueue &Q){
    Q.base = (int*)malloc(sizeof(int));
    if(!Q.base)
        return 0;
    Q.front=Q.rear=0;
    return true;
}

bool EnQueue(CyclicQueue &Q,int e){
    if((Q.rear+1)%QueueMAXSIZE==Q.front)
        return false;
    Q.base[Q.rear]=e;
    Q.rear = (Q.rear+1)%QueueMAXSIZE;
    return true;
}

bool DeQueue(CyclicQueue &Q,int &e){
    if (Q.front==Q.rear)
        return 0;
    Q.front = (++Q.front)%QueueMAXSIZE;
    if(Q.front==Q.rear)
        Q.front=Q.rear=0;
    return true;
}

int QueueLength(CyclicQueue Q){
    return (Q.rear-Q.front+QueueMAXSIZE)%QueueMAXSIZE;
}

void display(CyclicQueue Q){
    printf("Q.front: %d\n",Q.front);
    printf("Q.rear: %d\n",Q.rear);
    printf("length: %d\n",QueueLength(Q));
    if(Q.front==Q.rear){
        printf("*-------------*\n");
		printf("Empty Queue\n");
		printf("*-------------*\n");
        return;
    }
    int front=Q.front;
    printf("{");
    while (Q.front!=Q.rear)
    {
        printf("%d",Q.base[Q.front]);
        Q.front = (Q.front+1)%QueueMAXSIZE;
        if (Q.front!=Q.rear)
            printf("->");
    }
    printf("}\n");
    Q.front=front;
}

