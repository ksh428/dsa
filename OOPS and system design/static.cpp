#include<bits/stdc++.h>
using namespace std;
// void fun(){
//     int y=0;//scope fun()
//     static int x;//space allocated for lifetime..continues prev val
//     cout<<x<<" "<<endl;
//     x++;
//     y++;
//     cout<<y<<" ";

// }

class Account{
   int bal;
   static float r;
   public:
   void setb(int x){
       bal=x;
   }
   static void setr(float x){
       r=x;
   }
   static void get() {cout<<r;}
};
float Account:: r=4.90;
int main(){
  Account::setr(4.56);//static mf can be called withoutobj
  Account::get();
}




//// CPP program to illustrate
// class objects as static
#include<iostream>
using namespace std;

class GfG
{
	int i = 0;

	public:
	GfG()
	{
		i = 0;
		cout << "Inside Constructor\n";
	}

	~GfG()
	{
		cout << "Inside Destructor\n";
	}
};

int main()
{
	int x = 0;
	if (x==0)
	{
		static GfG obj;
	}
	cout << "End of main\n";
}
