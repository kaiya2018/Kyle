#include<iostream>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

int main(){
    LNode *l1 = new LNode;//指针必须分配空间,不然其指向的地址可能不可以被访问,触发segmentation fault
    LNode *l2 = new LNode;
    LNode *l3 = new LNode;
    l3->data = 3;
    l2->data = 2;
    l1->next = l2;
    cout<<"\n";
    cout<<"l1->next: "<<l1->next<<endl;
    cout<<"l2: "<<l2<<endl;
    l2 = l3;
    cout<<"l1->next: "<<l1->next<<endl;
    cout<<"l2: "<<l2<<endl; 

    LNode *L4 = NULL;
    cout<<"L4: "<<L4<<endl;
    cout<<"NULL: "<<NULL<<endl;
    return 0;
}
