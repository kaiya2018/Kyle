#include<iostream>

using namespace std;

#define MAX_SIZE 5

typedef struct{
    int data[5];//也可以用指针动态分配数组
    int top;
}SqStack;

void InitStack(SqStack &S);

bool Pop(SqStack &S,int X);

bool Push(SqStack &S,int X);

bool StackEmpty(SqStack S);

bool GetTop(SqStack S,int &x);

bool DestroyStack(SqStack &S);

void display(SqStack S);

int main(){
    SqStack S1;
    InitStack(S1);
    printf("\n");
    display(S1);
    int a;
    int b;
    printf("输入要加入的元素(输入9999退出)");
    scanf("%d",&a);
    while (a!=9999)
    {
        b = Push(S1,a);
        if(b==1)
            printf("插入成功\n");
        else
            printf("插入失败，栈已满\n");
        display(S1);
        printf("输入要加入的元素");
        scanf("%d",&a);
    }
    printf("是否弹出?(输入9999退出)\n");
    scanf("%d",&a);
    int x;
    while (a!=9999)
    {
        b = Pop(S1,x);
        if(b==0)
            printf("栈已为空\n");
        else
            printf("出栈成功\n");
        display(S1);
        printf("是否弹出?(输入9999退出)\n");
        scanf("%d",&a);
    }

    return 0;
}

void InitStack(SqStack &S){
    S.top = -1;
}

bool Pop(SqStack &S,int X){
    if (S.top==-1)
        return false;
    X = S.data[S.top--];
    return true;
}

bool Push(SqStack &S,int X){
    if (S.top==MAX_SIZE-1)
        return false;
    S.data[++S.top] = X;
    return true;
}

bool StackEmpty(SqStack S){
    if(S.top==-1)
        return true;
    return false;
}

bool GetTop(SqStack S,int &X){
    if(S.top==-1)
        return false;
    X = S.data[S.top];
    return true;
}

void display(SqStack S){
    if(S.top==-1)
        printf("Empty SqStack");
    int index = 0;
    for (int i = 0; i <= S.top; i++)
    {
        printf("%d",S.data[i]);
        if(i!=S.top)
            printf("->");
    }
    printf("\n");
}

