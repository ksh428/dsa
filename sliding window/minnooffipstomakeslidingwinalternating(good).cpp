class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        s+=s;
        string t1="";
        string t2="";
        for(int i=0;i<s.size();i++)
        {
            if(i%2==0){
                t1+='0';
                t2+='1';
            }else{
                t1+='1';
                t2+='0';
            }
        }
        int ans=s.size();
        int d1=0,d2=0;
        int l=0;
        //sliding window
        for(int r=0;r<s.size();r++){
            if(s[r]!=t1[r]) d1++;
            if(s[r]!=t2[r]) d2++;
            if(r-l+1>n){
                if(s[l]!=t1[l]) d1--;
                if(s[l]!=t2[l]) d2--;
                l++;
            }
            if(r-l+1==n){
                ans=min(ans,min(d1,d2));
            }
        }
        return ans;
    }
};
