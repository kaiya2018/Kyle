/*
    references:
        https://www.cnblogs.com/vivian187/p/15961083.html
        https://www.runoob.com/cplusplus/cpp-multithreading.html
*/



#include<iostream>
#include<pthread.h>
#include<windows.h>
using namespace std;

void* ThreadProcessing(void* argus);

int main(){
    cout<<endl;
    pthread_t t1,t2;
    int a = 1;
    int b = 2;
    cout<<"main(): creating thread 1\n";
    if (pthread_create(&t1,NULL,ThreadProcessing,(void*)&a))
    {
        cout<<"thread 1 creation failed\n";
        exit(0);
    }
    cout<<"main(): creating thread 2\n";
    if (pthread_create(&t2,NULL,ThreadProcessing,(void*)&b))
    {
        cout<<"thread 2 creation failed\n";
        exit(0);
    }

    if (pthread_detach(t1))
    {
        cout<<"thread  1 detach failed\n";
        exit(0);
    }
    if (pthread_detach(t2))
    {
        cout<<"thread 2 detach failed\n";
        exit(0);
    }
    

    cout<<"main(): main exiting\n";
    return 0;
}

void* ThreadProcessing(void* argus){
    int index = *((int*)argus);
    cout<<"thread "<<index<<" starts to run\n";
    for (int i = 0; i < 10*index; i++)
    {
        Sleep(500);
        cout<<"thread "<<index<<" going to sleep\n";
    }
    cout<<"thread "<<index<<" exiting\n";
}