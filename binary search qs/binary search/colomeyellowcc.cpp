#include<bits/stdc++.h>
typedef long long ll;
using namespace std;



bool ispossible(ll m,ll r,ll g,ll b){
    return (r-m)+(b-m)+g>=m;

}
int main(){
    int t;
    cin>>t;
    while(t--){
       ll n,r,g,b;
        cin>>n>>r>>g>>b;
        ll lb=0;
        ll ub=min(n,min(r,b));
        ll ans=0;
        while(lb<=ub){
            ll mid=lb+(ub-lb)/2;
            if(ispossible(mid,r,g,b)){
                ans=mid;
                lb=mid+1;
            }else ub=mid-1;
        }
        cout<<ans<<endl;

    }
}
