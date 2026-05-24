class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    #define lli long long int
    long long int countSubarrWithEqualZeroAndOne(int a[], int n)
    {
        lli ans=0;
        unordered_map<int,int>m;
        m[0]=1;
        int s=0;
        for(int i=0;i<n;i++){
            if(a[i]==0) s+=-1;
            else s+=1;
            if(m.find(s)!=m.end()) ans+=m[s];
            m[s]++;
        }
        return ans;
    }
};
