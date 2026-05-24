class Solution {
public:
    int maxProfit(vector<int>& a, int f) {
        int n=a.size();
        int bsp=-a[0];
        int ssp=0;
        for(int i=1;i<n;i++){

            if(bsp<ssp-a[i]){
                bsp=ssp-a[i];
            }
            if(ssp<bsp+a[i]-f){
                ssp=bsp+a[i]-f;
            }
        }
        return ssp;
    }
};
