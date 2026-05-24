class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&a){
		    // Code here
		    int n=a.size();
		    int lasb=1;//las with last ele>prev
		    int lass=1;//las with last ele <prev
		    for(int i=1;i<n;i++){
		        if(a[i]>a[i-1]){
		            lasb=lass+1;//think similar to the dp soln
		        }
		        if(a[i]<a[i-1]) lass=lasb+1;//dp[i][0]=max(dp[i)[0],1+dp[j][1];
		        //notice 0 and 1 from dp are flipped
		        //so accordingly lass and lasb are also flipped
		        //
		    }
		    return max(lass,lasb);
		}

};
//o(N)


//TLE:

     int n=nums.size();
		    int dp[n][2];
		    for(int i=0;i<n;i++){
		        dp[i][0]=dp[i][1]=1;
		    }
		    int ans=1;
		    for(int i=1;i<n;i++){
		        for(int j=0;j<i;j++){
		            if(nums[i]>nums[j]){
		            dp[i][0]=max(dp[i][0],1+dp[j][1]);
		            }
		            if(nums[i]<nums[j]){
		                dp[i][1]=max(dp[i][1],1+dp[j][0]);
		            }
		        }
		        ans=max(ans,max(dp[i][0],dp[i][1]));

		    }
		    return ans;
