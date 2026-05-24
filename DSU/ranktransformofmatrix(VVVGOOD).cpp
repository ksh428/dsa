class Solution {
public:
    pair<int,int>par[501][510];
    int rank[501][510];
    pair<int,int>find(pair<int,int>a){
        if(par[a.first][a.second]==a) return a;
        return par[a.first][a.second]=find(par[a.first][a.second]);
    }
    void unionn(pair<int,int>a,pair<int,int>b){
        a=find(a);
        b=find(b);
        if(rank[a.first][a.second]>rank[b.first][b.second]){
            par[b.first][b.second]=a;
        }else if(rank[a.first][a.second]<rank[b.first][b.second]){
            par[a.first][a.second]=b;
        }else{
            par[b.first][b.second]=a;
            rank[a.first][a.second]++;
        }
    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& a) {
        int m=a.size();
        int n=a[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                par[i][j]={i,j};
                rank[i][j]=0;
            }
        }
        //row
        for(int i=0;i<m;i++){
            map<int,pair<int,int>>mp;
            for(int j=0;j<n;j++){
                if(mp.find(a[i][j])!=mp.end()){
                    unionn(mp[a[i][j]],{i,j});
                }else mp[a[i][j]]={i,j};
            }
        }
        //col
        for(int j=0;j<n;j++){
            map<int,pair<int,int>>mp;
            for(int i=0;i<m;i++){
                if(mp.find(a[i][j])!=mp.end()){
                    unionn(mp[a[i][j]],{i,j});
                }else mp[a[i][j]]={i,j};
            }
        }
        //union end
        vector<pair<int,int>>v[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                auto x=find({i,j});
                v[x.first][x.second].push_back({i,j});

            }
        }
        map<int,vector<vector<pair<int,int>>>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j].size()==0) continue;
                else{
                    mp[a[i][j]].push_back(v[i][j]);
                }
            }
        }
        //map guarantees that all the smallers values are at first
        vector<int>row(m,0),col(n,0);
        for(auto it:mp){
            auto l=it.second;
            for(auto i:l){
                //a cmponent
                int r=0;
                for(auto j:i){
                    r=max(r,max(row[j.first],col[j.second])+1);
                }
                for(auto j:i){
                    ans[j.first][j.second]=r;
                    row[j.first]=r;
                    col[j.second]=r;
                }
            }
        }
        return ans;

    }
};
