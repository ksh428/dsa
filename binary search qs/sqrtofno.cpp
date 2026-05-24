//find sqrt of no.
#include<bits/stdc++.h>
using namespace std;

int findsqrt(int n)
{
    if(n==0 || n==1) return n;
    int l=1,r=n,ans;
    while(l<=r){
        int m=l+(r-l)/2;
        if(m*m==n) return m;
        if(m*m<n){
            l=m+1;
        ans=m;
        }else{
            r=m-1;
        }
    }
    return ans;

}
int main()
{
    int n;
    cin>>n;
    cout<<findsqrt(n);
}
