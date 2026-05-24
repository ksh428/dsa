
class Solution {
public:
#define ll long long
    vector<int> getOrder(vector<vector<int>>& a) {
        int n=a.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            a[i].push_back(i);
        }
        sort(begin(a),end(a));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        ll currtime=0;
        int i=0;
        while(1){
            if(ans.size()==n){
                break;
            }
            if(i<n and pq.empty()) currtime=max(currtime,(ll)a[i][0]);//update time if there are no queued job
            while(i<n and currtime>=a[i][0]){
                pq.push({a[i][1],a[i][2]});
                i++;
            }
            //pick the smallest job
            auto curr=pq.top();
            pq.pop();
            currtime+=curr.first;
            ans.push_back(curr.second);
        }
        return ans;

    }
};
