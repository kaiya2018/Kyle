#include<iostream>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

LinkList insert(LinkList &L,int index);

LinkList List_HeadInsert(LinkList &L);

LinkList List_TailInsert(LinkList &L);

int display(LinkList L);

int main(){
    LinkList L;
    List_TailInsert(L);
    display(L);

    // LinkList L1 = new LNode;
    // LinkList L2 = L1;
    // LinkList L3 = L2;

    // cout<<"\nL1地址: "<<L1<<endl;
    // cout<<"\nL2地址: "<<L2;
    // cout<<"\nL3地址: "<<L3;

    return 0;
}

LinkList insert(LinkList &L,int index){ //1.C没有引用这个概念,加了就报错.C++才有
    printf("invoked");

    return L;
}

LinkList List_HeadInsert(LinkList &L){// 带头结点的头插法建立单链表
    LNode *s;
    int x;
    L = new LNode; //L是头指针,这里把分配到的内存(也就是头结点)赋给头指针L,所以L->next实际上就是头结点的next元素
    L->next = NULL; //先初始化为空表,当加入新数据元素时,把新元素的next指向L->next(也就成了表尾)
    cout<<"\n请输入数据(输入9999退出)\n";
    scanf("%d",&x);
    while (x!=9999)
    {
        s = new LNode;
        s->data = x;
        s->next = L->next; //第一次插入数据元素时,s->next会指向NULL(即第一个插入的元素为链表的最后一个元素);第二次以及后续插入时,s->next都会指向上一个元素插入的元素
        L->next = s;//使头结点的next永远指向最新加入的数据元素
        cout<<"\n请输入数据(输入9999退出)\n";
        scanf("%d",&x);
    }
    return L;
}

LinkList List_TailInsert(LinkList &L){
    L = new LNode;
    L->next = NULL;
    LNode *s;
    LNode *tail = new LNode;
    tail = L;
    // cout<<"L的地址"<<&L<<endl;
    // cout<<"L->next指向的地址"<<L->next<<endl;
    // cout<<"tail的地址"<<&tail<<endl;
    // cout<<"tail指向的地址"<<tail<<endl;
    int x;
    cout<<"\n请输入数据(输入9999退出)\n";
    scanf("%d",&x);
    while (x!=9999)
    {
        s = new LNode;
        s->data = x;
        tail->next = s;
        // cout<<"L的地址"<<&L<<endl;
        // cout<<"L->next指向的地址"<<L->next<<endl;
        // cout<<"s的地址"<<&s<<endl;
        // cout<<"s指向的地址"<<s<<endl;
        // cout<<"tail的地址"<<&tail<<endl;
        // cout<<"tail指向的地址"<<tail<<endl;

        tail = s;
        cout<<"\n请输入数据(输入9999退出)\n";
        scanf("%d",&x);
    }
    s->next = NULL;
    return L;
}

int display(LinkList L){
    if(L->next==NULL){
        cout<<"\nempty list\n";
        return 0;
    }
    LinkList i = L;
    while (i->next!=NULL){
        i = i->next;
        cout<<i->data;
        if (i->next!=NULL)
        {
            cout<<"->";
        }  
    }
    cout<<endl;
    return 1;
}