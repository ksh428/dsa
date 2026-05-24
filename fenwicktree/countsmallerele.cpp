void update(int i, int v, int bit[], int n) {
      for (; i <= n; i += (i & (-i))) {
            bit[i] += v;
      }
}
int query(int i, int bit[]) {
      int ans = 0;
      for (; i > 0; i -= (i & (-i))) {
            ans += bit[i];
      }
      return ans;
}

vector<int>countNumber(int n, vector<int> &a)
{
    vector<int>ans(n);
    vector<int>t=a;
    sort(t.begin(),t.end());
    map<int,int>rank;
    int r=1;
   for(int i=0;i<n;i++){
       if(rank.find(t[i])==rank.end()){
           rank[t[i]]=r;
           r++;
       }
   }
    int sz=rank.size();
    int bit[sz+1]={0};
    //memset(bit,0,sizeof(bit));
    for(int i=n-1;i>=0;i--){
        ans[i]=query(rank[a[i]]-1,bit);
        update(rank[a[i]],1,bit,sz);
    }
    return ans;


    return ans;
}
