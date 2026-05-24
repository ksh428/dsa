#include<iostream>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        int n;cin>>n;
        if(n%2==0)
      {
        for(int i=0;i<n;i=i+2)
        {
            char z=s[i];
            s[i]=s[i+1];
            s[i+1]=z;
        }
       }
        else{

         for(int i=0;i<n-1;i=i+2)
        {
            char z=s[i];
            s[i]=s[i+1];
            s[i+1]=z;
        }
            }

       for(int i=0;i<n;i++)
       {
           char x=s[i];
           int v=int x;
           int index=x-97;
           int req=25-index;
           req=req+97;
           char ch=char(req);
           cout<<ch;
       }
      cout<<endl;
    }
}
