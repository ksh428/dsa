
class Solution {
public:
    #define ll long long
    vector<ll>mxin,mxout;
    ll dfs1(int curr,int par,vector<int>adj[],vector<int>&p){
        ll res=0;
        for(int j:adj[curr]){
            if(j!=par){
                res=max(res,dfs1(j,curr,adj,p));
            }
        }
        res+=p[curr];
        mxin[curr]=res;
        return res;
    }
    void dfs2(int curr,int par,vector<int>adj[],vector<int>&p){
        multiset<ll>st;
        for(int j:adj[curr]){
            if(j!=par) st.insert(mxin[j]);
        }
        for(int j:adj[curr]){
            if(j!=par){
                ll val=mxin[j];
                st.erase(st.find(val));
                ll op1;
                if(st.empty()) op1=0;
                else op1=*(st.rbegin());
                ll op2=mxout[curr];
                mxout[j]=max(op1,op2)+p[curr];
                st.insert(val);
                dfs2(j,curr,adj,p);
            }
        }

    }
    long long maxOutput(int n, vector<vector<int>>& e, vector<int>& p) {
        mxin.clear(),mxout.clear();
        mxin.resize(n,0);
        mxout.resize(n,0);
        vector<int>adj[n];
        for(auto it:e){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs1(0,-1,adj,p);//for childs of tree rooted at currnode
        dfs2(0,-1,adj,p);//for parent tree of the node
        ll ans=0;
        for(int i=0;i<n;i++){
            ll curr=max(mxin[i],mxout[i]+p[i])-p[i];
            ans=max(ans,curr);
        }
        return ans;

    }
};
