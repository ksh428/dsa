
#include<iostream>
using namespace std;

class Person{
    public:
    virtual void say()=0;
    void f1{
        cout<<"jwebfe";
    }
};

class stud:public Person
{
    // void say(){
    //     cout<<"gfgfg"; //1st option
    // }
    virtual void say()=0;  //2nd option
};

int main(){

}

