#include<iostream>
#include<math.h>

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
}*LinkStack;

void InitLinkStack(LinkStack &S);
 
bool push(LinkStack &S,int x);

bool pop(LinkStack &S,int x);

void display(LinkStack S);

bool DecimalToOctal(int d,int &o);

bool OctalToDecimal(int o,int &d);

int main(){
    printf("\n");
    printf("7/8: %d\n",7/8);
    printf("10^4: %d\n",(int)pow(10,4));
    printf("358/10: %d\n",358/10);
    printf("358%10: %d\n",358%10);
    int o;

    DecimalToOctal(0,o);
    DecimalToOctal(7,o);
    DecimalToOctal(8,o);
    DecimalToOctal(12,o);
    DecimalToOctal(1635,o);
    DecimalToOctal(163512,o);

    int a;
    // OctalToDecimal(0,a);
    // printf("a: %d\n",a);
    // OctalToDecimal(7,a);
    // printf("a: %d\n",a);
    // OctalToDecimal(10,a);
    // printf("a: %d\n",a);
    // OctalToDecimal(14,a);
    // printf("a: %d\n",a);
    // OctalToDecimal(3143,a);
    // printf("a: %d\n",a);
    // OctalToDecimal(477270,a);
    // printf("a: %d\n",a);

    return 0;
}

bool DecimalToOctal(int d,int &o){
    LinkStack l;
    InitLinkStack(l);
    while (d>7)
    {
        push(l,d%8);
        d = d / 8;
    }
    push(l,d);
    display(l);
    return 0;
}

bool OctalToDecimal(int o,int &d){

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
    while (S!=NULL)
    {
        printf("%d",S->data);
        S = S->next;
    }
    printf("\n");
}