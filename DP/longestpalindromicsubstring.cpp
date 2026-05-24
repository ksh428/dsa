class Solution {
public:
    string longestPalindrome(string s) {
         int n=s.size();
    bool p[n][n];
    memset(p,0,sizeof(p));
    int start=0,maxlen=1;
    for(int i=0;i<n;i++) p[i][i]=1;
    for(int l=2;l<=n;l++){
        for(int i=0;i+l<=n;i++){
            int j=i+l-1;
            if(l==2) {
                if(s[i]==s[j]){
                    p[i][j]=1;
                    if(l>maxlen){
                        start=i;
                        maxlen=l;
                    }

                }

            }else{
                if(s[i]==s[j] and p[i+1][j-1]){
                    p[i][j]=1;
                    if(l>maxlen){
                        start=i;
                        maxlen=l;
                    }
                }
            }
        }
    }
    return s.substr(start,maxlen);
    }
};
