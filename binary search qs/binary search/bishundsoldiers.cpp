#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q,sum=0,c=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>q;
    int x;
    while(q--)
    {
        cin>>x;
        for(int i=0;i<n;i++)
        {
            if(a[i]<x)
            {
                c++;
                sum+=a[i];
            }

        }
       /* int l=0,u=n-1;
        while(l<=u)
        {
            int m=(l+u)/2;
            if(a[m]<=x)
            {
                c++;
            }
            if(a[m]>x)
            {
                u=m-1;
            }
        } */
         cout<<c<<" "<<sum<<endl;
    }
}
