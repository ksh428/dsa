class Solution {
public:
    //we will be using contribution technique
    //each element has a sp contribution to the final ans
    int uniqueLetterString(string s) {
        int n=s.size();
        vector<int>hashleft(26,-1);
        vector<int>hashright(26,n);
        vector<int>left(n,-1);
        vector<int>right(n,-1);
        //claim: contribution[i]:left[i]*right[i];
        //left
        for(int i=0;i<n;i++){
            left[i]=i-hashleft[s[i]-'A'];
            hashleft[s[i]-'A']=i;
        }
        //right
        for(int i=n-1;i>=0;i--){
            right[i]=hashright[s[i]-'A']-i;
            hashright[s[i]-'A']=i;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=left[i]*right[i];
        }
        return ans;

    }
};
