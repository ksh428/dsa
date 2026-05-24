#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	    int n,k;
	    cin>>n>>k;
	    vector<int>a(n);
	    for(int i=0;i<n;i++) cin>>a[i];
	    unordered_set<int>s(a.begin(),a.end());
    vector<int>dp(k+1,0); //0:losing state
    for(int i=1;i<=k;i++){
        for(int j:a){
            if(j>i) continue;
            else{
                if(dp[i-j]==0) {
                    dp[i]=1;
                    break;
                }
            }
        }
    }
    (dp[k]==1)?cout<<"first":cout<<"second";
}
