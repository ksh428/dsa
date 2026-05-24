

#include <bits/stdc++.h>

using namespace std;

class Stack{
    queue<int>q1,q2;
    int size;
    public:
    Stack(){
        size=0;
    }
    void push(int x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
        /* queue<int>q=a;
        a=b;
        b=q;
        */
    }
    void pop(){
        if(q1.empty()) cout<<"empty";
        else q1.pop();
        size--;
    }
    void top(){
        if(q1.empty()) cout<<"empty";
        else cout<<q1.front();
    }
    int size() {
        return size;
    }

}

int main()
{

}

