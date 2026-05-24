#include<bits/stdc++.h>
using namespace std;
int findx(int a[],int n,int x)
{
    int lb=0;
    int ub=n-1;
    int ans=-1;
    while(lb<=ub)
    {
        int mid=lb+(ub-lb)/2;
        if(a[mid]>x)
        {
            ans=mid;
            ub=mid-1;
        }
        else
        {
            lb=mid+1;
        }
    }
    return ans;
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   int x;cin>>x;
   int value;
   value=findx(a,n,x);
   cout<<a[value];
}
