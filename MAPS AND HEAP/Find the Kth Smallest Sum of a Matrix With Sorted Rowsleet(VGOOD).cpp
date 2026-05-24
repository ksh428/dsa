
class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int m=a.size();
        int n=a[0].size();
        set<pair<int,vector<int>>>st;//sum,current index rowise
        int s=0;
        vector<int>v;
        for(int i=0;i<m;i++){
            s+=a[i][0];
            v.push_back(0);
        }
        st.insert({s,v});
        int cs;
        while(k){
            auto it=*st.begin();
            st.erase(it);
            cs=it.first;
            int os=cs;
            vector<int>currstate=it.second;
            for(int i=0;i<m;i++){//similar to bfs
                if(currstate[i]+1<n){
                    currstate[i]++;
                    cs+=a[i][currstate[i]]-a[i][currstate[i]-1];
                    st.insert({cs,currstate});
                    currstate[i]--;
                    cs=os;
                }
            }
            k--;
        }
        return cs;

    }
};
