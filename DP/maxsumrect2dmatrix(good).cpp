
class Solution {
  public:
  int kadane(vector<int>temp,int c){
      int meh=0,msf=INT_MIN;
      for(int i=0;i<c;i++){
          meh+=temp[i];
          if(meh>msf){
              msf=meh;
          }
          if(meh<0){
              meh=0;
          }
      }
      return msf;
  }
    int maximumSumRectangle(int r, int c, vector<vector<int>> m) {
        // code here
        int ans=INT_MIN;
        for(int i=0;i<r;i++){
            vector<int>temp(c);
            for(int j=i;j<r;j++){
                for(int col=0;col<c;col++){
                    temp[col]+=m[j][col];
                }
                ans=max(ans,kadane(temp,c));
            }
        }
        return ans;
    }
};
//TC: R*R*C
