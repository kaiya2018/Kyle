#include<iostream>
using namespace std;

class Time{
	public:
		Time(int Hour=0,int Minute=0,int Second=0);
		Time(const Time &T);
		Time returnCopy(Time T2);
		void Display();
	private:
		int Hour;
		int Minute;
		int Second;
		int GetHour(){
			return this->Hour; 
		}
		int GetMinute(){
			return this->Minute; 
		}
		int GetSecond(){
			return this->Second;
		}
};

Time::Time(int Hour,int Minute,int Second){
	cout<<"default constructor called\n";
	this->Hour = Hour;
	this->Minute = Minute;
	this->Second = Second;
}

Time::Time(const Time &T){
	cout<<"copy constructor called\n";
	this->Second = T.Second;
	this->Minute = T.Minute;
	this->Hour = T.Hour;
}

void Time::Display(){
	cout<<"{\n";
	cout<<"L: "<<this<<endl;
	cout<<"Hour: "<<Hour<<endl;
    cout<<"Minute: "<<Hour<<endl;
	cout<<"Second: "<<Hour<<endl<<endl;	 
}

Time Time::returnCopy(Time T2) {
	Time T1(this->GetHour(),this->GetMinute(),this->GetSecond());
	T2.GetHour();
	cout<<"Before return\n";
	return T1;
}

int main(){ //拷贝函数的三种调用情况 
	cout<<endl;
	Time T1;
	T1.Display();
	
	Time T2(10,10,10);
	T2.Display();
	
	Time T3(T2); //1.显式调用 
	T3.Display();
	
	Time T4 = T1;
	T4.Display();
	
	T2.returnCopy(T3);//2.对象作形参调用 
					  //3.对象作返回类型返回时(没有的话要在编译器加入命令[-fno-elide-constructors] from "https://blog.csdn.net/qq_42859149/article/details/108277184") 
	cout<<"After return\n";
	
	return 0; 
}
