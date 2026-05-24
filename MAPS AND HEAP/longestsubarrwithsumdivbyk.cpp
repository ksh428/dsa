
class Solution{
public:
	int longSubarrWthSumDivByK(int a[], int n, int k)
	{
	    int ans=0;
	    int sum=0,rem=0;
	    unordered_map<int,int>m;//rem,idx
	    m[0]=-1;
	    for(int i=0;i<n;i++){
	        sum+=a[i];
	        rem=((sum%k)+k)%k;
	      //  if(rem<0) rem+=k;
	        if(m.find(rem)!=m.end()){
	           ans=max(ans,i-m[rem]);
	        }else{
	            m[rem]=i;
	        }
	    }
	    return ans;
	}
};
