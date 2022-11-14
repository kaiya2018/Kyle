#include<iostream>
using namespace std;

#define MAX_SIZE 5 

typedef struct{
    int data[MAX_SIZE];
    int head,rear;
}SqQueue;

void InitQueue(SqQueue &Q);

bool QueueEmpty(SqQueue Q);

bool EnQueue(SqQueue &Q,int X);

bool DeQueue(SqQueue &Q,int &X);

bool GetHead(SqQueue Q,int &X);

void display(SqQueue Q);

int main(){
    SqQueue Q1;
    InitQueue(Q1);
    printf("\n");
    printf("输入要入队的值(9999退出)\n");
    int X;
    scanf("%d",&X);
    while (X!=9999)
    {
        if(EnQueue(Q1,X))
            printf("插入成功\n");
        else
            printf("插入失败\n");
        display(Q1);
        printf("输入要入队的值(9999退出)\n");
        scanf("%d",&X);
    }

    printf("是否出队(9999退出)\n");
    scanf("%d",&X);
    int v;
    while (X!=9999)
    {
       if(!DeQueue(Q1,v))
            printf("队列为空，无需出队\n");
        else{
            printf("出队成功，%d已出队\n",v);
        }
        display(Q1);
        printf("是否出队(9999退出)\n");
        scanf("%d",&X);
    }

    printf("是否获取队头的值(9999退出)\n");
    scanf("%d",&X);
    while (X!=9999)
    {
       if(!GetHead(Q1,v))
            printf("队列为空，队头没有值\n");
        else{
            printf("获取成功，队头的值: %d\n",v);
        }
        printf("是否获取队头的值(9999退出)\n");
        scanf("%d",&X);
    }
    
    
}

void InitQueue(SqQueue &Q){
    Q.head = 0;
    Q.rear = 0;
}

bool QueueEmpty(SqQueue Q){
    if (Q.head==0&&Q.rear==0)
        return true;
    return false;
}

bool EnQueue(SqQueue &Q,int X){
    if(Q.rear-Q.head==MAX_SIZE)
        return false;
    Q.data[Q.rear++] = X;
    return true;
}

bool DeQueue(SqQueue &Q,int &X){
    if(QueueEmpty(Q))
        return false;
    X = Q.data[Q.head++];
    if(Q.head==Q.rear)
        Q.head=Q.rear=0;
    return true;
}

bool GetHead(SqQueue Q,int &X){
    if (QueueEmpty(Q))
        return false;
    X = Q.data[Q.head];
    return true;
}

void display(SqQueue Q){
    printf("head: %d\n",Q.head);
    printf("rear: %d\n",Q.rear);
    if(QueueEmpty(Q))
        printf("空队列\n");
    else{
        for (int i = Q.head; i < Q.rear-1; i++){
            printf("%d->",Q.data[i]);
    }
        printf("%d\n",Q.data[Q.rear-1]);
    }
}

