//BFS WITH PRIORITY QUEUE
class Solution {
public:
//UNDERSTAND THAT WE NEED TO USE A PQ INSTEAD OF A QUEUE AND OFFLINE QUERIES
    vector<int> maxPoints(vector<vector<int>>& a, vector<int>& q) {
        int m=a.size();
        int n=a[0].size();
        int k=q.size();
        vector<int>ans(k);
        vector<pair<int,int>>vp;
        for(int i=0;i<k;i++){
            vp.push_back({q[i],i});
        }
        sort(vp.begin(),vp.end());
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>vis(m,vector<int>(n,0));
        vis[0][0]=1;
        int pref=0;
        pq.push({a[0][0],0,0});
        for(int i=0;i<k;i++){
            int qv=vp[i].first;
            int qi=vp[i].second;
            while(!pq.empty() and pq.top()[0]<qv){
                auto curr=pq.top();
                int cx=curr[1];
                int cy=curr[2];
                pref++;
                pq.pop();
                if(cx+1<m and vis[cx+1][cy]==0){
                    pq.push({a[cx+1][cy],cx+1,cy});
                    vis[cx+1][cy]=1;
                }
                if(cx-1>=0 and vis[cx-1][cy]==0){
                    pq.push({a[cx-1][cy],cx-1,cy});
                    vis[cx-1][cy]=1;
                }
                if(cy+1<n and vis[cx][cy+1]==0){
                    pq.push({a[cx][cy+1],cx,cy+1});
                    vis[cx][cy+1]=1;
                }
                if(cy-1>=0 and vis[cx][cy-1]==0){
                    pq.push({a[cx][cy-1],cx,cy-1});
                    vis[cx][cy-1]=1;
                }
            }
            ans[qi]=pref;
        }
        return ans;
    }
};
