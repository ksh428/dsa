class Solution{

	public:
	#define ll long long
	long long subCount(long long a[], int n, long long k)
	{
	    ll ans=0;
	    unordered_map<int,int>m;//rem,count
	    int s=0;
	    m[0]=1;
	    for(int i=0;i<n;i++){
	        s+=a[i];
	      //  if((s%k+k)%k==0) ans++;
	        if(m.find((s%k+k)%k)!=m.end()) ans+=m[(s%k+k)%k];
	        m[(s%k+k)%k]++;
	    }
	    return ans;
	}



};

