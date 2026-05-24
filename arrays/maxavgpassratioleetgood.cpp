class Solution {
public:
    struct comp{
        bool operator()(pair<int,int> a,pair<int,int> b){
            double x=(double)(a.first+1)/(a.second+1)-(double)a.first/a.second;
            double y=(double)(b.first+1)/(b.second+1)-(double)b.first/b.second;
            return x<y;//swap
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int ex) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        for(auto i:classes){
            pq.push({i[0],i[1]});
        }
        while(ex--){
            auto curr=pq.top();
            pq.pop();
            curr.first+=1;
            curr.second+=1;
            pq.push({curr.first,curr.second});
        }
        double ans=0;
        while(!pq.empty()){
            ans+=(double)pq.top().first/(double)pq.top().second;
            pq.pop();
        }
        return ans/(double)classes.size();
    }
};
