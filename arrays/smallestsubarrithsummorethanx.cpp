class Solution{
  public:

    int sb(int a[], int n, int x)
    {
       int ans=INT_MAX;
        int s=0,i=0,j=0;
        while(1){
            //acquire
            bool f1=0,f2=0;
            while(s<=x and j<n){
                s+=a[j];
                j++;
                f1=1;
            }
            //store and release
            while(i<j and s>x){
                ans=min(ans,j-i);
                s-=a[i];
                i++;
                f2=1;
            }
            if(f1 ==0 and f2==0) break;
        }
        return ans;
    }
};
