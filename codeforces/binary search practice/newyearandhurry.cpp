#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int remtime=240-k;
    int s=0;
    int ans=0;
    vector<int>v;
    for(int i=1;i<=n;i++){
        v.push_back(5*i);
    }
    for(int i=0;i<n;i++){
        if((s+v[i])<=remtime){
            s+=v[i];
            ans++;
        }
    }
    cout<<ans<<endl;
}
