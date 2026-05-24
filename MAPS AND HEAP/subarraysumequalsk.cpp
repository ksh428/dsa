class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int s=0;
        int n=a.size();
        int ans=0;
        map<int,int>m;
        m[0]=1;
        for(int i=0;i<n;i++){
            s+=a[i];
           // if(s==k) ans++;
            if(m.find(s-k)!=m.end()){
                ans+=m[s-k];
            }
            m[s]++;
        }
        return ans;

    }
};
