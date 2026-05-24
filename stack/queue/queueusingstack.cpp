

#include <bits/stdc++.h>

using namespace std;

class  Queue{
   stack<int>s1,s2;
   int size=0;
   public:
   Queue(){
       size=0;
   }
   void push(int x){
       while(!s1.empty()){
           s2.push(s1.top());
           s1.pop();
       }
       s1.push(x);
       while(!s2.empty()){
           s1.push(s2.top());
           s2.pop();
       }
       size++;
   }
   void pop(){
       if(s1.empty()){
           cout<<"emtpy";
           return;
       }
       else cout<<s1.top();
       s1.pop();
       size--;
   }
};

int main()
{
    Queue q;
    q.push(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();

}

