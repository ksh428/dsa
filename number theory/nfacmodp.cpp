#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

//N!%P

int power(int n,int b,int p){// n^bmodp
      if(b==0) return 1;
      int t=power(n,b/2,p);
      int ans=1;
      if(b%2==0){
            ans=((t%p)*(t%p))%p;
      }else{
            ans=((t%p)*(t%p))%p;
            ans=((ans%p)*(n%p))%p;
      }
      return ans%p;
}

void solve(){
      int n,p;
      cin>>n>>p;
      if(n>=p){
            cout<<0<<endl;
            return;
      }
      int f=1;
      int i=1;
      while(n+i<=p-1){
            int inv=power(n+i,p-2,p);
            f=(f*inv)%p;
            i++;
      }
      f*=-1;
      f+=p;
      cout<<f<<endl;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
  return 0;
}
