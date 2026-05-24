class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int bd=0,sd=0,profit=0;
        for(int i=1;i<n;i++){
            if(p[i]>=p[i-1]){
                sd++;
            }else{
                profit+=p[sd]-p[bd];
                sd=bd=i;
            }
        }
        profit+=p[sd]-p[bd];//when lst is not dec
        return profit;
    }
};
