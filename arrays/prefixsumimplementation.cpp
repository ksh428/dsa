#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ps[n];
    ps[0]=a[0];
    for(int i=1;i<n;i++)
    {
        ps[i]=a[i]+ps[i-1];

    }
    for(int x:ps)
    {
        cout<<x<<" ";
    }

}
