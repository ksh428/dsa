// https://practice.geeksforgeeks.org/contest/interview-series-adobe/problems/
//ASO AVAILABLE ON LEETCODE

class Solution {
  public:
    int maxEvents(int s[], int e[], int n) {

        int ans=0;
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            vp.push_back({s[i],e[i]});
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(vp.begin(),vp.end());
        int i=0;
        for(int d=1;d<=100000;d++){
            while(!pq.empty() and pq.top()<d) pq.pop();
            while(i<n and vp[i].first==d){
                pq.push(vp[i].second);
                i++;;
            }
            if(pq.size()){
                ans++;
                pq.pop();
            }
        }
        return ans;
    }
};
