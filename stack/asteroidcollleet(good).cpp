
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size();
        stack<int>st;
        //5 4 -1 3 -2
        //-1 2 3
        for(int i:a){
            if(i>0) st.push(i);//guaranteed no colision
            else{
                while(!st.empty() and st.top()>0 and -i>st.top()) st.pop();//remove all collisions in which i is bigger
                if(!st.empty() and st.top()==-i) st.pop();//stop and destory i
                else if(!st.empty() and st.top()>-i) {}//collision but destroy i no push it
                else st.push(i);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
