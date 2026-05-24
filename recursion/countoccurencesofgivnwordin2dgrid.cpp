
class Solution{
    public:
    int n,m;
    int dfs(int i,int j,vector<vector<char>>&a,string t,int ix){
        if(i<0 or j<0 or i>=n or j>=m or a[i][j]!=t[ix]) return 0;
        if(ix==t.size()-1) return 1;
        int ans=0;
        char c=a[i][j];
        a[i][j]='%';
        ans+=dfs(i+1,j,a,t,ix+1);
        ans+=dfs(i,j+1,a,t,ix+1);
        ans+=dfs(i-1,j,a,t,ix+1);
        ans+=dfs(i,j-1,a,t,ix+1);
        a[i][j]=c;
        return ans;

    }
    int findOccurrence(vector<vector<char> > &a, string t){
        n=a.size();
        m=a[0].size();
        int len=t.size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                c+=dfs(i,j,a,t,0);
            }
        }
        return c;
    }
};
