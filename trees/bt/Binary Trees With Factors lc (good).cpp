class Solution {
public:
    #define mod 1000000007
    #define ll long long
    int numFactoredBinaryTrees(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
       map<int,ll>m;
        ll ans=0;
        for(auto x:a) m[x]=1;
        for(int i=1;i<n;i++){
            int curr=0;
            for(int j=0;j<i;j++){
                if((a[i]%a[j])==0){
                    curr=(curr+(m[a[j]]*m[a[i]/a[j]])%mod)%mod;
                }
            }
            m[a[i]]=(m[a[i]]+curr)%mod;
        }
        for(auto it:m) ans=(ans+it.second)%mod;
        return (ans)%mod;
    }
};
