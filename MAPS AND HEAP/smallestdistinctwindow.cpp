class Solution{
    public:
    int findSubString(string s)
    {
        int n=s.size();
        map<char,int>m;
        for(char c:s) m[c]++;
        int k=m.size();
        map<char,int>m1;
        int ans=1e6;
        int j=0;
        for(int i=0;i<n;i++){
            m1[s[i]]++;
            while(m1.size()==m.size()){
                ans=min(ans,i-j+1);
                if(m1[s[j]]==1){
                    m1.erase(s[j]);
                } else m1[s[j]]--;
                j++;
            }
        }
        return ans;

    }
};
