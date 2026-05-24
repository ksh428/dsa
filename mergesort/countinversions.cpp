
#define ll long long

ll merge(ll a[],int l,int m,int r){
    int i=l,j=m+1;
    ll c=0;
    int k=0;
    for(int i=l;i<=m;i++){
            while(j<=r and a[i]>a[j]) j++;
            c+=(j-m-1);
        }
    j=m+1;
    ll temp[r-l+1];
    while(i<=m and j<=r){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }else{
           // c+=(m-i);
            temp[k++]=a[j++];
        }
    }
    while(i<=m) temp[k++]=a[i++];
    while(j<=r) temp[k++]=a[j++];
    for(int i=l,k=0;i<=r;i++,k++) a[i]=temp[k];
    return c;
}
ll mergesort(ll a[],int l,int r){
    ll c=0;
    if(l<r){
        int m=(l+r)/2;
        c+=mergesort(a,l,m);
        c+=mergesort(a,m+1,r);
        c+=merge(a,l,m,r);
        return c;
    }
    return c;
}
long long getInversions(long long *a, int n){
    ll ans=mergesort(a,0,n-1);
    return ans;
}
