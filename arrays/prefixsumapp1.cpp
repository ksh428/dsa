// application of prefix sum
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    int ps[n];
    ps[0]=a[0];
    for(int i=1;i<n;i++)
    {
        ps[i]=a[i]+ps[i-1];
    }
    int index;
    for(int i=0;i<n;i++)
    {
        if(ps[i]==(s/2))
            index=i;
    }
    cout<<index;



}

