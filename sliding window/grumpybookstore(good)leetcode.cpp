
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int x) {
        int n=customers.size();
        int normaladd=0,ans=0,extraadd=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) normaladd+=customers[i];
            if(grumpy[i]) extraadd+=customers[i];
            if(i>=x){
                //slide the window //slide only the lower part
                //as upper is already in right place
                if(grumpy[i-x]){
                    extraadd-=customers[i-x];
                }
            }
            ans=max(ans,extraadd);
        }
        return normaladd+ans;

    }
};
