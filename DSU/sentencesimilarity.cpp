
//DSU ON STRINGS


#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

map<string,string>parent;
map<string,int>rank;
string findparent(string s){
    if(parent.find(s)==parent.end()){
        //instead of declaring here u could have also declared by traversing the pairs then do the operation
        parent[s]=s;
        rank[s]=1;
    }
    if(parent[s]==s) return s;
    return parent[s]=findparent(parent[s]);
}
void unionn(string x,string y){
    x=findparent(x);
    y=findparent(y);
    if(x==y) return;
    if(rank[x]>rank[y]){
        parent[y]=x;
    }else if(rank[y]>rank[x]){
        parent[x]=y;
    }else{
        parent[x]=y;
        rank[y]++;
    }
}

void solve() {
    int n,m;
    cin>>n;
    vector<string>a;
    for(int i=0;i<n;i++) cin>>a[i];
    vector<string>b;
    for(int i=0;i<m;i++) cin>>b[i];
    int m;
    vector<pair<string,string>>v;
    for(int i=0;i<m;i++){
        cin>>v[i].first>>v[i].second;
        unionn(v[i].first,v[i].second);
    }
    int f=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i] or (findparent(a[i])==findparent(b[i]))){
            continue;
        }else f=1;
    }
    if(f){
        cout<<"false";
    }else cout<<"true";
}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    solve();
	return 0;
}
