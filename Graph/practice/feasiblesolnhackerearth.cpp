//FEASIBLE SOLUTIONS

#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000001];
int vis[1000001],cc[1000001];
int currcomp;
void dfs(int node){
    vis[node]=1;
    cc[node]=currcomp;
    for(int child:adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        currcomp=0;
        vector<pair<int,int>>p;
        int n,k,a,b;
        string op;
        cin>>n>>k;
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=0;i<=k;i++){
            cin>>a>>op>>b;
            if(op=='='){
                adj[a].push_back(b);
                adj[b].push_back(a);
            }else{
                p.push_back({a,b});
            }
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                currcomp++;
                dfs(i);

            }
        }
        bool flag=true;
        for(int i=0;i<p.size();i++){
            int a=p[i].first();
            int b=p[i].second();
            if(cc[a]==cc[b]){
                flag=false;
                break;
            }

        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

}
