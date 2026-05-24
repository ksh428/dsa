

#include <bits/stdc++.h>

#define inf 10000000

using namespace std;

bool good(int m,int c,int n,int a[]){ //is it possible to place c cows so that the min dist b/w is >=m
    int count=0;
    int pre=-inf;
    for(int i=1;i<=n;i++){
        if(a[i]-pre>=m){
            count++;
            pre=a[i];
        }
    }
    if(count>=c) return true;
    else return false;

}


int solve(int n,int c,int a[]){
    int l=0;
    int u=a[n]-a[1];//atleast 2 cows will be there
    int ans=0;
    while(l<=u){
        int m=l+(u-l)/2;
        if(good(m,c,n,a)){
            ans=max(ans,m);
            l=m+1;
        }else u=m-1;
    }
    return ans;
}

int main()
{
  int t;
  cin>>t;
  while(t--){
      int n,c;
      cin>>n>>c;
      int a[n+1];
      for(int i=1;i<=n;i++) cin>>a[i];
      sort(a+1,a+n+1);
      cout<<solve(n,c,a)<<endl;
  }
}
