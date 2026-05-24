#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
}*top=NULL;
void push(int x)
{
    node* t;
    t=(node *)malloc(sizeof(node));
    if(t==NULL) cout<<"stack full";
    else{
        t->data=x;
        t->next=top;
        top=t;
    }

}
void pop()
{
    if(top==NULL) cout<<"stack empty";
    else{
        node*p=top;
        top=top->next;
        free(p);

    }
}
void display()
{
    node* p;
    p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    push(10);
    push(12);
    push(6);
    pop();
    display();

}
