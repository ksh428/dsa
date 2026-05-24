class Solution {
public:
    //use scanline algo
    #define ll long long
    vector<vector<long long>> splitPainting(vector<vector<int>>& seg) {
       vector<vector<ll>>ans;
        ll pref[100001]={};
        int ends[100001]={};
        ll sum=0,last=0;
        for(auto i:seg){
            pref[i[0]]+=i[2];
            pref[i[1]]-=i[2];
            ends[i[0]]=ends[i[1]]=1;
        }
        for(int i=1;i<100001;i++){
            if(ends[i] and sum){
                ans.push_back({last,i,sum});
            }
            last=ends[i]?i:last;
            sum+=pref[i];
        }
        return ans;
    }
};
