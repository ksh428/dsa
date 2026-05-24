class Solution {
public:
    int bfs(string a,string b){
        if(a==b) return 0;
        int n=a.size();
        int ans=0;
        int idx,swaps;
        string curr;
        unordered_set<string>vis;
        queue<pair<string,pair<int,int>>>q;//(string,indx till matched,lvl)
        q.push({a,{0,0}});
        vis.insert(a);
        while(!q.empty()){
            auto t=q.front();
            curr=t.first;
            idx=t.second.first;
            swaps=t.second.second;
            q.pop();
            while(b[idx]==curr[idx]) idx++;
            for(int i=idx+1;i<n;i++){
                if(curr[i]==b[idx]){
                    swap(curr[i],curr[idx]);
                    if(curr==b) return swaps+1;
                    if(vis.find(curr)==vis.end()){
                       q.push({curr,{idx+1,swaps+1}});
                        vis.insert(curr);
                    }
                    swap(curr[i],curr[idx]);
                }
            }
        }
        return ans;
    }
    int kSimilarity(string a, string b) {
        return bfs(a,b);
    }
    //k fimilar whose 2 parents must n
};
};
