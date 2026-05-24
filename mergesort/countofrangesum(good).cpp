class Solution {
public:
    #define ll long long int
    ll merge(ll a[],int l,int m,int r,int lower,int upper){
        ll ans=0;
        int j=m,k=m;
        for(int i=l;i<m;i++){
            while(j<=r and a[j]-a[i]<=upper) j++;
            while(k<=r and a[k]-a[i]<lower) k++;
            ans+=(j-k);
        }
        ll temp[r-l+1];
        int i=l;
        j=m;
         k=0;
        while(i<m and j<=r){
            if(a[i]<=a[j]) temp[k++]=a[i++];
            else temp[k++]=a[j++];
        }
        while(i<m) temp[k++]=a[i++];
        while(j<=r) temp[k++]=a[j++];
        k=0;
        for(int i=l;i<=r;i++){
            a[i]=temp[k++];
        }
        return ans;
    }
    ll mergesort(ll pref[],int l,int r,int lower,int upper){
        ll ans=0;
        if(l==r){
            return pref[l]>=lower and pref[l]<=upper;
        }
        if(l<r){
            int m=(l+r)/2;
            ans+=mergesort(pref,l,m,lower,upper);
            ans+=mergesort(pref,m+1,r,lower,upper);
            ans+=merge(pref,l,m+1,r,lower,upper);
        }
        return ans;
    }
    int countRangeSum(vector<int>& a, int lower, int upper) {
        int n=a.size();
        ll pref[n];
        pref[0]=a[0];
        for(int i=1;i<n;i++) pref[i]=a[i]+pref[i-1];
        return mergesort(pref,0,n-1,lower,upper);
    }
};
