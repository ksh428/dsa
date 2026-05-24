class Solution {
public:
    // bool compare(vector<int>a,vector<int>b){
    //     return a[0]<b[0];
    // }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //same as maxoverlapping bridges
        //sort on width and lis on hright
        //only diff is that env cannot have same width
        sort(envelopes.begin(),envelopes.end());
        int n=envelopes.size();
        int lis[n];
        lis[0]=1;
        for(int i=1;i<n;i++){
            lis[i]=1;
            for(int j=0;j<i;j++){
                if(envelopes[j][1]<envelopes[i][1] && envelopes[j][0]<envelopes[i][0] && lis[i]<1+lis[j]){
                    lis[i]=1+lis[j];
                }
            }
        }
        int maxv=0;
        for(int x:lis){
            if(x>maxv) maxv=x;
        }
        return maxv;
    }
};
