
class Solution {
public:
    string reorganizeString(string s) {
        //always take the most freq char and append to ans
        //and remove the curr element from pq so that it is not taaken in thre next iteraion and also in the next iteration insert the pref ele if its freq still>0
        string ans="";
        int n=s.size();
        priority_queue<pair<int,char>>pq;
        map<int,int>m;
        for(char c:s) m[c]++;
        for(auto it:m) pq.push({it.second,it.first});
        pair<int,int>pref={0,'$'};
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            ans+=curr.second;
            if(pref.first>0){
                pq.push(pref);
            }
            curr.first--;
            pref=curr;
        }
        if(ans.size()!=s.size()) return "";
        return ans;
    }
};
