
class Solution {
    //generate all possible cases as in any k bob can either win or lose
    //2^12 cases
public:
    int best;
    vector<int>ans;
    void help(int k,vector<int>a,int score,int n,vector<int>req){
        if(k==-1 or n<=0){
            if(score>best){
                best=score;
                ans=req;
            }
            return;
        }
        //lose here
        help(k-1,a,score,n,req);
        //win
        int must=a[k]+1;
        //backtracking is necessary for optimal ans
        if(must<=n){
            int old=req[k];
            req[k]=must;
            help(k-1,a,score+k,n-must,req);
            req[k]=old;
        }
    }
    vector<int> maximumBobPoints(int n, vector<int>& a) {
        best=INT_MIN;
        vector<int>req(12,0);
        int score=0;
        help(11,a,score,n,req);
        int c=0;
        for(auto it:ans) c+=it;
        if(c<n) ans[0]+=(n-c);//bob will always win
        return ans;
    }
};
