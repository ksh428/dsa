
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        int q;
        cin>>n>>q;
        ll currfloor=0,ans=0; //initially starts from grnd flor
        for(int i=1;i<=q;i++)
        {
            int s,d;
            cin>>s>>d;
           // int ans=0;
            ans+=abs(s-currfloor);
            ans+=abs(d-s);
            //ans+=f;
            currfloor=d;
        }
        cout<<ans<<endl;

    }
}
