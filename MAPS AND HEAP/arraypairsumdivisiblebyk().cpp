class Solution {
  public:
    bool canPair(vector<int> a, int k) {
        int n=a.size();
        if(n&1) return 0;

        unordered_map<int,int>m;
       for(int i=0;i<n;i++){
           m[a[i]%k]++;
       }
       for(int i=0;i<n;i++){
           int r=a[i]%k;
           if(r==0){
               if(m[r]%2!=0) return 0;
           }else if(m[r]!=m[k-r]){
               return 0;
           }
       }
       return 1;
    }
};
