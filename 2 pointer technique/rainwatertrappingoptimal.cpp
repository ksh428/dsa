


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[]={8,8,2,4,5,5,1};
    int n=sizeof(a)/sizeof(a[0]);
    int s=0;
    int l=0,r=n-1;
    int lmax=0,rmax=0;
    while(l<=r){
        if(a[l]<=a[r]){
            if(a[l]>=lmax) lmax=a[l];
            else s+=lmax-a[l];
            l++;
        }else{
            if(a[r]>=rmax) rmax=a[r];
            else s+=rmax-a[r];
            r--;
        }
    }
   cout<<s;
}

//other

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int a[], int n){
        int ans=0;
        int pref[n],suf[n];
        pref[0]=a[0]; //pref(i): max element from 0 to i
        for(int i=1;i<n;i++) pref[i]=max(pref[i-1],a[i]);
        suf[n-1]=a[n-1];//suf(i):max ele from i to n-1
        for(int i=n-2;i>=0;i--) suf[i]=max(suf[i+1],a[i]);
        for(int i=0;i<n;i++){
            ans+=(min(pref[i],suf[i])-a[i]);
        }
        return ans;
    }
};
