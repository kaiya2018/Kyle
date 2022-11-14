/*
    references:
        https://www.runoob.com/cplusplus/cpp-signal-handling.html

*/

#include<iostream>
#include<csignal>
#include<windows.h>
using namespace std;

void SignalHandler(int signum){//中断处理
    cout<<"Interrupt signal ("<<signum<<") received\n";

    exit(signum);//退出程序
}

void SignalHandler1(int signum){//错误运算处理，如除以0
    cout<<"divided by 0,signum: "<<signum<<" received\n";

    exit(signum);
}

int main(){
    cout<<endl;

    signal(SIGINT,SignalHandler);//注册信号与信号处理函数
    signal(SIGFPE,SignalHandler1);//注册信号与信号处理函数

    //中断处理（按ctrl+C）
    // while (1)
    // {
    //     cout<<"Going to sleep\n";
        // Sleep(1000);
    // }
    
    //错误运算处理
    // int a = 1/0;

    //rise():信号生成函数
    for(int i=0;i<4;i++){
        if(i==3)
            raise(SIGINT);
    }

    return 0;
}