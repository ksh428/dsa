// insert element in sorted linked list
//deletion

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
void ins2(){
    int x;
    cout<<"enter element"<<endl;
    cin>>x;
    node* t=head;
    node*p=NULL;
    while(t && (t->data)<x){
            p=t;
        t=t->next;
    }
    node* new2=new node;
    new2->data=x;
    p->next=new2;
    new2->next=t;


}
void deletefirat(){
    node*t=head;
    head=head->next;
    delete p;
}
void deletepos(){
    cout<<"enter pos"<<endl;
    int pos;
    cin>>pos;
    node*t=head;
    node*p=NULL;
    for(int i=0;i<pos-1;i++){
            p=t;
            t=t->next;

    }
    p->next=t->next;
    delete t;
}

int main(){
    int a[]={1,2,3,4,5,6,7,9,10,11};
    int n=sizeof(a)/sizeof(a[0]);
    create(a,n);
    display();
    ins2();
    display();
    deletefirat();
    display();
    deletepos();


}
