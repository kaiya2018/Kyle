#include<iostream>
using namespace std;

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
}*LinkStack;

void InitLinkStack(LinkStack &S);

bool push(LinkStack &S,int x);

bool pop(LinkStack &S,int x);

void display(LinkStack S);

int main(){
    printf("\n");
    LinkStack S1;
    InitLinkStack(S1);
    display(S1);
    int x;
    printf("enter command(1 for push,2 for pop,0 for exit)\n");
    scanf("%d",&x);
    int v;
    while (x!=0)
    {
        if (x==1)
        {
            printf("enter the value\n");
            scanf("%d",&v);
            push(S1,v);
        }
        else if(x==2){
            pop(S1,v);
        }
    display(S1);
    printf("enter command(1 for push,2 for pop,0 for exit)\n");
    scanf("%d",&x);
    }
    

    return 0;
}

void InitLinkStack(LinkStack &S){
    S = NULL;
}

bool push(LinkStack &S,int x){
    LinkStack p = (LinkStack)malloc(sizeof(LinkNode));
    if (!p)
        return 0;
    p->data = x;
    p->next = S;
    S = p;
}

bool pop(LinkStack &S,int x){
    if (!S)
        return false;
    LinkStack p = S;
    S = S->next;
    free(p);
    return true;
}

void display(LinkStack S){
    if (S==NULL){
        printf("*-------------*\n");
		printf("Empty Queue\n");
		printf("*-------------*\n");
        return;
    }
    printf("{");
    while (S!=NULL)
    {
        printf("%d",S->data);
        if(S->next!=NULL)
            printf("->");
        S = S->next;
    }
    printf("}\n");
}
