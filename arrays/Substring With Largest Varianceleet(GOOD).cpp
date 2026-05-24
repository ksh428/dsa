//application of kadanes algo


class Solution {
public:
    int largestVariance(string s) {
        int n=s.size();
        int ans=0;
        map<char,int>m;
        for(auto it:s) m[it]++;
        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                if(ch1==ch2 or !m[ch1] or !m[ch2]) continue;
                for(int j=1;j<=2;j++){
                    int f1=0,f2=0;
                    for(auto it:s){
                        f1+=it==ch1;
                        f2+=it==ch2;
                        if(f1<f2) f1=f2=0;
                        if(f1>0 and f2>0) ans=max(ans,f1-f2);
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};
