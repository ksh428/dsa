class Solution {
public:
    int minimumDeviation(vector<int>& a) {
        //a odd element can only be multiplied 1ce, so it can onl increase
        //a even element can only be reduced

        //so make all the elements of the array  even so that we dont need to perform the 2nd op
        //we dont need to have multiple occurences of same element so set would work
        //but couldnt figure out why multiset dosent work
        set<int>st;
        for(auto it:a){
            if(it&1) st.insert(2*it);
            else st.insert(it);
        }
        int ans=*st.rbegin()-*st.rend();
        //now continue decreasing the max element and if it becomes odd stop
        while(*st.rbegin()%2==0){
            int mx=*st.rbegin();
            st.erase(mx);
            st.insert(mx/2);
            ans=min(ans,*st.rbegin()-*st.begin());
        }
        return ans;

    }
};
