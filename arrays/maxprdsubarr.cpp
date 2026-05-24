class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n=a.size();
        int maxeh=a[0];
        int mineh=a[0];
        int ans=a[0];
        for(int i=1;i<n;i++){

            int t=maxeh;
            maxeh=max({a[i],a[i]*maxeh,a[i]*mineh});
            mineh=min({a[i],a[i]*t,a[i]*mineh});
            ans=max(ans,maxeh);
        }
        return ans;
    }
};
