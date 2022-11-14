



#include<iostream>
#include<pthread.h>
using namespace std;

#define NUM_THREAD 5

void* thread(void* ar);

int main(){
    cout<<"\n";
    pthread_t tids[NUM_THREAD];//创建一组线程对象
    int index[NUM_THREAD];
    int code;
    for (int i = 0; i < NUM_THREAD; i++)
    {
        index[i] = i;
        cout<<"main(): creating thread "<<i<<endl;
        code = pthread_create(&tids[i],NULL,thread,(void*)&index[i]);//创建线程：参数1：线程对象的地址                                                                
        if (code!=0)                                                          //参数2：                                                                    
        {                                                                     //参数3：该线程所要运行的函数（返回类型必须是void*）
           cout<<"Thread creation failed\n";                                  //参数4：该函数所需要的参数（必须是void*类型）（没有参数则为NULL）
           exit(0);
        }
    }
    
    pthread_exit(NULL); //pthread_exit()用于防止在其他线程正在运行时main()结束后程序自动结束
    return 0;
}

void* thread(void* ar){
    int index = *((int*)ar);
    cout<<"Thread ID: "<<index<<endl;

    pthread_exit(NULL);
}