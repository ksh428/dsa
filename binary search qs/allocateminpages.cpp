class Solution
{
    public:
    //Function to find minimum number of pages.
    int sum(int a[],int n){
        int s=0;
        for(int i=0;i<n;i++) s+=a[i];
        return s;
    }
    int findmin(int a[],int n){
        int ans=INT_MAX;
        for(int i=0;i<n;i++) ans=min(ans,a[i]);
        return ans;
    }
    bool valid(int x,int a[],int n,int m){
        //return true if n books can be distributed among m students such that
        //each student gets not more than x books
        int no=1;
        int c=0;
        for(int i=0;i<n;i++){
            if(c+a[i]<=x){
                c+=a[i];
            }else{
                no++;
                c=a[i];
                if(c>x) return 0;
            }
        }
        return no<=m;



    }
    int findPages(int a[], int n, int k)
    {
        int l=findmin(a,n);
        int r=sum(a,n);
        int ans=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(valid(m,a,n,k)){
                ans=m;
                r=m-1;
            }else l=m+1;
        }
        return ans;
    }
};

