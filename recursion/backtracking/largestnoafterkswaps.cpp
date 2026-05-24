class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(string s,int k,string& max,int i){
       int n=s.size();
       if(k==0) return;
       char maxv=s[i];
       for(int j=i+1;j<n;j++){
           if(maxv<s[j]) maxv=s[j];
       }
       if(maxv!=s[i]) k--;
       for(int j=i;j<n;j++){
           if(s[j]==maxv){
               swap(s[i],s[j]);
               if(s>max){
                   max=s;
               }
               solve(s,k,max,i+1);
               swap(s[i],s[j]);
           }
       }
    }
    string findMaximumNum(string s, int k)
    {
       // code here.
       string max=s;
       solve(s,k,max,0);
       return max;
    }
};
