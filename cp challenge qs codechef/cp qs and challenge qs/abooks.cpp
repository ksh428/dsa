#include<iostream>
using namespace std;
int main()
{
    int t;cin>>t;
    int b[1000001]={0};
    while(t--)
    {
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[a[i]]=i;
        }
        for(int j=0;j<n;j++)
        {
            cout<<n-1-b[a[j]]<<endl;
        }
    }
}
