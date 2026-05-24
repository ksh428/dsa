class Solution{
  public:
    int minJumps(int a[], int n){
        if(n==1) return 0;
        if(a[0]==0) return -1;
        int maxr=a[0];
        int ans=1;
        int skip=a[0];
        for(int i=1;i<n;i++){
            if(i==n-1) return ans;
            maxr=max(maxr,i+a[i]);
            skip--;
            if(skip==0){
                ans++;
                if(i>=maxr) return -1;
                skip=maxr-i;
            }
        }
    }
};

//check copy for exp

