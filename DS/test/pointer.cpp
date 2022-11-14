#include<iostream>

using namespace std;

void test1(int *t);
void test2(int *&t);    

static int c = 100;

int main(){ //结论: 指针做形参传入函数时,依旧不会改变实参的数据及地址,依然要加引用(&)
    int a = 10;
    int b = 20;
    int *p_a = &a;
    int *p_b = &b;

    cout<<"\n";
    cout<<"a: "<<a<<endl;
    cout<<"*p_a的值: "<<*p_a<<endl;
    cout<<"p_a的地址: "<<&p_a<<endl;
    cout<<"p_a指向的地址: "<<p_a<<endl;
    test1(p_a);
 
    cout<<"\nafter test1:\n";
    cout<<"a: "<<a<<endl;
    cout<<"*p_a的值: "<<*p_a<<endl;
    cout<<"p_a指向的地址: "<<p_a<<endl;
    test2(p_a);

    cout<<"\nafter test2:\n";
    cout<<"a: "<<a<<endl;
    cout<<"*p_a的值: "<<*p_a<<endl;
    cout<<"p_a的地址: "<<&p_a<<endl;
    cout<<"p_a指向的地址: "<<p_a<<endl;

    return 0;
}

void test1(int *t){
    cout<<"\n";
    cout<<"t的地址: "<<&t<<endl;
    cout<<"t指向的地址: "<<t<<endl;
    t = &c;
    cout<<"\ntest1内:\n";
    cout<<"c的地址: "<<&c<<endl;
    cout<<"*t的值: "<<*t<<endl;
    cout<<"t的地址: "<<&t<<endl;
    cout<<"t指向的地址: "<<t<<endl;
}

void test2(int *&t){
    t = &c;
   cout<<"\ntest2内:\n";
   cout<<"c的地址: "<<&c<<endl;
   cout<<"*t的值: "<<*t<<endl;
   cout<<"t的地址: "<<&t<<endl;
   cout<<"t指向的地址: "<<t<<endl;
}

