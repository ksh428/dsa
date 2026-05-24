class Solution{
	public:
	int LongestBitonicSequence(vector<int>a)
	{
	    //find lds and piis
	    //find lis and lds at evry point and find max of it
	    int n=a.size();
	    int lis[n];
	    lis[0]=1;
	    for(int i=1;i<n;i++){
	        lis[i]=1;
	        for(int j=0;j<i;j++){
	            if(a[j]<a[i] and lis[i]<1+lis[j]){
	                lis[i]=1+lis[j];
	            }
	        }
	    }
	    int lds[n];
	    lds[n-1]=1;
	    for(int i=n-2;i>=0;i--){
	        lds[i]=1;
	        for(int j=i+1;j<n;j++){
	            if(a[i]>a[j] and lds[i]<1+lds[j]){
	                lds[i]=1+lds[j];
	            }
	        }
	    }
	    int ans=0;
	    for(int i=0;i<n;i++){
	        ans=max(ans,lis[i]+lds[i]-1);
	    }
	    return ans;
	}
};
