
class Solution {
public:
    int solve(vector<int>a,int k){
        if(k==0) return 0;
        int n=a.size();
        int tot=0;
        int diff=0;
        int j=0;
        vector<int>cnt(20002);
        for(int i=0;i<n;i++){
            if(cnt[a[i]]==0){
                cnt[a[i]]++;
                diff++;
            }else cnt[a[i]]++;
            if(diff<=k) tot+=i-j+1;
            else{
                while(j<n  and j<=i and diff>k){
                    cnt[a[j]]--;
                    if(cnt[a[j]]==0) diff--;
                    j++;
                }
                tot+=i-j+1;
            }
        }
        return tot;
    }
    int subarraysWithKDistinct(vector<int>& a, int k) {
       return solve(a,k)-solve(a,k-1);

    }
};
//see copy for exp
