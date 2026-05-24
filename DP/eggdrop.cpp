//RECURSIVE
class Solution {
public:
    int find(int k,int n){
        //k:eggs n: floor
        if(k==1) return n;
        if(n<=1) return n;
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
                //breaks or not is luck so always take worst case of luck
            int breaks=find(k-1,i-1);
            int stays=find(k,n-i);
            ans=min(ans,1+max(breaks,stays));
        }
        return ans;
    }
    int superEggDrop(int k, int n) {
        return find(k,n);

    }
};
//MEMO + BS

class Solution {
public:
    int find(int k,int n,vector<vector<int>>&dp){
        if(n==1 || n==0) return n;
        if(k==1) return n;
        if(dp[k][n]!=-1) return dp[k][n];
        //apllying bs on floor
        int l=1,h=n;
        int ans=INT_MAX;
        int temp=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            int breaks=find(k-1,mid-1,dp); //left
            int stays=find(k,n-mid,dp);//right
            temp=1+max(stays,breaks);
            if(breaks<stays) l=mid+1 ;
            else h=mid-1;
            ans=min(ans,temp);
        }
        return dp[k][n]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return find(k,n,dp);

    }
};
//normal bottom up dp

class Solution
{
    public:

    int eggDrop(int n, int k)
    {
       //dp[i][j]:min no of moves to finc cf for i eggs and j floors
       int dp[n+1][k+1];
       for(int i=0;i<=n;i++){
           for(int j=0;j<=k;j++){
               if(i==0){
                   dp[i][j]=0;
               }else if(j==0 or j==1){
                   dp[i][j]=j;
               }else if(i==1){
                   dp[i][j]=j;
               }else{
                   int ans=INT_MAX;
                   for(int p=1;p<=j;p++){
                       int breaks=dp[i-1][p-1];
                       int stays=dp[i][j-p];
                       ans=min(ans,1+max(stays,breaks));
                   }
                   dp[i][j]=ans;
               }
           }
       }
       return dp[n][k];
    }
};



//bottom up + bs

class Solution {
public:
    int superEggDrop(int K, int N) {
        if(N==0||N==1) return N;     //Think for base case
        if(K==1) return N;

        vector<vector<int>> dp(K+1,vector<int> (N+1,0));
      for(int i=0;i<=K;i++)
        dp[i][0]=0,dp[i][1]=1;
      for(int i=0;i<=N;i++)
        dp[0][i]=0,dp[1][i]=i;

        for(int i=2;i<K+1;i++)
        {
            //drop the egg from the ith floor and find the floor in which it breaks using bs
            for(int j=2;j<N+1;j++)
            {    int l=1,h=j,temp=0,ans=100000;
                 while(l<=h)
                 {
                    int mid=(l+h)/2;
                    int left= dp[i-1][mid-1];
                    int right= dp[i][j-mid];
                    temp=1+max(left,right);
                    if(left<right){
                      l=mid+1;
                    }
                    else
                    {
                        h=mid-1;
                    }
                    ans=min(ans,temp);
                 }
                 dp[i][j]=ans;
            }
        }
        return dp[K][N];

    }
};
