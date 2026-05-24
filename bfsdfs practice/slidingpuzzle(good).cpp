class Solution {
public:
    string swap1(string &s,int i,int j){
        swap(s[i],s[j]);
        return s;
    }
    int slidingPuzzle(vector<vector<int>>& a) {
        queue<string>q;
        string t="123450";
        string s="";//initial
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                s+=to_string(a[i][j]);
            }
        }
        cout<<s;
        q.push(s);
        vector<vector<int>>swapidx{{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        set<string>st;
        int l=0;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                string curr=q.front();
                q.pop();

                if(curr==t) return l;
                int idx=-1;
                for(int i=0;i<curr.size();i++){
                    if(curr[i]=='0'){
                        idx=i;
                        break;
                    }
                }
                for(int j:swapidx[idx]){
                    string t1=curr;
                    string temp=swap1(t1,idx,j);
                    if(st.find(temp)==st.end()){
                        q.push(temp);
                         st.insert(temp);
                    }
                }
            }
            l++;
        }
        return -1;

    }
};
