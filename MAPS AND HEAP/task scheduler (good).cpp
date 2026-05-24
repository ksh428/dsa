class Solution {
public:
    //char->time,char,left
    int leastInterval(vector<char>& a, int n) {
        int ans=0;
        map<char,int>m;
        for(auto it:a) m[it]++;
        priority_queue<int>pq;
        for(auto it:m) pq.push(it.second);
        while(!pq.empty()){
            vector<int>t;
            int c=0;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    int curr=pq.top();
                    pq.pop();
                    c++;
                    t.push_back(curr-1);
                }

            }
            // ans+=c;
            for(int x:t) if(x>0) pq.push(x);
            ans+=(pq.empty())?c:n+1;
        }
        return ans;
    }
};
