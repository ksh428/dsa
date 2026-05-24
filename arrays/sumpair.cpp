#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n;
    cin>>k;
    ll a[n];int flag=0;
    ll hash[1000001]={0};
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll i=1;i<1000001;i++)
    {
        hash[a[i]]++;
    }
    for(ll j=1;j<1000001;j++)
    {
        if((k-j)<1000001)
        {
            if((k-j)==0)
                break;
            else if ((k-j)==j)
            {
                if(hash[j]>1)
                {
                    flag =1;
                }
            }
            else if(hash[k-j]>0 && hash[j]>0)
            {
                flag =1;
            }
        }
    }
    if(flag)
        cout<<"yes";
    else
        cout<<"no";
}
