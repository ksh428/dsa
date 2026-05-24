// for the 2 pointer technique towork the array has to be sorted
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int i=0;int j=n-1;
    int flag=0;
    while(i<j)
    {
        if(a[i]+a[j]==x)
            {cout<<"yes";
            flag=1;
            break;}
        else if(a[i]+a[j]<x)
            i++;
        else j--;
    }
    if(flag==0)
        cout<<"no";

}
