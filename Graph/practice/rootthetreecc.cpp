#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>in(n);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        --x;--y;
        in[y]++;
    }
    int c=0;
    for(int i:in) if(i==0) c++;
    cout<<c-1<<endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
}
