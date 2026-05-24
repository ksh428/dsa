
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(deadends.begin(),deadends.end());
        unordered_set<string>vis;
        vis.insert("0000");
        queue<string>q;
        q.push("0000");
        int lvl=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(st.find(curr)!=st.end()) continue;//screwd
                if(curr==target) return lvl;
                string temp=curr;
                for(int i=0;i<4;i++){
                    char ch=temp[i];
                    int num=ch-'0';
                    string s1,s2;
                    int num1=(num==9?0:num+1);
                    int num2=(num==0?9:num-1);
                    s1=temp.substr(0,i)+to_string(num1)+temp.substr(i+1);
                    s2=temp.substr(0,i)+to_string(num2)+temp.substr(i+1);
                    if(vis.find(s1)==vis.end() and st.find(s1)==st.end()){
                        q.push(s1);
                        vis.insert(s1);
                    }
                    if(vis.find(s2)==vis.end() and st.find(s2)==st.end()){
                        q.push(s2);
                        vis.insert(s2);
                    }
                }
            }
          lvl++;
        }
        return -1;
    }

};
