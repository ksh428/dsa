
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
void countnode(){
    int c=0;
    node* t=head;
    while(t!=NULL){
        c++;
        t=t->next;
    }
    cout<<endl;
    cout<<c;
}

void sum(){
    int s=0;
    node* t=head;
    while(t!=NULL){
        s+=t->data;
        t=t->next;
    }
    cout<<s<<endl;

}
void findmax(){
    node* t=head;
    int max=t->data;
    while(t!=NULL){
        if(t->data>max){
            max=t->data;
        }
        t=t->next;
    }
    cout<<max<<endl;
}
void lsearch(){
    cout<<"enter value"<<endl;
    int x;
    cin>>x;
    int flag=0;
    int pos=0;
    node* t=head;
    while(t!=NULL){
        if(t->data==x){
            flag=1;
            break;
        }
        t=t->next;
        pos++;
    }
    if(flag)
    {
        cout<<"found"<<" "<<pos;
    }else{
        cout<<"not found"<<endl;
    }
}
void movetofirstitem(){
    //move the searched item to first of ll
    //just for practice dont execute this
    int x;
    cin>>x;
    node* t=head;
    node* p=NULL;
    while(t!=NULL){
        if(t->data==x){
            p->next=t->next;
            t->next=head;
            t=head;

        }
        p=t;
        t=t->next;
    }
}
void findsumn(){
    node* t=head;
    int s=0;
    int n;
    cin>>n;
    int c=countnode();
    int reqpos=c-n;
    for(int i=0;i<reqpos;i++){
        t=t->next;
    }
    while(t!=NULL){
        s+=t->data;
        t=t->next;
    }



}



int main()
{
    create();
    display();
    //count();
    //sum();
    //findmax();
    //lsearch();
    findsumn();

    return 0;
}
