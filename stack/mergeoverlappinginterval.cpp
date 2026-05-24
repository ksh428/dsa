class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>>ans;
        sort(a.begin(),a.end());
        vector<int>temp=a[0];
        for(auto it:a){
            if(it[0]<=temp[1]) temp[1]=max(temp[1],it[1]);
            else {
                ans.push_back(temp);
                temp=it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
