class Solution{
    public:

    vector<vector<int> > fourSum(vector<int> &a, int k) {
        // Your code goes here
        set<vector<int>>st;
        sort(a.begin(),a.end());
        int n=a.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int f=a[i];
                int s=a[j];
                int l=j+1;
                int r=n-1;
                while(l<r){
                    if(f+s+a[l]+a[r]==k){
                        st.insert({f,s,a[l],a[r]});
                        l++;
                        r--;
                    }else if(f+s+a[l]+a[r]>k){
                        r--;
                    }else l++;
                }
            }
        }

       for(auto it:st){
           ans.push_back(it);
       }

        return ans;
    }
};
