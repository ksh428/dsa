#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<k;i++){
        if(s[i]=='?'){
            for(int j=i+k;j<n;j+=k){
                if(s[j]!='?') {s[i]=s[j];break;}
                //break;
            }
        }
    }
    for(int i=0;i<k;i++){
        if(s[i]!='?'){
            for(int j=i+k;j<n;j+=k){
                if(s[j]=='?'){
                    s[j]=s[i];
                }else if(s[j]!=s[i]){
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    int one=0,zero=0;
    for(int i=0;i<k;i++){
        if(s[i]=='1') one++;
        if(s[i]=='0') zero++;
    }
    if(one<=k/2 and zero<=k/2) {
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;

    }


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
