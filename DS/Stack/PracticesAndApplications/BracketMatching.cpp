#include<iostream>
#include<malloc.h>

#define MAX_SIZE 25

typedef struct{
    char data[5];//也可以用指针动态分配数组
    int top;
}SqStack;

void InitStack(SqStack &S);

bool Pop(SqStack &S,char X);

bool Push(SqStack &S,char X);

bool StackEmpty(SqStack S);

bool GetTop(SqStack S,char &x);

bool DestroyStack(SqStack &S);

void display(SqStack S);

bool BracketMatching(char *b,SqStack &S);

int strlen(char *s);

int main(){
    printf("\n");
    SqStack S1;
    char *brackets = (char*)malloc(20*sizeof(char));
    InitStack(S1);
    brackets = "{[()]}";
    // if(!brackets[10])
    //     printf("null\n");

    // printf("\n%c\n",brackets[10]);   
    // printf("\n%s\n",brackets);
    
    BracketMatching(brackets,S1);

    return 0;
}

int strlen(char *s){
    int length = 0;
    while (*s)
    {
        length++;
        s++;
    }
    return length;
}

bool BracketMatching(char *b,SqStack &S){
    int length = strlen(b);
    char v;
    char x;
    for (int i = 0; i < length; i++)
    {
        printf("%c\n",b[i]);
        GetTop(S,x);
        if(b[i]=='{'||b[i]=='['||b[i]=='(')
        {
            Push(S,b[i]);
        }
        else if(b[i]==')'){
            if(x=='(')
                Pop(S,v);
            else{
                printf("wrong\n");
                return false;
            }
        }
        else if(b[i]==']'){
            if(x=='[')
                Pop(S,v);
            else{
                printf("wrong\n");
                return false;
            }
        }
        else if(b[i]=='}'){
            if(x=='{')
                Pop(S,v);
            else{
                printf("wrong\n");
                return false;
            }
        }
        display(S);
    }
    if (StackEmpty(S))
    {
        printf("matching!!\n");
        return true;
    }
    printf("wrong\n");
    return false;
}

void InitStack(SqStack &S){
    S.top = -1;
}

bool Pop(SqStack &S,char X){
    if (S.top==-1)
        return false;
    X = S.data[S.top--];
    return true;
}

bool Push(SqStack &S,char X){
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

bool GetTop(SqStack S,char &X){
    if(S.top==-1)
        return false;
    X = S.data[S.top];
    return true;
}

void display(SqStack S){
    if(S.top==-1)
        printf("Empty SqStack\n");
    int index = 0;
    printf("Stack: ");
    for (int i = 0; i <= S.top; i++)
    {
        printf("%c",S.data[i]);
        if(i!=S.top)
            printf("->");
    }
    printf("\n");
}
