#include<stdio.h>
#include<malloc.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

LinkList insert(LinkList L,int index);

LinkList initializing(LinkList L);

int display(LinkList L);

int main(){
    LinkList L = malloc;
    initializing(L);
    display(L);
    return 0;
}

LinkList insert(LinkList L,int index){ //1.C没有引用这个概念,加了就报错.C++才有
    printf("invoked");

    return L;
}

LinkList initializing(LinkList L){
    L->next = NULL;
    int x;
    printf("\n请输入数据(输入9999退出)");
    scanf("%d",x);
    if (x==9999)
        return L;
    L->data = x;
    printf("\n请输入数据(输入9999退出)");
    scanf("%d",x);
    LNode *p;
    while (x!=9999)
    {
        p = (LNode*)malloc(sizeof(LNode));
        p->data = x;
        p->next = L->next;
        L->next = p;
        printf("\n请输入数据(输入9999退出)");
        scanf("%d",x);
    }
    return L;
}

int display(LinkList L){
    if(L->next==NULL){
        printf("\nempty list\n");
        return 0;
    }
    LinkList i;
    for (i=L; i->next!=NULL;i=i->next)
    {
        printf("%d",i->data);
        if (i->next!=NULL)
        {
            printf("->");
        }
        
    }
    printf("\n");
    return 1;
}