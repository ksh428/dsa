//normal more intuitive

class Solution {
  public:
    int findMaxLen(string s) {
        int ans=0;
      int l=0,r=0;
      for(int i=0;i<s.size();i++){
          if(s[i]=='(') l++;
          else r++;
          if(l==r){
              ans=max(ans,2*r);
          }else if(l<r) l=r=0;
      }
      l=0,r=0;
      for(int i=s.size()-1;i>=0;i--){
          if(s[i]=='(') l++;
          else r++;
          if(l==r){
              ans=max(ans,2*r);
          }else if(l>r) l=r=0;
      }
      return ans;
    }
};

//stack

