

#include <bits/stdc++.h>
#define MAX 100

using namespace std;

class Stack{
    int top;
    public:
    int a[MAX];
    Stack(){
        top=-1;
    }
    void push(int a);
    int pop();
    int peek();
    bool empty();
};

void Stack::push(int x){
    top++;
    a[top]=x;
}
int Stack::pop(){
    return (top==-1)?-1:a[top--];
}
int Stack::peek(){
    return (top==-1)?-1:a[top];
}
bool Stack::empty(){
    return top==-1;
}
int main()
{
    Stack s;
    s.push(3);
    s.push(4);
    s.push(6);
    cout<<s.pop();
    cout<<s.peek();
    cout<<s.empty();

}
//ll


#include <bits/stdc++.h>
#define MAX 100

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
Node* head=NULL;

Node* newnode(int x){
    Node* t=new Node();
    t->data=x;
    t->next=NULL;
    return t;
}
void push(int x){
    Node* t=newnode(x);
    t->next=head;
    head=t;
}
int pop(){
    if(!head) return -1;
    Node* t=head;
    head=head->next;
    int popd=t->data;
    delete t;
    return popd;
}
bool empty(){
    return head==NULL;
}
int peek(){
    if(!head) return -1;
    return head->data;
}




int main()
{
    push(10);
    push(11);
    push(20);
    while(!empty()){
        cout<<head->data<<" ";
        pop();
    }
    cout<<peek();
    cout<<pop();
    cout<<empty();

}

