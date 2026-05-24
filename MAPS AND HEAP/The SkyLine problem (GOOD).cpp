class Solution {
public:
    //more exp in copy
    //we are using set since we may need to remove somethig which is not pq.top()
    static bool comp(pair<int,int>a,pair<int,int>b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
    //we also need a way to distinguish between start and end points
    vector<vector<int>> getSkyline(vector<vector<int>>& a) {
        vector<vector<int>>ans;
        int n=a.size();
        vector<pair<int,int>>v;
        for(auto it:a){
            v.push_back({it[0],-it[2]});
            v.push_back({it[1],it[2]});
        }
        sort(v.begin(),v.end(),comp);
       // for(auto it:v) cout<<it.first<<" "<<it.second<<"   ";
        multiset<int>st;//store ongoing rectangle heights
        int currh=0;
        st.insert(currh);
        for(int i=0;i<v.size();i++){
            int x=v[i].first;
            int h=v[i].second;
            if(h<0){//starting point
                st.insert(-h);
            }else{
                st.erase(st.find(h));
            }
            if(currh!=*st.rbegin()){
                ans.push_back({x,*st.rbegin()});
                currh=*st.rbegin();
            }
        }
        return ans;
    }
};
