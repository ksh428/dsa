#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int s[n];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        ll ans=0;
        for(int i=n-1;i>0;i--){
            ans+=abs(s[i]-s[i-1])-1;
    }
    cout<<ans<<endl;
    }
}
//1 6 11 6 10 11
