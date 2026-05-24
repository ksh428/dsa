class Solution {
public:
    void update(int i, int v, int bit[], int n) {
      for (; i <= n; i += (i & (-i))) {
            bit[i] += v;
      }
}
    //NOTES IN COPY
int query(int i, int bit[]) {
      int ans = 0;
      for (; i > 0; i -= (i & (-i))) {
            ans += bit[i];
      }
      return ans;
}
    int reversePairs(vector<int>& a) {
        int n=a.size();
        vector<long>b;
        for(long x:a) b.push_back(2*x);//imp step
        set<long>st;
        st.insert(a.begin(),a.end());
        st.insert(b.begin(),b.end());
        map<long,int>ranks;
        int r=1;
        for(long x:st){
            ranks[x]=r;
            r++;
        }
        //fenwick tree is made on ranks not original elemsnts
        //so size of bit should be ranks.size+1
        int sz=ranks.size();
        int bit[sz+1];
        int ans=0;
        memset(bit,0,sizeof(bit));
        for(int i=b.size()-1;i>=0;i--){
            ans+=query(ranks[b[i]/2]-1,bit);
            update(ranks[b[i]],1,bit,sz);

            }
        return ans;
    }
};
