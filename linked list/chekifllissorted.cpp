//check if ll is sorted

#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
}*head=NULL;

void create(){
    node*t;
    int ip;
    cout<<"enter 1 to create"<<endl;
    do{
        node* new1=(node*)malloc(sizeof(node));
        cout<<"enter data"<<endl;
        cin>>new1->data;
        new1->next=NULL;
        if(head==NULL){
            head=new1;
            t=new1;
        }else{
            t->next=new1;
            t=new1;
            new1->next=NULL;

        }
        cout<<"want to continue"<<endl;
        cin>>ip;

    }while(ip!=0);
}

void display(){
    node* t=head;
    while(t!=NULL){
        cout<<t->data;
        t=t->next;
    }
    cout<<endl;

}
void issorted(){
    int flag=0;
    node*t=head;
    t=t->next;
    node*p=head;
    while(t!=NULL){
            if((p->data) > (t->data)){
                flag++;
                break;

            }
            t=t->next;
            p=p->next;
    }
    if(flag){
        cout<<"no"<<endl;
    }else cout<<"yes"<<endl;

}
void removeduplicates(){
    node* t=head->next;
    node*p=head;
    while(t!=NULL){
        if(t->data!=p->data){
                p=t;
        t=t->next;
        }else{
            p->next=q->next;
            delete p;
            p=p->next;
        }
    }
}
void reversell(){
    //reverse ll by reversing links
    node* p=head;
    node*q=NULL;
    node* r=NULL;
    while(p!=NULL){
            //sliding
        r=q;
        q=p;
        p=p->next;
    // reverse link
    q->next=r;
    }
    head=q;
    //always change the link from the middle pointer!!!!
}


int main()
{
    create();
    display();
    //issorted();
    //removeduplicates();
    reversell();

    return 0;
}

