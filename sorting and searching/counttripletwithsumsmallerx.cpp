class Solution{


	public:
	#define ll long long
	long long countTriplets(long long a[], int n, long long sum)
	{
	   sort(a,a+n);
	   ll ans=0;
	   for(int i=0;i<n-2;i++){
	       ll f=a[i];
	       int j=i+1;
	       int k=n-1;
	       while(j<k){
	           if(f+a[j]+a[k]<sum){
	               ans+=k-j;
	               j++;
	           }else{
	               k--;
	           }
	       }
	   }
	   return ans;
	}


};
