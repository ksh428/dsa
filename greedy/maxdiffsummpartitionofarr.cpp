#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int k;
    cin>>n>>k;
    int a[n];
    int sumt=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sumt+=a[i];
    }
    // array consists of non neg elements
    sort(a,a+n);
    reverse(a,a+n);
    int s1=0;

    int M=max(k,n-k);
    for(int i=0;i<M;i++)
    {
        s1+=a[i] ;
    }
    cout<<s1-(sumt-s1);
}
