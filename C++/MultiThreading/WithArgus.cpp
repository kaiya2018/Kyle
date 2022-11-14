//向线程传送参数


#include<iostream>
#include<pthread.h>
using namespace std;

#define NUM_THREADS 5

struct person{
    char *name;
    int age;
};

void* ThreadProcessing(void* argus);

int main(){
    cout<<endl;

    pthread_t threads[NUM_THREADS];
    struct person persons[NUM_THREADS];
    int code;
    for (int i = 0; i < NUM_THREADS; i++)
    {
        persons[i].age = 10*i;
        persons[i].name = (char*)"Kyle";
        cout<<"main(): creating thread "<<i<<endl;
        code = pthread_create(&threads[i],NULL,ThreadProcessing,(void*)&persons[i]);
        if(code){
            cout<<"Thread creation failed\n";
            exit(0);
        }
    }
    cout<<"main(): program exiting\n";
    pthread_exit(NULL);
    return 0;
}

void* ThreadProcessing(void* argus){
    struct person p = *((person*)argus);
    cout<<"name: "<<p.name<<", age:"<<p.age<<endl;
}