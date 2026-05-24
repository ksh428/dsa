#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;

}*head=NULL;

void create(int a[],int n){
    node*t=head;
    for(int i=0;i<n;i++){
        node* new1=new node;
        new1->data=a[i];
        new1->next=NULL;
        if(head==NULL){
            head=new1;
            t=new1;
        }else{
            t->next=new1;
            t=new1;
            new1->next=NULL;
        }


    }
}
void display(){
    node* t=head;
    while(t!=NULL){
        cout<<t->data;
        t=t->next;
    }
    cout<<endl;

}

void checkforloop(){
    node* p=head;
    node* q=head;
    do{
    p=p->next;
    q=q->next;
    if(q!=NULL){
        q=q->next;
    }


    }while(p && q);
    if(p==q){
        cout<<"yes loop"<<endl;
    }else{
    cout<<"no";
    }
}



int main(){
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    create(a,n);
    display();
    //create the loop
    node*t1;
    node*t2;
    t1=head->next->next;
    t2=head->next->next->next->next;
    t2->next=t1;
    checkforloop();

}
