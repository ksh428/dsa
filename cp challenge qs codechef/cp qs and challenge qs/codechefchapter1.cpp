#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int j=0;j<n;j++)
        {
            cin>>b[j];
        }
        sort(a,a+n);
        sort(b,b+n);
        if((a[n-1]>b[n-1]) || (b[n-1]>a[n-1]))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
