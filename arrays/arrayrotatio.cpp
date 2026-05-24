#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d;
    cout<<"enter value of n and d"<<endl;
    cin>>n>>d;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
   int j=n-d;
   int p=0;
   for(int i=0;i<n;i++)
   {
       if(i<d)
       {
        if(j<d)
          {a[j]=a[i];
           j++;
          }
       }

       else{
        a[p]=a[i];
        p++;
       }
   }
   for(int i=0;i<n;i++)
   {
       cout<<a[i];
   }
}
