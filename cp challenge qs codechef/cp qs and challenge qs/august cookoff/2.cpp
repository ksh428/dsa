#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a,b;
        //we just need to input the vertices it is of no use
        for(int i=0;i<n;i++)
            cin>>a>>b;
        int ans=n;
        while(n>5){
                n/=2;
                ans+=n;

        }
        cout<<ans<<endl;
    }
}
