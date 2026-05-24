

#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* prev;
    node* next;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertathead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    if(!head) head->prev=n;
    head=n;
}

void delbeg(node* &head){
    node* t=head;
    head=head->next;
    head->prev=NULL;
    t->next=NULL;
    delete t;
}

void delpos(node* &head,int pos){
    if(pos==1){
        delbeg(head);
    }
    node* t=head;
    int c=0;
    while(t!=NULL and c!=pos){
        t=t->next;
        c++;
    }
    t->prev->next=t->next;
    if(t->next!=NULL) t->next->prev=t->prev;
    delete t;
}

void inserttail(node* &head,int val){
    if(!head){
        insertathead(head,val);
    }
    node* newnode=new node(val);
    node* t=head;
    while(t->next!=NULL) t=t->next;
    t->next=newnode;
    newnode->prev=t;

}

int main()
{

}

