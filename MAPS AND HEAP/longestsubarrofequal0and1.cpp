class Solution{
  public:
    int maxLen(int a[], int n)
    {
        unordered_map<int,int>m;
        m[0]=-1;
        int s=0;
        int ans=0;
        for(int i=0;i<n;i++){
            s+=(a[i]==0)?-1:1;
            if(m.find(s)!=m.end()){
                ans=max(ans,i-m[s]);
            }
            else m[s]=i;
        }
        return ans;
    }
};
