//BINARY SEARCH APPROACH NOT WORKING

	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans=-1;
	    int j=m-1;
	    for(int i=0;i<n and j>=0;i++){
	        while(j>=0){
	            if(arr[i][j]==1){
	                ans=i;
	                j--;
	            }else break;
	        }
	    }
	    return ans;
	}

	//brute force:o(mn)
	//binary se:o(nlog(m));
	// best:o(m+n)
