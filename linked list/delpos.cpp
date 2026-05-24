#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node* next;
}* head=NULL;

int delpos()
{
	int pos;
	cout<<"enter position"<<endl;
	cin>>pos;
	node* t=head;
	for(int i=1;i<pos-1;i++)
	{
		t=t->next;
	} // t has prev element
	node* t2=t->next->next;// next element
	node* temp=t->next; // element ot delete
	t->next=t2;
	
	temp->next=NULL;
	free(temp);
	
	
}


int create()
{
	// create ll uptill user continues to enter
	cout<<"enter 1 to contiunue";
	int ip;
	node* t;
	do{
		node* new1=(node*)malloc(sizeof(node));
		cout<<"enter data for the node"<<endl;
		cin>>new1->data;
		new1->next=NULL;
		if(head==NULL)
		{
			head=new1;
			t=new1;
		}
		else{
			t->next=new1;
			t=new1;
			new1->next=NULL;
		}
		cout<<"want to continue";
		cin>>ip;
		
	}while(ip!=0);
}

int display()
{
	node* t=head;
	cout<<t->data<<endl;
	while(t->next!=NULL)
	{
			t=t->next;
		cout<<t->data<<endl;
	
	}
}

int main()
{
	create();
	delpos();
	display();
	cout<<  
	
}
