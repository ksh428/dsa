
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int x) {
        int n=a.size();
        vector<int>v;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(m.find(x-a[i])!=m.end()){
                v.push_back(m[x-a[i]]);
                v.push_back(i);
                break;
            }
            m[a[i]]=i;
        }
        return v;
    }
};
