class Solution{


	public:
	long long getCount(int n)
	{
		long long dp[n+1][10]={0}; //dp(i,j):count of possible nos when i keys are pressed
		//with last number as j
		vector<vector<int>>v;
// 		v[0].push_back({0,8});
// 		v[1].push_back({1,2,4});
// 		v[2].push_back({1,2,3,5});
// 		v[3].push_back({2,3,6});
// 		v[4].push_back({1,4,5,7});
// 		v[5].push_back({2,4,5,6,8});
// 		v[6].push_back({3,5,6,9});
// 		v[7].push_back({4,7,8});
// 		v[8].push_back({5,7,8,9,0});
// 		v[9].push_back({6,8,9});
        v.push_back({0,8});
		v.push_back({1,2,4});
		v.push_back({1,2,3,5});
		v.push_back({2,3,6});
		v.push_back({1,4,5,7});
		v.push_back({2,4,5,6,8});
		v.push_back({3,5,6,9});
		v.push_back({4,7,8});
		v.push_back({5,7,8,9,0});
		v.push_back({6,8,9});

		for(int i=1;i<=n;i++){
		    for(int j=0;j<=9;j++){
		        if(i==1) dp[i][j]=1;
		        else{//ith press of jth key =i-1 th press of v[j] keys
		            for(int prev:v[j]){
		                dp[i][j]+=dp[i-1][prev];
		            }
		        }
		    }
		}
		long long ans=0;
		for(int i=0;i<=9;i++) ans+=dp[n][i];
		return ans;

	}


};
