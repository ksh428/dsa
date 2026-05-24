
class Solution {
public:
    const int mod=1e9+7;

    int countPairs(vector<int>& d) {
        int n=d.size();
        long long  ans=0;
        unordered_map<int,int>m;
        for(int i:d){
            for(int j=1;j<=(1<<21);j*=2){
                if(m.count(j-i)) ans+=m[j-i];
            }
            m[i]++;
        }
        return ans%mod;
    }
};
