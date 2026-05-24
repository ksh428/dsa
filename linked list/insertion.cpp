#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node* next;
}*head =NULL;

int insbeg()
{
	node* new1,current;
	new1=(node*)malloc(sizeof(node));
	cout<<"enter data for the node"<<endl;
	cin>>new1->data;
	new1->next=NULL;
	if(head==NULL)//ther is no element present
	{
		new1->next=head;
		head=new1;
	}
	else{
		new1->next=head;
		head=new1;
	}
}

int insend()
{
	
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
	insbeg();
	display();
	//insend();
	//display();
}
