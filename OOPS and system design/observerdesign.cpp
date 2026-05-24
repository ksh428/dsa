#include <bits/stdc++.h>
#include<string>
using namespace std;
//INTERFACE= ABSTRACT CLASS IN CPP

class ISubscribe{
      public:
      virtual void notify(string s)=0;
};
class User:public ISubscribe{
      int id;
      public:
      User(int i){
            id=i;
      }
      void notify(string s){
            cout<<id<<" "<<s<<endl;
      }
};
class Group{
      list<User*>users;
      public:
      void subscribe(User* u){
            users.push_back(u);
      }
      void unsubscribe(User* u){
           users.remove(u);
      }
      void notify(string s){
            for(auto it:users){
                  it->notify(s);
            }
      }
};
int main(){
     Group* grp=new Group();
     User* u1=new User(1);
     User* u2=new User(2);
     User* u3=new User(3);
     grp->subscribe(u1);
     grp->subscribe(u2);
     grp->subscribe(u3);
     grp->notify("new msg");
     grp->unsubscribe(u1);
     grp->notify("new msg");

}

/* ALT 

#include <bits/stdc++.h>
using namespace std;

class Observer{
    public:
    virtual void notify(string s)=0;
};
class subject{
    list<Observer*>l;
    public:
    void add(Observer* o){
        l.push_back(o);
    }
    void remove(Observer* o){
        l.remove(o);
    }
    void notify(string s){
        for(auto it:l){
            it->notify(s);
        }
    }
};
class concreteobserver:public Observer{
    public:
    void notify(string s)  {
        cout<<s;
    }
};

int main() {
    concreteobserver o1;
    concreteobserver o2;
    subject s1;
    s1.add(&o1);
    s1.add(&o2);
    s1.notify("for 2 pepople");
    s1.remove(&o1);
    s1.notify("after deleting");
    
}

*/
