

#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* next;
    node(int x){
        data=x;
        next=NULL;
    }
};

void inserthead(node*&head,int x){
    node*n=new node(x);
    if(!head) {
        n->next=n;
        head=n;
        return;
    }
    node* t=head;
    while(t->next!=head) t=t->next;
    t->next=n;
    n->next=head;
    head=n;
}
void insertattaail(node*&head,int x){
    if(!head){
        inserthead(head,x);
        return;
    }
    node* n=new node(x);
    node* t=head;
    while(t->next!=head) t=t->next;
    t->next=n;
    n->next=head;
}
void deletebeg(node*&head){
    node* t=head;
    while(t->next!=head) t=t->next;
    node* p=head;
    head=head->next;
    t->next=head;
    delete p;
}

void deletepos(node*&head,int pos){
    node* t=head;
    if(pos==1){
        deletebeg(head);
    }
    int c=1;
    while(c!=pos-1){
        c++;
        t=t->next;
    }
    node* p=t->next;
    t->next=t->next->next;
    delete p;
}


void display(node*&head){
    node* t=head;
    do{
        cout<<t->data<<" ";
    }while(t!=head);
}
int main()
{

}
