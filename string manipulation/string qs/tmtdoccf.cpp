#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
#define endl "\n"
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ct=0;
    int cm=0;
    bool f1=true;
    for(char c:s){
        if(cm>ct){
           f1=false;
           break;
        }
        if(c=='T') ct++;
        if(c=='M') cm++;
    }
    if(f1==false){
        cout<<"NO"<<endl;
        return;
    }
    if(2*cm!=ct){
        cout<<"NO"<<endl;
        return;
    }
    cm=ct=0;
    for(int i=n-1;i>=0;i--){
        if(cm>ct){
            f1=false;
            break;
        }
        if(s[i]=='M') cm++;
        if(s[i]=='T') ct++;
    }
    if(f1==false){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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
