class Solution {
public:
    vector<int>a;
    int st;
    int ans;
    vector<int>sess;
    void dfs(int i){
        if(sess.size()>=ans) return;
        if(i==a.size()){
            int res=sess.size();
            ans=min(ans,res);
            return;
        }
        for(int j=0;j<sess.size();j++){
            if(sess[j]+a[i]<=st){
                sess[j]+=a[i];
                dfs(i+1);
                sess[j]-=a[i];
            }
        }
        sess.push_back(a[i]);
        dfs(i+1);
        sess.pop_back();
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        a=tasks;
        ans=a.size();
        st=sessionTime;
        dfs(0);
        return ans;

    }
};
