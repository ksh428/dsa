#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    vector<int>reqSeq;
    for(int i=0;i<n/2;i++)
    {
        reqSeq.push_back(a[i]);
        reqSeq.push_back(a[n-i-1]);
    }
    if(n%2==0)
    {
        reqSeq.push_back(a[n/2]); //pusg the mid ele if the arr size is even ptherwise it is nt incl int the first loop
    }
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        ans+=abs(reqSeq[i]-reqSeq[i+1]);
    }
    cout<<ans;
}
