

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int ans=0;
    unordered_map<string,int>m; //key,idx
    int c0=0,c1=0,c2=0;
    int d10=c1-c0;
    int d21=c2-c1;
    string key=to_string(d21)+"#"+to_string(d10);
    m.insert({key,-1});
    for(int i=0;i<n;i++){
        if(a[i]==0){
            c0++;
        }else if(a[i]==1){
            c1++;
        }else{
            c2++;
        }
        d10=c1-c0;
        d21=c2-c1;
        string key=to_string(d21)+"#"+to_string(d10);
        if(m.find(key)!=m.end()){
            ans=max(ans,i-m[key]);
        }else{
            m[key]=i;
        }
    }
    cout<<ans;
}

