/*
    references:
        https://www.runoob.com/cplusplus/cpp-preprocessor.html

*/

#include<iostream>
using namespace std;


#define pi 3.14 //常量宏
#define MIN(a,b) (a<b ? a : b)//参数宏
#define DEBUG
#define MKSTR(x) #x //宏里的#会将#后的加上双引号变成字符串
#define CONCAT(x,y) x##y//##运算符会把两边的字符连接在一起变成一个新的变量名（但不是字符串）
#define CONCAT2(x,y,z) x##y##z//##运算符会把两边的字符连接在一起变成一个新的变量名(不允许拼成变量类型，如int，会报错)

int main(){
    cout<<endl;
    cout<<"pi: "<<pi<<endl;//常量宏
    cout<<"MIN(3,4): "<<MIN(3,4)<<endl;//参数宏

#ifdef DEBUG//条件编译:当已经预编译DEBUG时才执行
    cout<<"DEBUG is defined\n";
#endif

#if 1//没被注释掉的
    cout<<"commands that had'n been omitted\n";
#endif

#if 0 //被注释掉的
    cout<<"commands that had been omitted\n";
#endif

    cout<<MKSTR(1231231)<<endl;//宏里的#会将#后的加上双引号变成字符串
    cout<<MKSTR(HELLO C++)<<endl;

    int xy = 100;
    cout<<"CONCAT(x,y): "<<CONCAT(x,y)<<endl;//##运算符会把两边的字符连接在一起变成一个新的变量名（但不是字符串）
    // cout<<"CONCAT2(i,n,t): "<<CONCAT2(i,n,t)<<endl;//illegal


    //C++ 中的预定义宏
    cout<<"the value of __LINE__ : "<<__LINE__<<endl;//当前行
    cout<<"the value of __FILE__ : "<<__FILE__<<endl;//当前文件
    cout<<"the value of __DATE__ : "<<__DATE__<<endl;//当前日期
    cout<<"the value of __TIME__ : "<<__TIME__<<endl;//当前时间

    return 0;
}