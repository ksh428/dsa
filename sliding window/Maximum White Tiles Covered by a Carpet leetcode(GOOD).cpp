class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& a, int len) {
        int n=a.size();
        //use modified sliding window
        int ans=0;
        sort(a.begin(),a.end());
        int j=0;
        //try to place the carpet in range j..i
        int cover=0;
        for(int i=0;i<n;){
            if(i==j or len+a[j][0]>a[i][1]){
                cover+=min(len,a[i][1]-a[i][0]+1);
                ans=max(ans,cover);
                i++;//continue the window
            }else{
                int partial=max(0,a[j][0]+len-a[i][0]);
                ans=max(ans,cover+partial);
                cover-=a[j][1]-a[j][0]+1;//slide the window
                j++;

            }
        }
        return ans;

    }
};
