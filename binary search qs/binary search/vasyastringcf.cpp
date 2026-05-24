#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
bool possible(int x,int k,string s){ //return true if substring of length m is beautiful
    int a[2]={0};
    // for(int i=0;i<x-1;i++){
    //     a[s[i]-'a']++;
    // }
    // for(int i=x-1;i<s.size();i++){
    //     a[s[i]-'a']++;
    //     if(k>=min(a[0],a[1])) return true;
    //     a[s[i-x+1]]--;
    // }
    // return false;
    //the above code fails to handle the test for x=0
    //so use below code
    for(int i=0;i<x;i++) a[s[i]-'a']++;
    if(k>=min(a[0],a[1])) return 1;
    for(int i=0;i+x<s.size();i++){
        a[s[i]-'a']--;
        a[s[i+x]-'a']++;
        if(k>=min(a[0],a[1])) return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int l=0;
    int r=n;
    int ans=0;
    while(l<=r){
        int m=l+(r-l)/2;
        if(possible(m,k,s)){
            ans=max(m,ans);
            l=m+1;
        }else r=m-1;

    }
    cout<<ans<<endl;
}
