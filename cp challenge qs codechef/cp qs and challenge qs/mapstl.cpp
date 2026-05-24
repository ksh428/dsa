#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int,string>customer;  //mao<key dt,value dt> map name;
    customer[100]="Gajender";
    customer[123]="dilip";
    customer[200]="Rajesh";
    /* or
    map<int ,string>c{ {100,"gajendra"},{123,"name"}
    ,{key,"value"}
    }; */
    map<int,string>::iterator p=customer.begin(); //using iterator to display full map
    while(p!=customer.end())
    {
        cout<<p->second<<endl;p++; //to print index/key write p->first and to print value write p->second
    }
    cout<<customer.size(); //return size
    cout<<customer.empty(); //to check whether array is empty or not
    customer.insert(pair<int,string>(206,"kc")); // to insert element first create a pair


}
