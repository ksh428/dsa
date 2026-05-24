#include<bits/stdc++.h>
#include <thread>
#include <mutex>
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;
//SINGLETON DESIGN PATTERN : ONLY ONE INSTANCE OF THE CLASS AND MULTIE OBEJCTS CAN BE CREATED

class A{
     A() { //make the constructor private
           c++;
           cout<<"instance no. "<<c<<endl;

     }
     A(const A& obj);//make the copy constructor privte
     A operator=(const A& obj); //make sure = overloading is not possible
     static A* instance;
     static int c,c1;
     static mutex mymutex;

 public:
     static A* getA();//if we dont make it static we wont be able to access the instance
     void display(){
           c1++;
           cout<<"obj created "<<c1<<endl;
     }
};
mutex A::mymutex;

A* A::instance=NULL;
int A::c=0;
int A::c1=0;
A* A::getA(){
      if(instance==NULL){
            mymutex.lock(); //THREAD SAFE SINGLETON
            instance=new A();
            mymutex.unlock();
      }
      return instance;

}
void user1logs(){
      A* a1=A::getA();
      a1->display();
}
void user2logs(){
      A* a2=A::getA();
      a2->display();
}
int main(){
     thread t1(user1logs);
     thread t2(user2logs);
     t1.join();
     t2.join();
}
