
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& a) {
        vector<int>ans{-100000,100000};
        int k=a.size();
        int mx=INT_MIN;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i=0;i<k;i++){
            pq.push({a[i][0],0,i});//element,index in array,array index
            mx=max(mx,a[i][0]);
        }
        while(1){
            auto it=pq.top();
            pq.pop();
            if(ans[1]-ans[0]>mx-it[0]){
                ans[0]=it[0];
                ans[1]=mx;
            }
            it[1]++;//next index
            vector<int>curr=a[it[2]];
            if(it[1]==curr.size()){
                break;
            }else{
                it[0]=curr[it[1]];
                mx=max(mx,curr[it[1]]);
                pq.push(it);
            }
        }
        return ans;

    }
};
