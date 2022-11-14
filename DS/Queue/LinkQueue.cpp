#include<iostream>
using namespace std;

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue
{
    LinkNode *front,*rear;
}LinkQueue;


void InitQueue(LinkQueue &Q);

bool IsEmpty(LinkQueue Q);

void EnQueue(LinkQueue &Q,int X);

bool DeQueue(LinkQueue &Q,int &X);

void ClearQueue(LinkQueue &Q);

int QueueLength(LinkQueue Q);

void Display(LinkQueue Q);

int main(){
	printf("\n");
	LinkQueue Q1;
	InitQueue(Q1);
	Display(Q1);
	printf("length: %d\n",QueueLength(Q1));
	
	//EnQueue
	int x;
	printf("Enter your number(9999 for exit)\n");
	scanf("%d",&x);
	while(x!=9999){
		EnQueue(Q1,x);
		Display(Q1);
		printf("Enter your number(9999 for exit)\n");
		scanf("%d",&x);
	}
	
	//DeQueue
//	printf("DeQueue?(one for yes,other number for exit)\n");
//	scanf("%d",&x);
//	int r;
//	while(x==1){
//		DeQueue(Q1,r);
//		Display(Q1);
//		printf("value: %d\n",r);
//	printf("DeQueue?(one for yes,other number for exit)\n");
//	scanf("%d",&x);
//	}
	
	//ClearQueue
	printf("ClearQueue?(one for yes,other number for exit)\n");
	scanf("%d",&x);
	if(x==1)
		ClearQueue(Q1) ;
	Display(Q1);
	return 0;
}

void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q){
    if(Q.front==Q.rear)
        return true;
    return false;
}

void EnQueue(LinkQueue &Q,int X){
    LinkNode *L = (LinkNode*)malloc(sizeof(LinkNode));
    L->data = X;
    L->next = NULL; 
	Q.rear->next = L; 
	Q.rear = L;
}

bool DeQueue(LinkQueue &Q,int &X){
	if(Q.front==Q.rear){
		printf("Q is empty\n");
		return false;
	}
	
	LinkNode *p = Q.front->next;
	X = p->data;
	Q.front->next=p->next;
	free(p);
	if(Q.front->next==Q.rear){	
		Q.rear=Q.front;
		printf("Q has been cleaned\n");
	}
	return true;
} 

void ClearQueue(LinkQueue &Q){
	LinkNode *p = Q.front->next;
	LinkNode *s;
	while(p!=NULL){
		s=p->next;
		free(p);
		p=s; 
	}
	Q.rear=Q.front;
	Q.front->next=NULL;
}

int QueueLength(LinkQueue Q){
	int count = 0;
	LinkNode *p = Q.front->next;
	while(p!=NULL){
		p = p->next;
		count++;
	}
	return count;
}

void Display(LinkQueue Q){
	if(Q.front==Q.rear){
		printf("*-------------*\n");
		printf("Empty Queue\n");
		printf("*-------------*\n");
//		return;
	}
	printf("length: %d\n",QueueLength(Q));
	LinkNode *p = Q.front->next;
	printf("{");
	while(p!=NULL){
		printf("%d",p->data);
		if(p->next!=NULL)
			printf("->");
		p = p->next;
	}
	printf("}\n");
}



