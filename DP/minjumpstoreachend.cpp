
//O(N^2)
int minJumps(int a[], int n){
    // Your code here

   int dp[n];
   for(int i=0;i<n;i++) dp[i]=INT_MAX;
   dp[0]=0;
   for(int i=1;i<n;i++){
       for(int j=0;j<i;j++){
           if(j+a[j]>=i && dp[j]!=INT_MAX){
               dp[i]=min(dp[i],1+dp[j]);
           }
       }
   }
   if(dp[n-1]!=INT_MAX) return dp[n-1];
   else return -1;
}
