#include<iostream>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

LinkList List_HeadInsert(LinkList &L);

LinkList List_TailInsert(LinkList &L);

LNode* getElem(LinkList L,int index);

LNode* locateElem(LinkList L,int value);

int display(LinkList L);

bool insert(LinkList &L,int value,int pos);

bool deleteLNode(LinkList &L,int pos);

int getSize(LinkList L);

int main(){
    LinkList L;
    List_TailInsert(L);
    display(L);
    cout<<"Length: "<<getSize(L)<<endl;
    //按位查找
    // LNode *L1 = new LNode;
    // int index = 0;
    // while (index!=9999) 
    // {
    //     printf("输入需要查找的位序\n");
    //     scanf("%d",&index); 
    //     L1 = getElem(L,index);
    //     display(L1);
    // }
    
    //按值查找
    // LNode *L2;
    // int value;
    // printf("输入需要查找的值\n");
    // scanf("%d",&value);
    // while (value!=9999)
    // {
    //     L2 = locateElem(L,value);
    //     display(L2);
    //     printf("输入需要查找的值\n");
    //     scanf("%d",&value);
    // }
    
    //按位插入
    // LinkList L3 = L;
    // int pos;
    // int value1;
    // printf("输入你要插入的位置(输入9999退出)\n");
    // scanf("%d",&pos);
    // while (pos!=9999)
    // {
    //     printf("输入你要插入的值(输入9999退出)\n");
    //     scanf("%d",&value1);
    //     insert(L3,value1,pos);
    //     display(L3);
    //     printf("输入你要插入的位置(输入9999退出)\n");
    //     scanf("%d",&pos);
    // }

    //按位删除
    // int pos2;
    // int status;
    // cout<<"输入你要删除的位置(输入9999退出)\n";
    // scanf("%d",&pos2);
    // while(pos2!=9999){
    //     status = deleteLNode(L3,pos2);
    //     if (status==0)
    //         cout<<"删除失败\n";
    //     display(L3);
    //     cout<<"输入你要删除的位置(输入9999退出)\n";
    //     scanf("%d",&pos2);
    // }   
    return 0;
}

// LinkList insert(LinkList &L,int index){ //1.C没有引用这个概念,加了就报错.C++才有
//     printf("invoked");

//     return L;
// }

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
    tail = L; //这里如果让tail指向L->next的话,后面对tail的赋值就不会对L产生影响(只是让tail指向了一个新地址而已),L->next会永远为NULL;
              //而如果让tail指向L的话,对tail->next的赋值实际上就是对L->next的赋值
    int x;
    cout<<"\n请输入数据(输入9999退出)\n";
    scanf("%d",&x);
    while (x!=9999)
    {
        s = new LNode;
        s->data = x;
        tail->next = s;
        tail = s;
        cout<<"\n请输入数据(输入9999退出)\n";
        scanf("%d",&x);
    }
    tail->next = NULL;
    return L;
}

int display(LinkList L){
    if(L==NULL){
        cout<<"\nempty list\n";
        return 0;
    }
    if(L->next==NULL){
        cout<<"\nempty list\n";
        return 0;
    }
    LinkList i = L;
    cout<<"\n{";
    while (i->next!=NULL){
        i = i->next;
        cout<<i->data;
        if (i->next!=NULL)
        {
            cout<<"->";
        }                   
    }
    cout<<"}";
    cout<<endl;
    return 1;
}

LNode* getElem(LinkList L,int index){
    int size = 1;
    LNode *p = L->next;
    if(index==0)
        return L;
    if (index<0)
        return NULL;
    while (p&&size<index)
    {
        size++;
        p = p->next;
    }

    return p; 
}

// LNode* locateElem(LinkList L,int value){//自己的写法
//     while (L->next!=NULL)
//     {
//        L = L->next;
//        if (L->data == value ){
//         return L;
//        }
//     }
//     cout<<value<<" is not in the List\n";
//     return NULL;
// }

LNode* locateElem(LinkList L,int value){//王道辅导书里的写法
    L = L->next;
    while (L!=NULL&&L->data!=value)
    {
        L = L->next;
    }
    cout<<value<<" is not in the List\n";
    return L;
}

bool insert(LinkList &L,int value,int pos){//王道写法
    if (L==NULL)
        return 0;
    LNode *p = getElem(L,pos-1);
    if (p==NULL)
        return 0;
    LNode *L_new = new LNode;
    L_new->data = value;
    L_new->next = p->next;
    p->next = L_new;
    return 1; 
}

// bool insert(LinkList &L,int value,int pos){//自己的写法
//     if(pos<=0){
//         cout<<"\nillegal argument\n";
//         return 0;
//     }
//     LNode *L_body = L; //在不对L_head重新赋值的情况下,L_head永远指向头结点
//     LNode *L_next;
//     LNode *L_new = new LNode;
//     int index = 1;
//     while (L_body->next!=NULL&&index!=pos)
//     {
//         L_body = L_body->next;
//         index++;
//         cout<<"index: "<<index<<endl;
//     }
//     if (index==pos)
//     {
//         L_new->data = value;
//         L_new->next = L_body->next;
//         L_body->next = L_new;
//     }
    
//     return 1; 
// }

bool deleteLNode(LinkList &L,int pos){
    if(L==NULL||pos<=0)
        return 0;
    LNode *p = getElem(L,pos-1);
    if (p==NULL||p->next==NULL)
        return 0;
    LNode *s = p->next;
    p->next = s->next;
    delete s;
    return 1;
}

int getSize(LinkList L){
    if (L==NULL)
        return 0;
    int size = 0;
    while (L->next!=NULL)
    {
        size++;
        L = L->next;
    }
    return size;
}
