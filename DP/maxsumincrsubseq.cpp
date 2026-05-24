	int maxSumIS(int a[], int n)
	{
	    // Your code goes here
	int mis[n];
	for(int i=0;i<n;i++) mis[i]=a[i];
	for(int i=1;i<n;i++){
	    for(int j=0;j<i;j++){
	        if(a[i]>a[j] && mis[i]<mis[j]+a[i]){
	            mis[i]=mis[j]+a[i];
	        }
	    }
	}
	int maxval=INT_MIN;
	for(int i=0;i<n;i++){
	    if(mis[i]>maxval) maxval=mis[i];
	}
	return maxval;

