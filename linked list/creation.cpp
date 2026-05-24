
//todo:delend() not working properly....
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node* next;

}*head=NULL;

int create()
{
	// create ll uptill user continues to enter
	cout<<"enter 1 to contiunue"<<endl;
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
	while(t !=NULL)
	{
			t=t->next;
		cout<<t->data<<endl;

	}
}

int insbeg()
{
	node* new1;
	new1=(node*)malloc(sizeof(node));
	cout<<"enter data for the node"<<endl;
	cin>>new1->data;
	new1->next=NULL;
	if(head==NULL)//ther is no element present
	{
		//new1->next=head;
		//head=new1;
		head=new1;
	}
	else{
		new1->next=head;
		head=new1;
	}
}

int insend()
{
	node* new1;
	new1=(node*)malloc(sizeof(int));
	cout<<"enter data"<<endl;
	cin>>new1->data;
	new1->next=NULL;
	node* t=head;
	if(head==NULL) // no ele present
	{
		head=new1;
	}
	else{
		// element sare present
		while(t !=NULL)
		{
			t=t->next;
		}
		t->next=new1;

	}
}
int inspos() // assuming position starting from 1..
{
	int pos;
	cout<<"enter position"<<endl;
	cin>>pos;
	node* new1;
	new1=(node*)malloc(sizeof(node));
	cout<<"enter data for this position"<<endl;
	cin>>new1->data;
	node* temp=head;
	for(int i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	node* t;
	t=temp->next;
	temp->next=new1;
	new1->next=t;
}

int delbeg()
{

node* t=head;
head=head->next;
t->next=NULL;
free(t);
}

int delend()
{
	node* t=head;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=NULL;
	free(t);
}
int len()
{
    int c=0;
		node* t=head;c++;
	while(t->next!=NULL)
	{
		t=t->next;
		c++;
	}
	t->next=NULL;
//	cout<<c;

}
int searchele() // func to search ele in ll
{
	cout<<"enter ele"<<endl;
	int ele;
	cin>>ele;
	node* t=head;
	int pos=1;

	    while(t->next!=NULL)
	    {

	    	if(t->data==ele)
	    	{
	    		cout<<"element found at "<<pos;
	    		break;

			}
			pos++;
			t=t->next;
		}

}
int getnnode()// function to get nth node
{
	cout<<"enter n"<<endl;
	int n;
	cin>>n;
	node* t=head;
	int l=len();
	if(n>l)
	cout<<"not possible";
	else{
		for(int i=1;i<n-1;i++)
		{
			t=t->next;
		}
		t=t->next;
		cout<<"data"<<t->data<<endl;
	}

}
/*int checkpalindrome(){
	node* beg=head;
	node* end =head;
	while(end->next!=NULL)
	{
		end=end->next;
	}
	while(beg!=end)
	{
		if(beg->next==end)
	}
} */

int removedup1() // remove dup from sorted ll
{
	node* curr=head;
	node* temp; // assuming indexing from 0
	// using stl
	while(curr->next!=NULL)
	{
        if(curr->data==curr->next->data)
        {
        	temp=curr->next->next;
        	curr->next=NULL;
        	free(curr->next);
        	curr->next=temp;
		}
		else{
			curr=curr->next;
		}

	}
	// display in set
//	for(auto x=s.begin();x!=s.end();x++)
//	cout<<*x<<" ";


}


int main()
{
	create();

/*	insbeg();
	insend();
	inspos();
	cout<<"UPTIL NOW"<<endl; */
	display();
/*	cout<<"DELETION"<<endl;
	delbeg();
	delend();
	display(); */
	//len();
//	searchele();
//	getnnode();
//	checkpalindrome();
//	removedup1();

}
