class Solution {
public:
    vector<vector<int>>ans;
    //set<vector<int>>st;
    void solve(vector<int>c,int t,int i,vector<int>&temp){
        if(i==c.size()){
            if(t==0){
                    ans.push_back(temp);
                }
                return;
            }
        if(c[i]<=t){
            temp.push_back(c[i]);
            solve(c,t-c[i],i,temp);
            temp.pop_back();
        }
        solve(c,t,i+1,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int>temp;
        sort(c.begin(),c.end());
        unordered_map<int,bool>m;
        vector<int>newc;
        for(int x:c){
            if(m.find(x)==m.end()){
                newc.push_back(x);
                m[x]=1;
            }
        }
        solve(newc,t,0,temp);
        return ans;
    }
};
