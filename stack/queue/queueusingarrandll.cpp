

#include <bits/stdc++.h>
#define MAX 100

using namespace std;
int q[5];
int c;
int n=5;
int f=0,r=0;
void push(int x){
    if(c==n){
        cout<<"queue full";
        return;
    }
    q[r%n]=x;
    r++;
    c++;
}
int pop(){
    if(c==0) {
        cout<<"empty";
        return -1;
    }
    int t=q[f%n];
    q[f%n]=-1;
    f++;
    c--;
    return t;
}
int top(){
    if(c==0) return -1;
    return q[f%n];
}
int main()
{
    push(4);
    push(5);
    push(6);
    cout<<pop();
  //  cout<<top();
     cout<<pop();
      cout<<pop();
       cout<<pop();

}


///////

#include <bits/stdc++.h>
#define MAX 100

using namespace std;
class Node{


     public:
      int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
class Queue{

    Node* front;
    Node* back;
     public:
    Queue(){
        front=NULL;
        back=NULL;
    }
    void push(int x){
         Node* t=new Node(x);
        if(!front){
            front=t;
            back=t;
        }else{
            back->next=t;
            back=t;
        }
    }
    int  pop(){
        if(!front) return -1;
        Node* t=front;
        front=front->next;
        int val=t->data;
        delete t;
        return val;
    }
    int top(){
        if(!front) return -1;
       return front->data;
    }
};

int main(){
        Queue q;
        q.push(5);
        q.push(2);
        q.push(3);
        q.push(15);
        cout<<q.pop();
        cout<<q.top();
}
