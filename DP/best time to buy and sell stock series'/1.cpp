
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int maxprofit=0;
        int minstock=INT_MAX;
        for(int i=0;i<n;i++){
            if(a[i]<minstock) minstock=a[i];
            else{
                maxprofit=max(maxprofit,a[i]-minstock);
            }

        }
        return maxprofit;

    }
};
