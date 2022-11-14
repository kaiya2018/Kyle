/*
    references:
        https://www.runoob.com/cplusplus/cpp-namespaces.html
*/

#include<iostream>
using std::cout;//只为cout命名，其他的还是要加std

namespace first_namespace{
    void print(){
        cout<<"print in first_namespace\n";
    }
}

namespace second_namespace{
    void print(){
        cout<<"print in second_namespace\n";
    }
}

namespace third_namespace{//嵌套的命名空间
    void print(){
        cout<<"print in third_namespace\n";
    }
    namespace forth_namespace{
    void print(){
        cout<<"print in forth_namespace\n";
    }
}
}

// using namespace first_namespace;
using namespace third_namespace::forth_namespace;//嵌套的命名空间声明

int main(){
    cout<<std::endl;
    // first_namespace::print();
    // second_namespace::print();

    print();

    return 0;
}