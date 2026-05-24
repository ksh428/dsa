//https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-for-amazon-alexa/problems/#

class Solution {
  public:
  vector<int>adj[100001];
  int level[100001];
  vector<int>v;
  unordered_map<int,int>first,last;
  void dfs(int i,int p,int lvl){
      level[i]=lvl;
      v.push_back(i);
      for(int j:adj[i]){
          if(j!=p){
              dfs(j,i,lvl+1);
          }
      }
      v.push_back(i);
  }
    vector<int> solve(int n, int q, vector<vector<int> > &edge,vector<vector<int> > &query) {
        v.clear();
        first.clear();last.clear();
        for(int i=0;i<100001;i++) adj[i].clear();
        for(int i=0;i<100001;i++) level[i]=0;
       // vector<int>adj[n];
        for(auto it:edge){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,-1,0);
        int i=0;
        for(auto it:v){
            if(first.find(it)==first.end()) first[it]=i;
            last[it]=i;
            i++;
        }
        vector<int>ans;
        int pref[v.size()];
        int suf[v.size()];
        pref[0]=level[v[0]];
        for(int i=1;i<v.size();i++) pref[i]=max(pref[i-1],level[v[i]]);
        suf[v.size()-1]=level[v.back()];
        for(int i=v.size()-2;i>=0;i--) suf[i]=max(suf[i+1],level[v[i]]);
        for(auto it:query){
            int u=it[0];
            int v1=it[1];
            if(level[u]>level[v1]){
                int lmax=(first[u]-1>=0)?pref[first[u]-1]:0;
                int rmax=(last[u]+1<v.size())?suf[last[u]+1]:0;
                ans.push_back(max(lmax,rmax));
            }else{
                int lmax=(first[v1]-1>=0)?pref[first[v1]-1]:0;
                int rmax=(last[v1]+1<v.size())?suf[last[v1]+1]:0;
                ans.push_back(max(lmax,rmax));
            }
        }
        return ans;
    }
};
