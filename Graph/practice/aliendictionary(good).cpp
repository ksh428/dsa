class Solution{
    public:
    vector<int>adj[27];
    void dfs(int i,vector<int>&vis,string &ans){
        vis[i]=1;
        for(int j:adj[i]){
            if(!vis[j]) dfs(j,vis,ans);
        }
        char ch=i+'a';
        ans=ch+ans;

    }
    string findOrder(string a[], int n, int k) {
    //   vector<int>adj[k];
       //small to large edge
       for(int i=0;i<n-1;i++){
           string w1=a[i];
           string w2=a[i+1];
           for(int j=0;j<min(w1.size(),w2.size());j++){
               if(w1[j]!=w2[j]){
                   adj[w1[j]-'a'].push_back(w2[j]-'a');
                   break;
               }
           }
       }
       vector<int>vis(k,0);
       string ans="";
       for(int i=0;i<k;i++){
           if(!vis[i]) dfs(i,vis,ans);
       }
       return ans;
    }
};

