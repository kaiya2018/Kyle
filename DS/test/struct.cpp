#include<iostream>

using namespace std;

struct books{ //定义结构体
    char* title = new char[20];
    float price;
    int quantity;
}book2,book3; //跟在 } 后面的为建立的可以直接用的变量

typedef struct LNode{
    int data;
    struct LNode* next;
}LNode,*LinkList;

int main(){
    struct books book1;   
    book1.price = 20;
    cout<<"\n"<<book1.price<<endl;
    book2.price = 30;
    cout<<"\n"<<book2.price<<endl;
    book3.title = "a book";
    cout<<book3.title<<endl;

    LNode* l1 = new LNode;
    l1->data = 11;
    cout<<"l1->data: "<<l1->data<<endl;
    LinkList l2 = new LNode;
    l2->data = 22;
    cout<<"l2->data: "<<l2->data<<endl;
    l1->next = l2;
    l1 = l1->next;
    cout<<"l1->data: "<<l1->data<<endl;
    return 0;
}
